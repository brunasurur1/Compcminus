%code requires {
  #include "ast.h"
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include "ast.h"

/* Declaração de yylineno, definida pelo Flex (%option yylineno) */
extern int yylineno;

/* Funções externas do Flex */
int yylex(void);
void yyerror(const char *s);

/* Variável para controlar o escopo atual (inicialmente "global") */
static char escopoAtual[64] = "global";
%}

%union {
    int num;         /* Para NUM */
    char *id;        /* Para IDs ou strings (ex: operadores) */
    int tipoToken;   /* Para tipos (INT/VOID) */
    ASTNode *ast;    /* Para nós da AST */
}

/* Declaração de tokens */
%token <num> NUM
%token <id>  ID
%token <tipoToken> INT VOID
%token IF ELSE WHILE RETURN
%token LE GE EQ NE

/* Não-terminais que produzem nós da AST */
%type <ast> program declaration_list declaration var_declaration fun_declaration fun_signature params param_list param compound_decl local_declarations statement_list statement expression_decl expression var activation simple_expression additive_expression term factor args arg_list selection_decl iteration_decl return_decl

/* O não-terminal type_specifier usa o campo tipoToken */
%type <tipoToken> type_specifier

/* Para os operadores relacionais, usamos o campo <id> */
%type <id> relop

/* Regras de precedência */
%left '+' '-'
%left '*' '/'
%right '='

%%

program:
    declaration_list
    {
      $$ = newASTNode(NODE_PROGRAM, "program", 0);
      addChild($$, $1);
      imprimeTabela();
      printf("\nArvore Sintatica:\n");
      printAST($$, 0, 1);
      printf("\nCompilacao encerrada com sucesso.\n");
    }
;

declaration_list:
    declaration_list declaration
    {
       $$ = newASTNode(NODE_DECLARATION_LIST, "declList", 0);
       addChild($$, $1);
       addChild($$, $2);
    }
    | declaration
    {
       $$ = newASTNode(NODE_DECLARATION_LIST, "declList", 0);
       addChild($$, $1);
    }
;

declaration:
    var_declaration { $$ = $1; }
    | fun_declaration { $$ = $1; }
;

var_declaration:
    type_specifier ID ';'
    {
       if ($1 == TIPO_VOID) {
           fprintf(stderr, "ERRO SEMANTICO: Variavel \"%s\" nao pode ter tipo void. Linha: %d\n", $2, yylineno);
           $$ = newASTNode(NODE_VAR_DECL, "var_decl", 0);
       } else {
           insereSimbolo($2, $1, escopoAtual);
           $$ = newASTNode(NODE_VAR_DECL, $2, 0);
       }
       free($2);
    }
    | type_specifier ID '[' NUM ']' ';'
    {
       if ($1 == TIPO_VOID) {
           fprintf(stderr, "ERRO SEMANTICO: Array \"%s\" nao pode ter tipo void. Linha: %d\n", $2, yylineno);
           $$ = newASTNode(NODE_VAR_DECL, "array_decl", 0);
       } else {
           insereSimbolo($2, $1, escopoAtual);
           $$ = newASTNode(NODE_VAR_DECL, $2, 0);
           addChild($$, newASTNode(NODE_NUM, NULL, $4));
       }
       free($2);
    }
;

/* A assinatura da função é processada separadamente */
fun_signature:
    type_specifier ID '(' params ')'
    {
         insereSimbolo($2, $1, "global");
         strcpy(escopoAtual, $2);
         $$ = newASTNode(NODE_FUN_DECL, $2, 0);
         {
             char buffer[16];
             sprintf(buffer, "%s", ($1==TIPO_INT ? "int" : "void"));
             addChild($$, newASTNode(NODE_TYPE_SPECIFIER, buffer, 0));
         }
         addChild($$, newASTNode(NODE_ID, $2, 0));
         addChild($$, $4); /* AST dos parâmetros */
         free($2);
    }
;

/* A declaração da função consiste da assinatura seguida do corpo */
fun_declaration:
    fun_signature compound_decl
    {
         $$ = newASTNode(NODE_FUN_DECL, "fun_decl", 0);
         addChild($$, $1);  /* assinatura */
         addChild($$, $2);  /* corpo */
         strcpy(escopoAtual, "global");
    }
;

params:
    param_list { $$ = $1; }
    | VOID { $$ = newASTNode(NODE_PARAMS, "void", 0); }
;

param_list:
    param_list ',' param
    {
       $$ = newASTNode(NODE_PARAM_LIST, "param_list", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | param
    {
       $$ = newASTNode(NODE_PARAM_LIST, "param_list", 0);
       addChild($$, $1);
    }
;

param:
    type_specifier ID
    {
      if ($1 == TIPO_VOID) {
          fprintf(stderr, "ERRO SEMANTICO: Parametro \"%s\" nao pode ter tipo void. Linha: %d\n", $2, yylineno);
          $$ = newASTNode(NODE_PARAM, "param", 0);
      } else {
          insereSimbolo($2, $1, escopoAtual);
          $$ = newASTNode(NODE_PARAM, $2, 0);
      }
      free($2);
    }
    | type_specifier ID '[' ']'
    {
      if ($1 == TIPO_VOID) {
          fprintf(stderr, "ERRO SEMANTICO: Parametro array \"%s\" nao pode ter tipo void. Linha: %d\n", $2, yylineno);
          $$ = newASTNode(NODE_PARAM, "param_array", 0);
      } else {
          insereSimbolo($2, $1, escopoAtual);
          $$ = newASTNode(NODE_PARAM, $2, 0);
      }
      free($2);
    }
;

compound_decl:
    '{' local_declarations statement_list '}'
    {
       $$ = newASTNode(NODE_COMPOUND_DECL, "compound", 0);
       addChild($$, $2);
       addChild($$, $3);
    }
;

local_declarations:
    local_declarations var_declaration
    {
       $$ = newASTNode(NODE_LOCAL_DECLS, "local_decls", 0);
       addChild($$, $1);
       addChild($$, $2);
    }
    | /* vazio */
    {
       $$ = newASTNode(NODE_LOCAL_DECLS, "local_decls", 0);
    }
;

statement_list:
    statement_list statement
    {
       $$ = newASTNode(NODE_STATEMENT_LIST, "stmt_list", 0);
       addChild($$, $1);
       addChild($$, $2);
    }
    | /* vazio */
    {
       $$ = newASTNode(NODE_STATEMENT_LIST, "stmt_list", 0);
    }
;

statement:
    expression_decl { $$ = $1; }
    | compound_decl { $$ = $1; }
    | selection_decl { $$ = $1; }
    | iteration_decl { $$ = $1; }
    | return_decl { $$ = $1; }
;

selection_decl:
    IF '(' expression ')' statement
    {
       $$ = newASTNode(NODE_OP, "if", 0);
       addChild($$, $3);
       addChild($$, $5);
    }
    | IF '(' expression ')' statement ELSE statement
    {
       $$ = newASTNode(NODE_OP, "if-else", 0);
       addChild($$, $3);
       addChild($$, $5);
       addChild($$, $7);
    }
;

iteration_decl:
    WHILE '(' expression ')' statement
    {
       $$ = newASTNode(NODE_OP, "while", 0);
       addChild($$, $3);
       addChild($$, $5);
    }
;

return_decl:
    RETURN ';'
    {
       $$ = newASTNode(NODE_OP, "return", 0);
    }
    | RETURN expression ';'
    {
       $$ = newASTNode(NODE_OP, "return", 0);
       addChild($$, $2);
    }
;

expression_decl:
    expression ';'
    { $$ = newASTNode(NODE_EXPRESSION_DECL, "expr_decl", 0); addChild($$, $1); }
    | ';'
    { $$ = newASTNode(NODE_EXPRESSION_DECL, "empty_expr", 0); }
;

expression:
    var '=' expression
    {
       $$ = newASTNode(NODE_OP, "=", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | simple_expression { $$ = $1; }
;

var:
    ID
    {
      Simbolo *s = buscaSimbolo($1, escopoAtual);
      if (!s) {
          s = buscaSimbolo($1, "global");
      }
      if (!s) {
          fprintf(stderr, "ERRO SEMANTICO: Variavel \"%s\" nao declarada. Linha: %d\n", $1, yylineno);
      }
      $$ = newASTNode(NODE_ID, $1, 0);
      free($1);
    }
    | ID '[' expression ']'
    {
      Simbolo *s = buscaSimbolo($1, escopoAtual);
      if (!s) {
          s = buscaSimbolo($1, "global");
      }
      if (!s) {
          fprintf(stderr, "ERRO SEMANTICO: Array \"%s\" nao declarado. Linha: %d\n", $1, yylineno);
      }
      $$ = newASTNode(NODE_OP, "array", 0);
      addChild($$, newASTNode(NODE_ID, $1, 0));
      addChild($$, $3);
      free($1);
    }
;

activation:
    ID '(' args ')'
    {
         Simbolo *s = buscaSimbolo($1, "global");
         if (!s) {
             fprintf(stderr, "ERRO SEMANTICO: Funcao \"%s\" nao declarada. Linha: %d\n", $1, yylineno);
         }
         $$ = newASTNode(NODE_ACTIVATION, $1, 0);
         addChild($$, $3);
         free($1);
    }
;

args:
    arg_list { $$ = $1; }
    | /* vazio */ { $$ = newASTNode(NODE_ARGS, "args", 0); }
;

arg_list:
    arg_list ',' expression
    {
       $$ = newASTNode(NODE_ARG_LIST, "arg_list", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | expression
    { $$ = newASTNode(NODE_ARG_LIST, "arg_list", 0); addChild($$, $1); }
;

simple_expression:
    additive_expression { $$ = $1; }
    | additive_expression relop additive_expression
    {
       $$ = newASTNode(NODE_OP, $2, 0);
       addChild($$, $1);
       addChild($$, $3);
    }
;

relop:
    EQ { $$ = strdup("=="); }
    | NE { $$ = strdup("!="); }
    | LE { $$ = strdup("<="); }
    | '<' { $$ = strdup("<"); }
    | GE { $$ = strdup(">="); }
    | '>' { $$ = strdup(">"); }
;

additive_expression:
    additive_expression '+' term
    {
       $$ = newASTNode(NODE_OP, "+", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | additive_expression '-' term
    {
       $$ = newASTNode(NODE_OP, "-", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | term { $$ = $1; }
;

term:
    term '*' factor
    {
       $$ = newASTNode(NODE_OP, "*", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | term '/' factor
    {
       $$ = newASTNode(NODE_OP, "/", 0);
       addChild($$, $1);
       addChild($$, $3);
    }
    | factor { $$ = $1; }
;

factor:
    '(' expression ')' { $$ = $2; }
    | activation { $$ = $1; }
    | var { $$ = $1; }
    | NUM { $$ = newASTNode(NODE_NUM, NULL, $1); }
;

type_specifier:
    INT { $$ = TIPO_INT; }
    | VOID { $$ = TIPO_VOID; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTATICO: %s na linha %d\n", s, yylineno);
}

int main(void) {
    insereSimbolo("input", TIPO_INT, "global");
    insereSimbolo("output", TIPO_VOID, "global");
    strcpy(escopoAtual, "global");
    if (!yyparse())
        return 0;
    else
        return 1;
}

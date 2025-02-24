%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cminus.tab.h"
void yyerror(const char *s);
%}

%option yylineno

DIGITO      [0-9]
LETRA       [a-zA-Z]
ID          {LETRA}({LETRA}|{DIGITO})*

%%

"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"int"               { return INT; }
"void"              { return VOID; }
"return"            { return RETURN; }
"("                 { return '('; }
")"                 { return ')'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
";"                 { return ';'; }
","                 { return ','; }
"["                 { return '['; }
"]"                 { return ']'; }
"=="                { return EQ; }
"!="                { return NE; }
"<="                { return LE; }
">="                { return GE; }
"<"                 { return '<'; }
">"                 { return '>'; }
"="                 { return '='; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }
{DIGITO}+           { yylval.num = atoi(yytext); return NUM; }
{ID}                { yylval.id = strdup(yytext); return ID; }
[ \t\r\n]+          { }
"/*"[^*]*"*/"       { }
.                   { fprintf(stderr, "ERRO LEXICO: \"%s\" na linha %d\n", yytext, yylineno); 
		    exit(1);
}

%%

int yywrap(void) { return 1; }

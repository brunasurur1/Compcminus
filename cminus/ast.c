#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode *newASTNode(ASTNodeType type, const char *value, int num) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->num = num;
    node->nchildren = 0;
    node->capacity = 4;
    node->children = (ASTNode **)malloc(sizeof(ASTNode *) * node->capacity);
    if (value)
        node->value = strdup(value);
    else
        node->value = NULL;
    return node;
}

void addChild(ASTNode *parent, ASTNode *child) {
    if (!child) return;
    if (parent->nchildren >= parent->capacity) {
        parent->capacity *= 2;
        parent->children = realloc(parent->children, sizeof(ASTNode *) * parent->capacity);
    }
    parent->children[parent->nchildren++] = child;
}

void printAST(ASTNode *node, int indent, int isLast) {
    if (!node) return;

    // Evita imprimir nós sem filhos que não carregam informações relevantes
    if (node->nchildren == 0 &&
        (node->type == NODE_DECLARATION_LIST ||
         node->type == NODE_STATEMENT_LIST ||
         node->type == NODE_LOCAL_DECLS ||
         node->type == NODE_COMPOUND_DECL)) {
        return;
    }

    // Indentação para estruturar a árvore
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }

    if (indent > 0) {
        printf("|-- ");
    }

    // Mapeamento correto dos nós
    switch (node->type) {
        case NODE_PROGRAM:
            printf("program\n");
            break;
        case NODE_DECLARATION_LIST:
            printf("decl_list\n");
            break;
        case NODE_FUN_DECL:
            if (node->value)
                printf("fun_decl (%s)\n", node->value);
            else
                printf("fun_decl\n");
            break;
        case NODE_VAR_DECL:
            printf("var_decl (int %s)\n", node->value);
            break;
        case NODE_TYPE_SPECIFIER:
            printf("%s\n", node->value);
            break;
        case NODE_PARAMS:
            printf("params\n");
            break;
        case NODE_PARAM_LIST:
            printf("param_list\n");
            break;
        case NODE_PARAM:
            printf("param: %s\n", node->value);
            break;
        case NODE_COMPOUND_DECL:
            printf("compound_stmt\n");
            break;
        case NODE_LOCAL_DECLS:
            printf("local_decls\n");
            break;
        case NODE_STATEMENT_LIST:
            printf("stmt_list\n");
            break;
        case NODE_EXPRESSION_DECL:
            printf("expr_decl\n");
            break;
        case NODE_EXPRESSION:
            printf("expression\n");
            break;
        case NODE_VAR:
            printf("var: %s\n", node->value);
            break;
        case NODE_ACTIVATION:
            printf("chamada %s\n", node->value);
            break;
        case NODE_ARGS:
            printf("args\n");
            break;
        case NODE_ARG_LIST:
            printf("arg_list\n");
            break;
        case NODE_SIMPLE_EXPR:
            printf("op: %s\n", node->value);
            break;
        case NODE_OP:
            printf("op: %s\n", node->value);
            break;
        case NODE_NUM:
            printf("num: %d\n", node->num);
            break;
        case NODE_ID:
            printf("%s\n", node->value);
            break;
        default:
            printf("nó desconhecido (tipo: %d)\n", node->type);
            break;
    }

    // Percorre os filhos corretamente
    for (int i = 0; i < node->nchildren; i++) {
        printAST(node->children[i], indent + 1, i == node->nchildren - 1);
    }
}

void freeAST(ASTNode *node) {
    if (!node) return;
    for (int i = 0; i < node->nchildren; i++) {
        freeAST(node->children[i]);
    }
    if (node->value) free(node->value);
    free(node->children);
    free(node);
}

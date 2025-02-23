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

void printAST(ASTNode *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");
    printf("Node Type: %d", node->type);
    if (node->value) printf(", Value: %s", node->value);
    if (node->type == NODE_NUM) printf(", Num: %d", node->num);
    printf("\n");
    for (int i = 0; i < node->nchildren; i++) {
        printAST(node->children[i], indent + 1);
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

#ifndef CODINTERMED_H
#define CODINTERMED_H

#include "ast.h"  // para usar ASTNode*

// Define o formato de uma quádrupla
typedef struct {
    char op[8];
    char arg1[32];
    char arg2[32];
    char result[32];
} Quadrupla;

// Declara as variáveis globais usadas no codegen
extern Quadrupla quads[1000];
extern int quadIndex;

// Declaração das funções disponíveis
void emit(const char* op, const char* arg1, const char* arg2, const char* result);
char* newTemp();
char* geraCodigo(ASTNode* node);
void printCodigoIntermediario();

#endif

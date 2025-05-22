#include <stdio.h>
#include <stdlib.h>
#include "symboltable.h"
#include "codintermed.h"

// Definir a variável global lineno
int lineno = 1;

extern FILE *yyin;
ASTNode* parsear(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <arquivo.c->\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }

    yyin = f;

    ASTNode* raiz = parsear();

    if (raiz) {
        geraCodigo(raiz);              
        printCodigoIntermediario();    
    } else {
        printf("Erro na análise sintática.\n");
    }


    fclose(f);
    return 0;	
}

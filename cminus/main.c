#include <stdio.h>
#include <stdlib.h>
#include "symboltable.h"

// Definir a variável global lineno
int lineno = 1;

extern FILE *yyin;
extern int yyparse();

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

    // Inicializa a tabela de símbolos
    initSymbolTable();

    // Chama o parser (que invoca o scanner)
    yyparse();

    fclose(f);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

static Simbolo *listaSimbolos = NULL;

void insereSimbolo(char *nome, TipoSimbolo tipo, const char *escopo) {
    Simbolo *novo = (Simbolo *)malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = tipo;
    novo->escopo = strdup(escopo);
    novo->prox = listaSimbolos;
    listaSimbolos = novo;
}

Simbolo* buscaSimbolo(char *nome, const char *escopo) {
    Simbolo *atual = listaSimbolos;
    while (atual) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void imprimeTabela(void) {
    printf("\n=== Tabela de Símbolos ===\n");
    printf("%-10s %-10s %-10s\n", "Nome", "Tipo", "Escopo");
    printf("--------------------------------\n");
    Simbolo *atual = listaSimbolos;
    while (atual) {
        const char *tipoStr = (atual->tipo == TIPO_INT) ? "int" : "void";
        printf("%-10s %-10s %-10s\n", atual->nome, tipoStr, atual->escopo);
        atual = atual->prox;
    }
    printf("==========================\n");
}

void limpaTabela(void) {
    Simbolo *atual = listaSimbolos;
    while (atual) {
        Simbolo *temp = atual;
        atual = atual->prox;
        free(temp->nome);
        free(temp->escopo);
        free(temp);
    }
    listaSimbolos = NULL;
}

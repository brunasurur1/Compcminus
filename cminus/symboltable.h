 #ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

typedef enum { TIPO_INT, TIPO_VOID } TipoSimbolo;

typedef struct simbolo {
    char *nome;
    TipoSimbolo tipo;
    char *escopo;
    struct simbolo *prox;
} Simbolo;

void insereSimbolo(char *nome, TipoSimbolo tipo, const char *escopo);
Simbolo* buscaSimbolo(char *nome, const char *escopo);
void imprimeTabela(void);
void limpaTabela(void);
void initSymbolTable(void);

#endif   

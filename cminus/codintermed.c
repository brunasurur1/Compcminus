#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "codintermed.h"
#include <ctype.h>


Quadrupla quads[1000];
int quadIndex = 0;
int tempCount = 0;


void emit(const char* op, const char* result, const char* arg1, const char* arg2) {
    if (!op || !result || !arg1 || !arg2) {
        printf("ERRO EM emit: um dos argumentos é NULL\n");
        printf("op: %s, result: %s, arg1: %s, arg2: %s\n",
               op ? op : "NULL",
               result ? result : "NULL",
               arg1 ? arg1 : "NULL",
               arg2 ? arg2 : "NULL");
        exit(1);
    }

    strcpy(quads[quadIndex].op, op);
    strcpy(quads[quadIndex].result, result);
    strcpy(quads[quadIndex].arg1, arg1);
    strcpy(quads[quadIndex].arg2, arg2);
    quadIndex++;
}

char* newTemp() {
    char* nome = malloc(10);         
    sprintf(nome, "t%d", tempCount);  
    tempCount++;                      
    return nome;
}

int precisaLoad(const char* nome) {
    if (nome == NULL || strcmp(nome, "-") == 0) return 0;
    return !(nome[0] == 't' || isdigit(nome[0]));
}

const char* traduzOperador(const char* op) {
    if (strcmp(op, "+") == 0) return "ADD";
    if (strcmp(op, "-") == 0) return "SUB";
    if (strcmp(op, "*") == 0) return "MUL";
    if (strcmp(op, "/") == 0) return "DIV";
    if (strcmp(op, "==") == 0) return "EQ";
    if (strcmp(op, "!=") == 0) return "NE";
    if (strcmp(op, "<") == 0) return "LT";
    if (strcmp(op, "<=") == 0) return "LE";
    if (strcmp(op, ">") == 0) return "GT";
    if (strcmp(op, ">=") == 0) return "GE";
    return op;  
}


void processaArgs(ASTNode* node, int* numArgs) {
    if (node == NULL) return;

    if (node->type == NODE_ARG_LIST) {
        for (int i = 0; i < node->nchildren; i++) {
            processaArgs(node->children[i], numArgs);
        }
    } else {
        char* arg = geraCodigo(node);
        if (arg == NULL) {
            printf("ERRO: argumento retornou NULL\n");
	    printf("Tipo do nó que falhou: %d\n", node->type);
printf("Nome textual (node->value): %s\n", node->value ? node->value : "NULL");
printf("Número de filhos: %d\n\n", node->nchildren);
	    if (node->value != NULL){
		printf("Valor: %s\n", node->value);
	    }
            exit(1);
        }

        char* carg = arg;
        if (precisaLoad(arg)) {
            carg = newTemp();
            emit("LOAD", carg, arg, "-");
        }

        emit("PARAM", carg, "-", "-");
        (*numArgs)++;
    }
}

void processaParams(ASTNode* node, const char* nomeFunc) {
    if (node == NULL) return;

    if (node->type == NODE_PARAM_LIST) {
        for (int i = 0; i < node->nchildren; i++) {
            processaParams(node->children[i], nomeFunc);
        }
    } else if (node->type == NODE_PARAM) {
        char* nomeParam = node->value;
        emit("ARG", "int", nomeParam, nomeFunc);
    }
}


char* geraCodigo(ASTNode* node) {
    switch (node->type) {

	case NODE_PROGRAM:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_DECLARATION_LIST:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_VAR_DECL:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_FUN_DECL: {
	    ASTNode* assinatura = node->children[0];     
	    ASTNode* corpo = node->children[1];          

    	    char* nomeFunc = assinatura->children[1]->value;  
    	    char* tipoRetorno = assinatura->children[0]->value; 

	    emit("FUN", tipoRetorno, nomeFunc, "-");

ASTNode* listaParams = assinatura->children[2];
processaParams(listaParams, nomeFunc);

	    ASTNode* blocoDecls = corpo->children[0]; // NODE_LOCAL_DECLS
	    for (int i = 0; i < blocoDecls->nchildren; i++) {
	    	ASTNode* decl = blocoDecls->children[i]; // NODE_VAR_DECL
	        char* nomeVar = decl->value;
	        emit("ALLOC", nomeVar, nomeFunc, "-");
	    }

	    geraCodigo(corpo);

	    if (strcmp(nomeFunc, "main") == 0) {
	        emit("HALT", "-", "-", "-");
	    }

	    emit("END", nomeFunc, "-", "-");
	    return NULL;
	    }
            break;

	case NODE_TYPE_SPECIFIER:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_PARAMS:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_PARAM_LIST:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_PARAM:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_COMPOUND_DECL:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_LOCAL_DECLS:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_STATEMENT_LIST:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

	case NODE_EXPRESSION_DECL:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;

case NODE_ARGS:
    if (node->nchildren == 1) {
        return geraCodigo(node->children[0]);
    } else if (node->nchildren > 1) {
        for (int i = 0; i < node->nchildren; i++) {
            geraCodigo(node->children[i]);
        }
        return NULL;
    } else {
        return strdup("-");  // <- AQUI RESOLVEMOS!
    }
	
	case NODE_ARG_LIST:
	    for (int i = 0; i < node->nchildren; i++) {
	        geraCodigo(node->children[i]);
	    }
	    break;

	case NODE_NUM: {
	    char* valor = malloc(16);
	    sprintf(valor, "%d", node->num);
	    return valor;
	}

	case NODE_ID:
	    return strdup(node->value);

	case NODE_OP: {
	    if (strcmp(node->value, "=") == 0) {
	        char* var = geraCodigo(node->children[0]);    
	        char* expr = geraCodigo(node->children[1]);   
	        emit("STORE", var, expr, "-");                    
	        return var;
	    }

            else if (strcmp(node->value, "return") == 0) {
                if (node->nchildren == 1) {
                    char* expr = geraCodigo(node->children[0]);
                    emit("RETURN", expr, "-", "-");
                } else {
                    emit("RETURN", "-", "-", "-");
                }
                return NULL;
            }

	    else if (strcmp(node->value, "if") == 0) {
	        char* cond = geraCodigo(node->children[0]);
    	        char labelElse[16], labelEnd[16];
    	        static int labelCount = 0;
    		sprintf(labelElse, "L%d", labelCount++);
    		sprintf(labelEnd, "L%d", labelCount++);

    		emit("IFF", cond, labelElse, "-");
    		geraCodigo(node->children[1]);  
    		emit("GOTO", labelEnd, "-", "-");
    		emit("LABEL", labelElse, "-", "-");
    		emit("LABEL", labelEnd, "-", "-");
    		return NULL;
	    }
        
	    else if (strcmp(node->value, "if-else") == 0) {
    		char* cond = geraCodigo(node->children[0]);
    		char labelElse[16], labelEnd[16];
    		static int labelCount = 0;
    		sprintf(labelElse, "L%d", labelCount++);
    		sprintf(labelEnd, "L%d", labelCount++);

    		emit("IFF", cond, labelElse, "-");
    		geraCodigo(node->children[1]);  
    		emit("GOTO", labelEnd, "-", "-");
    		emit("LABEL", labelElse, "-", "-");
    		geraCodigo(node->children[2]);  
    		emit("LABEL", labelEnd, "-", "-");
    		return NULL;
	    }

	    else if (strcmp(node->value, "while") == 0) {
    		char labelBegin[16], labelEnd[16];
    		static int labelCount = 0;
    		sprintf(labelBegin, "L%d", labelCount++);
    		sprintf(labelEnd, "L%d", labelCount++);

    		emit("LABEL", labelBegin, "-", "-");
    		char* cond = geraCodigo(node->children[0]);
    		emit("IFF", cond, labelEnd, "-");
    		geraCodigo(node->children[1]);  
    		emit("GOTO", labelBegin, "-", "-");
    		emit("LABEL", labelEnd, "-", "-");
    		return NULL;
            }

	    else {
    		char* arg1 = geraCodigo(node->children[0]);
    		char* t1 = arg1;
    		if (precisaLoad(arg1)) {
        	    t1 = newTemp();
        	    emit("LOAD", t1, arg1, "-");
    		}

    		char* arg2 = geraCodigo(node->children[1]);
    		char* t2 = arg2;
    		if (precisaLoad(arg2)) {
        	    t2 = newTemp();
        	    emit("LOAD", t2, arg2, "-");
    		}

    		char* result = newTemp();
    		emit(traduzOperador(node->value), result, t1, t2);
    		return result;
	    }


	} 

	case NODE_ACTIVATION: {
	    int numArgs = 0;

	    if (node->nchildren > 0) {
	        processaArgs(node->children[0], &numArgs);
	    }

	    char* result = newTemp();
	    char numStr[16];
	    sprintf(numStr, "%d", numArgs);
	    emit("CALL", result, node->value, numStr);

	    return result;
	}


    } 
    return NULL;
}


void printCodigoIntermediario() {
    printf("\nCodigo Intermediario:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%s, %s, %s, %s\n",
               quads[i].op,
               quads[i].result,
               quads[i].arg1,
               quads[i].arg2);
    }
}

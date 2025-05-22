#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "codintermed.h"


Quadrupla quads[1000];
int quadIndex = 0;
int tempCount = 0;


void emit(const char* op, const char* arg1, const char* arg2, const char* result) {
    strcpy(quads[quadIndex].op, op);
    strcpy(quads[quadIndex].arg1, arg1);
    strcpy(quads[quadIndex].arg2, arg2);
    strcpy(quads[quadIndex].result, result);
    quadIndex++;
}

char* newTemp() {
    char* nome = malloc(10);         
    sprintf(nome, "t%d", tempCount);  
    tempCount++;                      
    return nome;
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

	case NODE_FUN_DECL:
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
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
            for (int i = 0; i < node->nchildren; i++) {
                geraCodigo(node->children[i]);
            }
            break;
	
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
	        emit("=", expr, "-", var);                    
	        return var;
	    }

            else if (strcmp(node->value, "return") == 0) {
                if (node->nchildren == 1) {
                    char* expr = geraCodigo(node->children[0]);
                    emit("return", expr, "-", "-");
                } else {
                    emit("return", "-", "-", "-");
                }
                return NULL;
            }

	    else if (strcmp(node->value, "if") == 0) {
	        char* cond = geraCodigo(node->children[0]);
    	        char labelElse[16], labelEnd[16];
    	        static int labelCount = 0;
    		sprintf(labelElse, "L%d", labelCount++);
    		sprintf(labelEnd, "L%d", labelCount++);

    		emit("ifFalse", cond, "-", labelElse);
    		geraCodigo(node->children[1]);  
    		emit("goto", "-", "-", labelEnd);
    		emit("label", "-", "-", labelElse);
    		emit("label", "-", "-", labelEnd);
    		return NULL;
	    }
        
	    else if (strcmp(node->value, "if-else") == 0) {
    		char* cond = geraCodigo(node->children[0]);
    		char labelElse[16], labelEnd[16];
    		static int labelCount = 0;
    		sprintf(labelElse, "L%d", labelCount++);
    		sprintf(labelEnd, "L%d", labelCount++);

    		emit("ifFalse", cond, "-", labelElse);
    		geraCodigo(node->children[1]);  
    		emit("goto", "-", "-", labelEnd);
    		emit("label", "-", "-", labelElse);
    		geraCodigo(node->children[2]);  
    		emit("label", "-", "-", labelEnd);
    		return NULL;
	    }

	    else if (strcmp(node->value, "while") == 0) {
    		char labelBegin[16], labelEnd[16];
    		static int labelCount = 0;
    		sprintf(labelBegin, "L%d", labelCount++);
    		sprintf(labelEnd, "L%d", labelCount++);

    		emit("label", "-", "-", labelBegin);
    		char* cond = geraCodigo(node->children[0]);
    		emit("ifFalse", cond, "-", labelEnd);
    		geraCodigo(node->children[1]);  
    		emit("goto", "-", "-", labelBegin);
    		emit("label", "-", "-", labelEnd);
    		return NULL;
            }

            else {
                char* arg1 = geraCodigo(node->children[0]);
                char* arg2 = geraCodigo(node->children[1]);
                char* temp = newTemp();
                emit(node->value, arg1, arg2, temp);
                return temp;
            }
	} 

	case NODE_ACTIVATION: {
	    for (int i = 0; i < node->nchildren; i++) {
        	geraCodigo(node->children[i]);
    	    }

	    emit("call", node->value, "-", "-");

	    return strdup(node->value); 
	}


    } 
    return NULL;
}


void printCodigoIntermediario() {
    printf("\nCodigo Intermediario:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%s, %s, %s, %s\n",
               quads[i].op,
               quads[i].arg1,
               quads[i].arg2,
               quads[i].result);
    }
}

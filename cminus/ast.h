#ifndef AST_H
#define AST_H

typedef enum { 
    NODE_PROGRAM,
    NODE_DECLARATION_LIST,
    NODE_VAR_DECL,
    NODE_FUN_DECL,
    NODE_TYPE_SPECIFIER,
    NODE_PARAMS,
    NODE_PARAM_LIST,
    NODE_PARAM,
    NODE_COMPOUND_DECL,
    NODE_LOCAL_DECLS,
    NODE_STATEMENT_LIST,
    NODE_EXPRESSION_DECL,
    NODE_ACTIVATION,
    NODE_ARGS,
    NODE_ARG_LIST,
    NODE_OP,
    NODE_NUM,
    NODE_ID
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    char *value;
    int num;
    int nchildren;
    int capacity;
    struct ASTNode **children;
} ASTNode;

ASTNode *newASTNode(ASTNodeType type, const char *value, int num);
void addChild(ASTNode *parent, ASTNode *child);
void printAST(ASTNode *node, int indent, int isLast);
void freeAST(ASTNode *node);

#endif

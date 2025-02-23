#ifndef AST_H
#define AST_H

typedef enum { 
    NODE_PROGRAM,
    NODE_DECLARATION_LIST,
    NODE_DECLARATION,
    NODE_VAR_DECL,
    NODE_FUN_DECL,
    NODE_TYPE_SPECIFIER,
    NODE_PARAMS,
    NODE_PARAM_LIST,
    NODE_PARAM,
    NODE_COMPOUND_DECL,
    NODE_LOCAL_DECLS,
    NODE_STATEMENT_LIST,
    NODE_STATEMENT,
    NODE_EXPRESSION_DECL,
    NODE_EXPRESSION,
    NODE_VAR,
    NODE_ACTIVATION,
    NODE_ARGS,
    NODE_ARG_LIST,
    NODE_SIMPLE_EXPR,
    NODE_ADDITIVE_EXPR,
    NODE_TERM,
    NODE_FACTOR,
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
void printAST(ASTNode *node, int indent);
void freeAST(ASTNode *node);

#endif

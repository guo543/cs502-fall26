#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <vector>
#include <map>
#include "stt.h"

enum DataType { DATATYPE_UNDEFINED, DATATYPE_STR, DATATYPE_INT, DATATYPE_BOOL, DATATYPE_VOID };

// Returns the name of the given data type.
static inline const char *type_string(enum DataType t) {
    static const char *names[] = {"Undefined", "String", "Integer", "Boolean", "Void"};
    return names[t % 5];
}

struct SemanticData {
    enum DataType type;
    std::vector<struct SemanticData*> formals;
    int dimensions;
    union value_t {
        char* string_value;
        int int_value;
        bool boolean_value;
    } value;
};

enum NodeType {
    NODETYPE_PROGRAM,
    NODETYPE_MAINCLASS,
    NODETYPE_MAINMETHOD,
    NODETYPE_MAINMETHODARGS,

    NODETYPE_PRIMETYPE,

    NODETYPE_STATICVARDECLLIST,
    NODETYPE_STATICMETHODLIST,

    NODETYPE_VARDECLLINE,
    NODETYPE_VARDECL,
    NODETYPE_STATICVARDECLLINE,
    NODETYPE_VARINIT,
    NODETYPE_STATICMETHODDECL,

    NODETYPE_METHODCALL,
    NODETYPE_FORMALLIST,
    NODETYPE_FORMALVAR,

    NODETYPE_LEFTVALUE,

    NODETYPE_STATEMENTLIST,
    NODETYPE_STATEMENT_COMPOUND,
    NODETYPE_STATEMENT_IFELSE,
    NODETYPE_STATEMENT_WHILE,
    NODETYPE_STATEMENT_PRINTLN,
    NODETYPE_STATEMENT_PRINT,
    NODETYPE_STATEMENT_PARSEINT,
    NODETYPE_STATEMENT_ASSIGNMENT,
    NODETYPE_STATEMENT_RETURN,

    NODETYPE_EXPLIST,

    NODETYPE_EXP_LEFTVALLENGTH,
    NODETYPE_EXP_INTLITERAL,
    NODETYPE_EXP_STRLITERAL,
    NODETYPE_EXP_BOOLLITERAL,
    NODETYPE_EXP_NEWOBJ,

    NODETYPE_EXP_POSITIVE,
    NODETYPE_EXP_NEGATIVE,
    NODETYPE_EXP_NEGATE,
    
    NODETYPE_EXP_MULTIPLY,
    NODETYPE_EXP_DIVIDE,

    NODETYPE_EXP_SUBTRACT,
    NODETYPE_EXP_ADD,

    NODETYPE_EXP_LESSER,
    NODETYPE_EXP_GREATER,
    NODETYPE_EXP_LEQ,
    NODETYPE_EXP_GREQ,
    
    NODETYPE_EXP_NEQ,
    NODETYPE_EXP_EQEQ,

    NODETYPE_EXP_LOGAND,

    NODETYPE_EXP_LOGOR,

    NODETYPE_INDEX
};

struct ASTNode {
    //struct ASTNode* parent;
    std::vector<struct ASTNode*> children;
    int lineno;
    enum NodeType node_type;
    struct STTNode* scope;
    struct SemanticData data;
};

// Creates a new node with 0 children on the heap using `malloc()`.
struct ASTNode* new_node(enum NodeType t);
void add_child(struct ASTNode* parent, struct ASTNode* child);
void prepend_child(struct ASTNode* parent, struct ASTNode* child);

// Sets the data of the node to the given value and the corresponding type.

void set_data_type(struct ASTNode* node, enum DataType data_type);
void set_string_value(struct ASTNode* node, char* s);
void set_int_value(struct ASTNode* node, int i);
void set_boolean_value(struct ASTNode* node, bool b);
void print_AST(struct ASTNode* root, int level);

#endif

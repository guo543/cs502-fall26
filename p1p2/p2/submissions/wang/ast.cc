#include "ast.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

extern int yylineno;

struct ASTNode* new_node(enum NodeType t){
    struct ASTNode* ast_node = (struct ASTNode*) malloc(sizeof(struct ASTNode));
    memset(ast_node, 0, sizeof(struct ASTNode));
    ast_node->node_type = t;
    ast_node->lineno = yylineno;
    return ast_node;
}

void prepend_child(struct ASTNode* parent, struct ASTNode* child) {
    //if (child) child -> parent = parent;
    parent -> children.insert(parent->children.begin(), child);
}

void add_child(struct ASTNode* parent, struct ASTNode* child){
    //if (child) child -> parent = parent;
    parent -> children.push_back(child);
}

void set_data_type(struct ASTNode* node, enum DataType data_type) {
    node->data.type = data_type;
}

void set_string_value(struct ASTNode* node, char* s){
    node->data.value.string_value = s;
}

void set_int_value(struct ASTNode* node, int i){
    node->data.value.int_value = i;
}

void set_boolean_value(struct ASTNode* node, bool b){
    node->data.value.boolean_value = b;
}


static inline const char* print_node(struct ASTNode* node) {
    static const char* to_str[] = {"Program", "Main Class", "Main Method", "Main Method Args",
        "Prime Type", "Static Var List", "Static Method List",
        "Var Decl Line", "Var Decl", "Static Var Decl Line", "Var Init", "Static Method Decl",
        "Method Call", "Formal List", "Formal Var", "Left Value", "Statement List",
        "Compound Statement", "If Else", "While", "Println", "Print", "ParseInt", "LVal Assignment", "Return",
        "Expression List", "LVal Length", "Int Literal", "String Literal", "Bool Literal", "New Object",
        "Positive", "Negative", "Negate", "Multiply", "Divide", "Subtract", "Add", 
        "Lesser", "Greater", "Leq", "Greq", "Neq", "Eqeq", "Logical And", "Logical Or", "Index"};
    return to_str[node->node_type % 47];
}

void print_AST(struct ASTNode* root, int level) {
    if (!root) return;

    std::cout << root->lineno << std::string(level, '\t') << print_node(root) << " ";
    std::cout << type_string(root->data.type) << " " << root->data.dimensions << " " << root->data.formals.size() << std::endl;

    for (int i = 0; i < root->children.size(); i++) {
        print_AST(root->children[i], level+1);
    }
}

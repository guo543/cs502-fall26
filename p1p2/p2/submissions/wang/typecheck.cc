#include "typecheck.h"
#include "ast.h"
#include "stt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stdbool.h>
#include <vector>

/* UTILITY FUNCTIONS */

std::vector<int> typeErrorReports;

void report_type_violation(int line_number) {
    typeErrorReports.push_back(line_number);
}

void dump_reports() {   
    std::sort(typeErrorReports.begin(), typeErrorReports.end());
    for (int i = 0; i < typeErrorReports.size(); i++) {
        fprintf(stderr, "Type violation in line %d\n", typeErrorReports[i]);
    }
}

bool typeMatch(struct SemanticData* d1, struct SemanticData* d2) {
    if (d1->type == DATATYPE_UNDEFINED || d2->type == DATATYPE_UNDEFINED) 
        return true;
    if (d1->type != d2->type) 
        return false;
    if (d1->dimensions != d2->dimensions) 
        return false;
    if (d1->formals.size() != d2->formals.size()) 
        return false;
    for (int i = 0; i < d1->formals.size(); i++) {
        if (!typeMatch(d1->formals[i], d2->formals[i]))
            return false;
    }

    return true;
}

/* TYPE CHECKING */

int typeCheck(struct ASTNode* node);
int typeCheck_VarDecl(struct ASTNode* node);
int typeCheck_MethodCall(struct ASTNode* node);
int typeCheck_ControlBlock(struct ASTNode* node);
int typeCheck_Print(struct ASTNode* node);
int typeCheck_ParseInt(struct ASTNode* node);
int typeCheck_Assignment(struct ASTNode* node);
int typeCheck_Return(struct ASTNode* node);
int typeCheck_LeftValLength(struct ASTNode* node);
int typeCheck_NewObj(struct ASTNode* node);
int typeCheck_UnaryInteger(struct ASTNode* node);
int typeCheck_UnaryBoolean(struct ASTNode* node);
int typeCheck_BinaryInteger(struct ASTNode* node);
int typeCheck_Addition(struct ASTNode* node);
int typeCheck_ComparisonInteger(struct ASTNode* node);
int typeCheck_Equality(struct ASTNode* node);
int typeCheck_BinaryBoolean(struct ASTNode* node);
int typeCheck_Index(struct ASTNode* node);

int typeCheck_None(struct ASTNode* node) { return 0; }
int typeCheck_Default(struct ASTNode* node) {
    int result = 0;
    for (int i = 0; i < node->children.size(); i++) {
        result = result || typeCheck(node->children[i]);
    }
    return result;
}

// type check table
int (* typeCheckTable [])(struct ASTNode*) = {
    typeCheck_Default,
    typeCheck_Default,
    typeCheck_Default,
    typeCheck_None,
    typeCheck_None,
    typeCheck_Default,
    typeCheck_Default, // method list
    typeCheck_Default,
    typeCheck_VarDecl,
    typeCheck_Default,
    typeCheck_Default,
    typeCheck_Default,
    typeCheck_MethodCall,
    typeCheck_None,
    typeCheck_None,
    typeCheck_Default,
    typeCheck_Default,
    typeCheck_Default,
    typeCheck_ControlBlock,
    typeCheck_ControlBlock,
    typeCheck_Print,
    typeCheck_Print,
    typeCheck_ParseInt,
    typeCheck_Assignment,
    typeCheck_Return, // return
    typeCheck_Default,
    typeCheck_LeftValLength,
    typeCheck_None,
    typeCheck_None,
    typeCheck_None,
    typeCheck_Default, // new obj
    typeCheck_UnaryInteger,
    typeCheck_UnaryInteger,
    typeCheck_UnaryBoolean,
    typeCheck_BinaryInteger,
    typeCheck_BinaryInteger,
    typeCheck_BinaryInteger,
    typeCheck_Addition,
    typeCheck_ComparisonInteger,
    typeCheck_ComparisonInteger,
    typeCheck_ComparisonInteger,
    typeCheck_ComparisonInteger,
    typeCheck_Equality,
    typeCheck_Equality,
    typeCheck_BinaryBoolean,
    typeCheck_BinaryBoolean,
    typeCheck_Index
};

// definitions

int typeCheck(struct ASTNode* node) {
    if (!node) 
        return 0;

    return typeCheckTable[node->node_type % 47](node);
}

int typeCheck_VarDecl(struct ASTNode* node) {
    if (node->children.size() == 0 || 
        !node->children[0])
        return 0;

    typeCheck_Default(node);
    
    struct ASTNode* rval = node->children[0]->children[0];
    
    if (!typeMatch(&node->data, &rval->data)) {
        report_type_violation(node->lineno);
        return 1;
    } 

    return 0;
}

int typeCheck_MethodCall(struct ASTNode* node) {
    typeCheck_Default(node);

    struct STTNode* residentScope = findResidentScope(&methodTab, &node->data);
    if (residentScope != NULL) {
        auto match = residentScope->symtab->find(node->data.value.string_value);

        set_data_type(node, match->second->type);

        std::vector<struct SemanticData*> formals = match->second->formals;
        std::vector<struct ASTNode*> arguments = node->children[0]->children;
        
        // check arguments match

        if (arguments.size() != formals.size()) {
            report_type_violation(node->lineno);
            return 1;
        }

        for (int i = 0; i < arguments.size(); i++) {
            if (!typeMatch(&arguments[i]->data, formals[i])) {
                report_type_violation(node->lineno);
                return 1;
            }
        }

        return 0;
    } else {
        report_type_violation(node->lineno);
        return 1;
    }
}

int typeCheck_ControlBlock(struct ASTNode* node) {
    typeCheck_Default(node);
    
    struct SemanticData booleanData;
    booleanData.type = DATATYPE_BOOL;
    booleanData.dimensions = 0;
    if (!typeMatch(&booleanData, &node->children[0]->data)) {
        report_type_violation(node->lineno);
        return 1;
    }

    return 0;
}

int typeCheck_Print(struct ASTNode* node) {
    typeCheck_Default(node);

    if (node->data.dimensions > 0) {
        report_type_violation(node->lineno);
        return 1;
    }

    return 0;
}

int typeCheck_ParseInt(struct ASTNode* node) {
    typeCheck_Default(node);
    set_data_type(node, DATATYPE_INT);
    
    struct SemanticData strData;
    strData.type = DATATYPE_STR;
    strData.dimensions = 0;
    if (!typeMatch(&strData, &node->children[0]->data)) {
        report_type_violation(node->lineno);
        return 1;
    }

    return 0;
}

int typeCheck_Assignment(struct ASTNode* node) {
    typeCheck_Default(node);
    struct ASTNode* lhs = node->children[0];
    struct ASTNode* rhs = node->children[1];

    if (!typeMatch(&lhs->data, &rhs->data)) {
        report_type_violation(node->lineno);
        return 1;
    } 
    
    return 0;
}

int typeCheck_Return(struct ASTNode* node) {
    typeCheck_Default(node);
    struct ASTNode* returnVal = node->children[0];
    struct SemanticData* returnType = node->scope->returnType;

    if (!typeMatch(returnType, &returnVal->data)) {
        report_type_violation(node->lineno);
        return 1;
    } 
    return 0;
}

int typeCheck_LeftValLength(struct ASTNode* node) {
    typeCheck_Default(node);

    if (node->data.type != DATATYPE_UNDEFINED &&
        node->data.dimensions < 1) {
        report_type_violation(node->lineno);
    }

    set_data_type(node, DATATYPE_INT);
    node->data.dimensions = 0;

    return 0;
}

int typeCheck_UnaryInteger(struct ASTNode* node) {
    typeCheck_Default(node);
    
    struct SemanticData intData;
    intData.type = DATATYPE_INT;
    intData.dimensions = 0;
    if (!typeMatch(&intData, &node->children[0]->data)) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
        return 1;
    }

    if (node->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    }

    set_data_type(node, DATATYPE_INT);
    return 0;
}

int typeCheck_UnaryBoolean(struct ASTNode* node) {
    typeCheck_Default(node);
    
    struct SemanticData boolData;
    boolData.type = DATATYPE_BOOL;
    boolData.dimensions = 0;
    if (!typeMatch(&boolData, &node->children[0]->data)) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
        return 1;
    }
    
    if (node->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    } 
    
    set_data_type(node, DATATYPE_BOOL);
    return 0;
}

int typeCheck_BinaryInteger(struct ASTNode* node) {
    typeCheck_Default(node);
    
    if (node->children[0]->data.type == DATATYPE_UNDEFINED ||
        node->children[1]->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    }
    
    struct SemanticData intData;
    intData.type = DATATYPE_INT;
    intData.dimensions = 0;
    if (!typeMatch(&intData, &node->children[0]->data) ||
        !typeMatch(&intData, &node->children[1]->data)) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
        return 1;
    }
    
    set_data_type(node, DATATYPE_INT);
    return 0;
}

int typeCheck_Addition(struct ASTNode* node) {
    typeCheck_Default(node);

    if (node->children[0]->data.type == DATATYPE_UNDEFINED ||
        node->children[1]->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    }
    
    struct SemanticData intData;
    intData.type = DATATYPE_INT;
    intData.dimensions = 0;

    if (typeMatch(&intData, &node->children[0]->data) &&
        typeMatch(&intData, &node->children[1]->data)) {
        set_data_type(node, DATATYPE_INT);
        return 0;
    }

    struct SemanticData strData;
    strData.type = DATATYPE_STR;
    strData.dimensions = 0;

    if (typeMatch(&strData, &node->children[0]->data) &&
        typeMatch(&strData, &node->children[1]->data)) {
        set_data_type(node, DATATYPE_STR);
        return 0;
    }

    report_type_violation(node->lineno);
    set_data_type(node, DATATYPE_UNDEFINED);
    return 1;
}

int typeCheck_ComparisonInteger(struct ASTNode* node) {
    typeCheck_Default(node);
    
    if (node->children[0]->data.type == DATATYPE_UNDEFINED ||
        node->children[1]->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    }
    
    struct SemanticData intData;
    intData.type = DATATYPE_INT;
    intData.dimensions = 0;
    if (!typeMatch(&intData, &node->children[0]->data) ||
        !typeMatch(&intData, &node->children[1]->data)) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
        return 1;
    }

    set_data_type(node, DATATYPE_BOOL);
    return 0;
}

int typeCheck_Equality(struct ASTNode* node) {
    typeCheck_Default(node);
    
    if (node->children[0]->data.type == DATATYPE_UNDEFINED ||
        node->children[1]->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    }

    if (!typeMatch(&node->children[0]->data, &node->children[1]->data)) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
    }

    set_data_type(node, DATATYPE_BOOL);
    return 0;
}

int typeCheck_BinaryBoolean(struct ASTNode* node) {
    typeCheck_Default(node);
    
    if (node->children[0]->data.type == DATATYPE_UNDEFINED ||
        node->children[1]->data.type == DATATYPE_UNDEFINED) {
        set_data_type(node, DATATYPE_UNDEFINED);
        return 0;
    }
    
    struct SemanticData boolData;
    boolData.type = DATATYPE_BOOL;
    boolData.dimensions = 0;
    if (!typeMatch(&boolData, &node->children[0]->data) ||
        !typeMatch(&boolData, &node->children[1]->data)) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
        return 1;
    }

    set_data_type(node, DATATYPE_BOOL);
    return 0;
}

int typeCheck_Index(struct ASTNode* node) {
    typeCheck_Default(node);

    struct SemanticData intData;
    intData.type = DATATYPE_INT;
    intData.dimensions = 0;

    for (int i = 0; i < node->children.size(); i++) {
        if (!typeMatch(&intData, &node->children[i]->data)) {
            report_type_violation(node->lineno);
            return 1;
        }
    }

    return 0;
}
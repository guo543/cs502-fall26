#include "stt.h"
#include <map>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include "typecheck.h"
#include <iostream>

/* STT UTILITY FUNCTIONS */

struct SemanticData* createDataCopy(struct SemanticData* semData) {
    struct SemanticData* new_data = (struct SemanticData*) malloc(sizeof(struct SemanticData));
    memset(new_data, 0, sizeof(struct SemanticData));

    new_data->type = semData->type;

    for (int i = 0; i < semData->formals.size(); i++) {
        new_data->formals.push_back(createDataCopy(semData->formals[i]));
    }
    
    new_data->dimensions = semData->dimensions;
    new_data->value = semData->value;

    return new_data;
}

void copyType(struct SemanticData* from, struct SemanticData* to) {
    to->type = from->type;

    for (int i = 0; i < from->formals.size(); i++) {
        to->formals.push_back(createDataCopy(from->formals[i]));
    }
    
    to->dimensions = from->dimensions;
}

struct STTNode* newScope(struct STTNode* parent) {
    struct STTNode* stt_node = (struct STTNode*) malloc(sizeof(struct STTNode));
    memset(stt_node, 0, sizeof(struct STTNode));
    stt_node->returnType = (struct SemanticData*) malloc(sizeof(struct SemanticData));
    memset(stt_node->returnType, 0, sizeof(struct SemanticData));
    stt_node->symtab = new SymTab();
    stt_node->parent = parent;
    stt_node->classScope = false;
    
    if (parent) {
        parent->children.push_back(stt_node);
        copyType(parent->returnType, stt_node->returnType);
    }

    return stt_node;
}

struct STTNode* newScope() {
    return newScope(NULL);
}

void insertSymTabEntry(SymTab* symtab, struct SemanticData* semData) {
    struct SemanticData* copy = createDataCopy(semData);
    symtab->insert({semData->value.string_value, copy});
}

void addFormal(struct SemanticData* method_data, struct SemanticData* formal_data) {
    method_data->formals.push_back(createDataCopy(formal_data));
}

struct STTNode* findResidentScope(struct STTNode* currscope, struct SemanticData* semData) {
    if (!currscope) 
        return NULL;
    
    auto match = currscope->symtab->find(semData->value.string_value);
    if (match != currscope->symtab->end()) 
        return currscope;

    return findResidentScope(currscope->parent, semData);
}

/* STT CONSTRUCTION */

struct STTNode methodTab;

// prototypes
void constructSTT(struct ASTNode* node, struct STTNode* scope);
void constructSTT_Program(struct ASTNode* node, struct STTNode* scope);
void constructSTT_MainMethod(struct ASTNode* node, struct STTNode* scope);
void constructSTT_MainMethodArgs(struct ASTNode* node, struct STTNode* scope);
void constructSTT_VarDeclLine(struct ASTNode* node, struct STTNode* scope);
void constructSTT_VarDecl(struct ASTNode* node, struct STTNode* scope);
void constructSTT_StaticMethodDecl(struct ASTNode* node, struct STTNode* scope);
void constructSTT_FormalVar(struct ASTNode* node, struct STTNode* scope);
void constructSTT_LeftValue(struct ASTNode* node, struct STTNode* scope);
void constructSTT_StatementCompound(struct ASTNode* node, struct STTNode* scope);
void constructSTT_IfElse(struct ASTNode* node, struct STTNode* scope);
void constructSTT_While(struct ASTNode* node, struct STTNode* scope);
void constructSTT_NewObj(struct ASTNode* node, struct STTNode* scope);

void constructSTT_None(struct ASTNode* node, struct STTNode* scope) {}
void constructSTT_Default(struct ASTNode* node, struct STTNode* scope) {
    for (int i = 0; i < node->children.size(); i++) {
        constructSTT(node->children[i], scope);
    }
}

// construction switch table
void (* sttConstructTab [])(struct ASTNode*, struct STTNode*) = {
    constructSTT_Program,
    constructSTT_Default,
    constructSTT_MainMethod,
    constructSTT_MainMethodArgs,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_VarDeclLine,
    constructSTT_VarDecl,
    constructSTT_VarDeclLine,
    constructSTT_Default,
    constructSTT_StaticMethodDecl,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_FormalVar,
    constructSTT_LeftValue,
    constructSTT_Default,
    constructSTT_StatementCompound,
    constructSTT_IfElse,
    constructSTT_While,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_LeftValue,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_NewObj,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default,
    constructSTT_Default
};

// definitions

void constructSTT(struct ASTNode* node, struct STTNode* scope) {
    if (!node) 
        return;

    node->scope = scope;
    sttConstructTab[node->node_type % 47](node, scope);
}

void constructSTT(struct ASTNode* root) {
    methodTab.symtab = new SymTab;
    constructSTT(root, NULL);
}

void constructSTT_Program(struct ASTNode* root, struct STTNode* scope) {
    struct STTNode* root_stt_node = newScope();
    root_stt_node->classScope = true;
    copyType(&root->data, root_stt_node->returnType);
    root->scope = root_stt_node;
    constructSTT_Default(root, root_stt_node);
}

void constructSTT_MainMethod(struct ASTNode* node, struct STTNode* scope) {
    addFormal(&node->data, &(node->children[0]->data));
    set_data_type(node, DATATYPE_VOID);
    insertSymTabEntry(methodTab.symtab, &node->data);
    struct STTNode* new_scope = newScope(scope);
    copyType(&node->data, new_scope->returnType);
    constructSTT_Default(node, new_scope);
}

void constructSTT_MainMethodArgs(struct ASTNode* node, struct STTNode* scope) {
    insertSymTabEntry(scope->symtab, &node->data);
}

void constructSTT_VarDeclLine(struct ASTNode* node, struct STTNode* scope) {
    struct SemanticData* type_info = &node->children[0]->data;
    for (int i = 1; i < node->children.size(); i++) {
        copyType(type_info, &node->children[i]->data);
    }
    constructSTT_Default(node, scope);
}

void constructSTT_VarDecl(struct ASTNode* node, struct STTNode* scope) {
    struct STTNode* residentScope = findResidentScope(scope, &node->data);
    if (residentScope == NULL || (scope->classScope != residentScope->classScope)) {
        insertSymTabEntry(scope->symtab, &node->data);
    } else {
        report_type_violation(node->lineno);

        auto match = residentScope->symtab->find(node->data.value.string_value);
        if (!typeMatch(&node->data, match->second)) {
            set_data_type(node, DATATYPE_UNDEFINED);
        }

        if (scope != residentScope) {
            insertSymTabEntry(scope->symtab, &node->data);
        } else {
            match->second->type = node->data.type;
        }
    }

    constructSTT_Default(node, scope);
}

void constructSTT_StaticMethodDecl(struct ASTNode* node, struct STTNode* scope) {
    struct SemanticData* type_info = &node->children[0]->data;
    copyType(type_info, &node->data);

    struct STTNode* methodBodySTTNode = newScope(scope);
    copyType(&node->data, methodBodySTTNode->returnType);
    constructSTT_Default(node, methodBodySTTNode);
    struct ASTNode* formalListNode = node->children[1];

    for (int i = 0; i < formalListNode->children.size(); i++) {
        addFormal(&node->data, &formalListNode->children[i]->data);
    }

    struct STTNode* residentScope = findResidentScope(&methodTab, &node->data);

    if (residentScope == NULL) {
        insertSymTabEntry(methodTab.symtab, &node->data);
    } else {
        report_type_violation(node->lineno);

        auto match = residentScope->symtab->find(node->data.value.string_value);
        if (match->second->type != node->data.type) {
            match->second->type = DATATYPE_UNDEFINED;
        }
    }
}

void constructSTT_FormalVar(struct ASTNode* node, struct STTNode* scope) {
    struct SemanticData* type_info = &node->children[0]->data;
    copyType(type_info, &node->data);
    struct STTNode* residentScope = findResidentScope(scope, &node->data);
    if (residentScope == NULL || (scope->classScope != residentScope->classScope)) {
        insertSymTabEntry(scope->symtab, &node->data);
    } else {
        report_type_violation(node->lineno);

        auto match = residentScope->symtab->find(node->data.value.string_value);
        if (!typeMatch(&node->data, match->second)) {
            match->second->type = DATATYPE_UNDEFINED;
        }
        // should i insert it into symtab???
    }
}

void constructSTT_LeftValue(struct ASTNode* node, struct STTNode* scope) {
    struct STTNode* residentScope = findResidentScope(scope, &node->data);
    // if not in var table, look in method table
    if (residentScope == NULL) {
    //     residentScope = findResidentScope(&methodTab, &node->data);

    // // if not in either table, truly does not exist
    // if (residentScope == NULL) {
        report_type_violation(node->lineno);
        set_data_type(node, DATATYPE_UNDEFINED);
    }
    
    if (residentScope != NULL) {
        auto match = residentScope->symtab->find(node->data.value.string_value);
        copyType(match->second, &node->data);
        node->data.dimensions -= node->children[0]->data.dimensions;
        
        if (node->data.dimensions < 0) {
            report_type_violation(node->lineno);
            set_data_type(node, DATATYPE_UNDEFINED);
        }
    }
    constructSTT_Default(node, scope);
}

void constructSTT_StatementCompound(struct ASTNode* node, struct STTNode* scope) {
    struct STTNode* compound_scope = newScope(scope);
    node->scope = scope;
    constructSTT_Default(node, compound_scope);
}

void constructSTT_IfElse(struct ASTNode* node, struct STTNode* scope) {
    struct STTNode* if_scope = newScope(scope);
    struct STTNode* else_scope = newScope(scope);
    node->scope = scope;
    constructSTT(node->children[0], scope);
    constructSTT(node->children[1], if_scope);
    constructSTT(node->children[2], else_scope);
}

void constructSTT_While(struct ASTNode* node, struct STTNode* scope) {
    struct STTNode* while_scope = newScope(scope);
    node->scope = scope;
    constructSTT_Default(node, while_scope);
}

void constructSTT_NewObj(struct ASTNode* node, struct STTNode* scope) {
    struct SemanticData* type_info = &node->children[0]->data;
    copyType(type_info, &node->data);
    node->data.dimensions += node->children[1]->data.dimensions;
    constructSTT_Default(node, scope);
}

/* Debug Functions */

void printSTT(struct STTNode* root, int level) {
    if (!root) return;

   std::cout << type_string(root->returnType->type) << " " << root->returnType->dimensions << " " << std::endl;

    SymTab* symtab = root->symtab;
    for (auto i = symtab->begin(); i != symtab->end(); i++) {
        struct SemanticData* data = i->second;
        std::cout << std::string(level, '\t') << i->first << " " << type_string(data->type) << " " << data->formals.size() << " " << data->dimensions << " " << std::endl;
    }
    std::cout << std::endl;  

    for (int i = 0; i < root->children.size(); i++) {
        printSTT(root->children[i], level+1);
    }
}

void printSTT(struct STTNode* root) {
   if (!root) return;

   SymTab* symtab = methodTab.symtab;
   for (auto i = symtab->begin(); i != symtab->end(); i++) {
      struct SemanticData* data = i->second;
      std::cout << i->first << " " << type_string(data->type) << " " << data->formals.size() << " " << data->dimensions << " " << std::endl;
      for (int f = 0; f < data->formals.size(); f++) {
        std::cout << "\t" << type_string(data->formals[f]->type) << " " << data->formals[f]->dimensions << " " << std::endl;
      }
   }
   std::cout << std::endl;

   printSTT(root, 0);
} 
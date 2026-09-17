#ifndef STT_H
#define STT_H

#include <stdbool.h>
#include <vector>
#include <map>
#include <string.h>
#include "ast.h"

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return strcmp(a, b) < 0;
   }
};

typedef std::map<char*, struct SemanticData*, cmp_str> SymTab;

struct STTNode {
   struct SemanticData* returnType;
   struct STTNode* parent;
   std::vector<struct STTNode*> children;
   SymTab* symtab;
   bool classScope = false;
};

extern struct STTNode methodTab;

struct STTNode* findResidentScope(struct STTNode* currscope, struct SemanticData* semData);
void constructSTT(struct ASTNode* root);

void printSTT(struct STTNode* root);

#endif
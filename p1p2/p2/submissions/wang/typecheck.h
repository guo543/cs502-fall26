#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

#include "ast.h"
#include <vector>
#include <stdbool.h>

void report_type_violation(int lineno);
void dump_reports();
bool typeMatch(struct SemanticData* d1, struct SemanticData* d2);
int typeCheck(struct ASTNode* program);

extern int num_errors;
extern int num_entries;

#endif

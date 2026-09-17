%{
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "typecheck.h"
#include <vector>
#include "ast.h"
#include "stt.h"
void yyerror( const char *);

extern int yylex();

// Global variables defined by lex.yy.c.
extern int yylineno;
extern char* yytext;
extern FILE *yyin;

struct ASTNode* root;
%}

// Declares all variants of semantic values. Yacc/Bison copies all variants
// to the generated header file (y.tab.h) enclosed in a C-language union
// declaration, named `YYSTYPE`. Check out the header file to see it.

%union {
    struct ASTNode* node;
    int integer;
    char* string;
}

// Left hand non-terminals. They are all associated to the `node` variant
// declared in the %union section, which is of type `ASTNode *`.
%type <node> Program MainClass MainMethod MainMethodArgs PrimeType Type
%type <node> StaticVarDeclList StaticMethodDeclList StaticVarDecl StaticMethodDecl
%type <node> VarDeclLine VarInit ExtraVarDecl MethodCall FormalList FormalVar LeftValue
%type <node> StatementList Statement 
%type <node> ExpList ExpL16 ExpL14 ExpL12 ExpL11 ExpL9 ExpL8 ExpL4 ExpL3 Exp
%type <node> Index

// Declares tokens. In the generated y.tab.h file, each token gets declared as 
// a enum constant and assigned with a unique number. These enum constants are
// used in the lex file, returned by `yylex()` to denote the symbolic tokens.

// These keyword-like tokens doesn't need to have a semantic value.
%token KW_BOOLEAN KW_CLASS KW_PUBLIC KW_PRIVATE KW_STATIC KW_VOID KW_STRING KW_INT KW_IF KW_ELSE KW_WHILE KW_RETURN KW_NEW
%token PRINTLN PRINT PARSEINT LENGTH KW_TRUE KW_FALSE TOK_ID TOK_STRLITERAL TOK_INTLITERAL 
%token TOK_PLUSPLUS TOK_MINUSMINUS TOK_ANDAND TOK_OROR TOK_GREQ TOK_LEQ TOK_EQEQ TOK_NEQ

// These tokens have additional information aside from what kind of token it
// is, so they carry semantic information.
%token <integer> INT_LITERAL
%token <string> STR_LITERAL ID KW_MAIN

%start Program

%%

Program:                
    MainClass {
        $$ = new_node(NODETYPE_PROGRAM);
        root = $$;
        add_child($$, $1);
    }
    ;

MainClass: 
    KW_CLASS ID '{' 
        StaticVarDeclList StaticMethodDeclList MainMethod
    '}'
    {
        $$ = new_node(NODETYPE_MAINCLASS);
        set_string_value($$, $2);
        add_child($$, $4);
        add_child($$, $5);
        add_child($$, $6);
    }
    ;

MainMethod:
    KW_PUBLIC KW_STATIC KW_VOID KW_MAIN '(' MainMethodArgs ')' '{' StatementList '}'
    {
        $$ = new_node(NODETYPE_MAINMETHOD);
        $$->lineno = $6->lineno;
        set_string_value($$, $4);
        add_child($$, $6);
        add_child($$, $9);
    }
    ;

MainMethodArgs:
    KW_STRING '[' ']' ID {
        $$ = new_node(NODETYPE_MAINMETHODARGS);
        set_string_value($$, $4);
        set_data_type($$, DATATYPE_STR);
        $$->data.dimensions = 1;
    }
    ;

PrimeType:
    KW_INT {
        $$ = new_node(NODETYPE_PRIMETYPE);
        set_data_type($$, DATATYPE_INT);
    }
    | KW_BOOLEAN {
        $$ = new_node(NODETYPE_PRIMETYPE);
        set_data_type($$, DATATYPE_BOOL);
    }
    | KW_STRING {
        $$ = new_node(NODETYPE_PRIMETYPE);
        set_data_type($$, DATATYPE_STR);
    }
    ;

Type: 
    PrimeType {
        $$ = $1;
    }
    | Type '[' ']' {
        $$->data.dimensions++;
    }
    ;

StaticVarDeclList:
    StaticVarDeclList StaticVarDecl {
        $$ = $1;
        add_child($$, $2);
    }
    | {
        $$ = new_node(NODETYPE_STATICVARDECLLIST);
    }
    ;

StaticVarDecl:
    KW_PRIVATE KW_STATIC VarDeclLine {
        $$ = $3;
        $$->node_type = NODETYPE_STATICVARDECLLINE;
    }
    ;

VarDeclLine:
    Type ID VarInit ExtraVarDecl ';' {
        $$ = $4;
        struct ASTNode* vardecl = new_node(NODETYPE_VARDECL);
        set_string_value(vardecl, $2);
        add_child(vardecl, $3);
        prepend_child($$, vardecl);
        prepend_child($$, $1);
    }
    ;

ExtraVarDecl:
    ExtraVarDecl ',' ID VarInit {
        $$ = $1;
        struct ASTNode* vardecl = new_node(NODETYPE_VARDECL);
        set_string_value(vardecl, $3);
        add_child(vardecl, $4);
        add_child($$, vardecl);
    }
    | {
        $$ = new_node(NODETYPE_VARDECLLINE);
    }
    ;

VarInit:
    '=' Exp {
        $$ = new_node(NODETYPE_VARINIT);
        add_child($$, $2);
    }
    | {
        $$ = NULL;
    }
    ;

StaticMethodDeclList:
    StaticMethodDeclList StaticMethodDecl {
        $$ = $1;
        add_child($$, $2);
    }
    | {
        $$ = new_node(NODETYPE_STATICMETHODLIST);
    }
    ;

StaticMethodDecl: 
    KW_PUBLIC KW_STATIC Type ID '(' FormalList ')' '{' StatementList '}' {
        $$ = new_node(NODETYPE_STATICMETHODDECL);
        $$->lineno = $6->lineno;
        set_string_value($$, $4);
        add_child($$, $3);
        add_child($$, $6);
        add_child($$, $9);
    }
    ;

MethodCall:
    ID '(' ExpList ')' {
        $$ = new_node(NODETYPE_METHODCALL);
        set_string_value($$, $1);
        add_child($$, $3);
    }
    | PARSEINT '(' Exp ')' {
        $$ = new_node(NODETYPE_STATEMENT_PARSEINT);
        add_child($$, $3);
    }
    ;

FormalList:
    FormalList ',' FormalVar {
        $$ = $1;
        add_child($$, $3);
    }
    | FormalVar {
        $$ = new_node(NODETYPE_FORMALLIST);
        add_child($$, $1);
    }
    | {
        $$ = new_node(NODETYPE_FORMALLIST);
    }
    ;

FormalVar:
    Type ID {
        $$ = new_node(NODETYPE_FORMALVAR);
        add_child($$, $1);
        set_string_value($$, $2);
    }
    ;

LeftValue:
    ID Index {
        $$ = new_node(NODETYPE_LEFTVALUE);
        set_string_value($$, $1);
        add_child($$, $2);
    }
    ;

StatementList:
    StatementList Statement {
        $$ = $1;
        add_child($$, $2);
    }
    | {
        $$ = new_node(NODETYPE_STATEMENTLIST);
    }
    ;

Statement:
    VarDeclLine {
        $$ = $1;
    }
    | '{' StatementList '}' {
        $$ = new_node(NODETYPE_STATEMENT_COMPOUND);
        add_child($$, $2);
    }
    | KW_IF '(' Exp ')' Statement KW_ELSE Statement {
        $$ = new_node(NODETYPE_STATEMENT_IFELSE);
        add_child($$, $3);
        add_child($$, $5);
        add_child($$, $7);
    }
    | KW_WHILE '(' Exp ')' Statement {
        $$ = new_node(NODETYPE_STATEMENT_WHILE);
        add_child($$, $3);
        add_child($$, $5);
    }
    | PRINTLN '(' Exp ')' ';' {
        $$ = new_node(NODETYPE_STATEMENT_PRINTLN);
        add_child($$, $3);
    }
    | PRINT '(' Exp ')' ';' {
        $$ = new_node(NODETYPE_STATEMENT_PRINT);
        add_child($$, $3);
    }
    | LeftValue '=' Exp ';' {
        $$ = new_node(NODETYPE_STATEMENT_ASSIGNMENT);
        add_child($$, $1);
        add_child($$, $3);
    }
    | KW_RETURN Exp ';' {
        $$ = new_node(NODETYPE_STATEMENT_RETURN);
        add_child($$, $2);
    }
    | MethodCall ';' {
        $$ = $1;
    }
    ;

ExpList: 
    ExpList ',' Exp {
        $$ = $1;
        add_child($$, $3);
    }
    | Exp {
        $$ = new_node(NODETYPE_EXPLIST);
        add_child($$, $1);
    }
    | {
        $$ = new_node(NODETYPE_EXPLIST);
    }
    ;

ExpL16:
    '(' Exp ')' {
        $$ = $2;
    }
    | INT_LITERAL {
        $$ = new_node(NODETYPE_EXP_INTLITERAL);
        set_data_type($$, DATATYPE_INT);
        set_int_value($$, $1);
    }
    | STR_LITERAL {
        $$ = new_node(NODETYPE_EXP_STRLITERAL);
        set_data_type($$, DATATYPE_STR);
        set_string_value($$, $1);
    }
    | KW_TRUE {
        $$ = new_node(NODETYPE_EXP_BOOLLITERAL);
        set_data_type($$, DATATYPE_BOOL);
        set_boolean_value($$, true);
    }
    | KW_FALSE {
        $$ = new_node(NODETYPE_EXP_BOOLLITERAL);
        set_data_type($$, DATATYPE_BOOL);
        set_boolean_value($$, false);
    }
    | LeftValue LENGTH {
        $$ = $1;
        $$->node_type = NODETYPE_EXP_LEFTVALLENGTH;
    }
    | LeftValue {
        $$ = $1;
    }
    | MethodCall {
        $$ = $1;
    }
    | KW_NEW PrimeType '[' Exp ']' Index {
        $$ = new_node(NODETYPE_EXP_NEWOBJ);
        add_child($$, $2);
        add_child($$, $6);
        prepend_child($6, $4);
        $6->data.dimensions++;
    }
    ;

ExpL14:
    '+' ExpL14 {
        $$ = new_node(NODETYPE_EXP_POSITIVE);
        add_child($$, $2);
    }
    | '-' ExpL14 {
        $$ = new_node(NODETYPE_EXP_NEGATIVE);
        add_child($$, $2);
    }
    | '!' ExpL14 {
        $$ = new_node(NODETYPE_EXP_NEGATE);
        add_child($$, $2);
    }
    | ExpL16 {
        $$ = $1;
    }
    ;

ExpL12:
    ExpL12 '*' ExpL14 {
        $$ = new_node(NODETYPE_EXP_MULTIPLY);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL12 '/' ExpL14 {
        $$ = new_node(NODETYPE_EXP_DIVIDE);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL14 {
        $$ = $1;
    }
    ;

ExpL11:
    ExpL11 '-' ExpL12 {
        $$ = new_node(NODETYPE_EXP_SUBTRACT);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL11 '+' ExpL12 {
        $$ = new_node(NODETYPE_EXP_ADD);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL12 {
        $$ = $1;
    }
    ;

ExpL9:
    ExpL9 '<' ExpL11 {
        $$ = new_node(NODETYPE_EXP_LESSER);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL9 '>' ExpL11 {
        $$ = new_node(NODETYPE_EXP_GREATER);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL9 TOK_LEQ ExpL11 {
        $$ = new_node(NODETYPE_EXP_LEQ);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL9 TOK_GREQ ExpL11 {
        $$ = new_node(NODETYPE_EXP_GREQ);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL11 {
        $$ = $1;
    }
    ;

ExpL8:
    ExpL8 TOK_NEQ ExpL9 {
        $$ = new_node(NODETYPE_EXP_NEQ);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL8 TOK_EQEQ ExpL9 {
        $$ = new_node(NODETYPE_EXP_EQEQ);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL9 {
        $$ = $1;
    }
    ;

ExpL4:
    ExpL4 TOK_ANDAND ExpL8 {
        $$ = new_node(NODETYPE_EXP_LOGAND);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL8 {
        $$ = $1;
    }
    ;

ExpL3:
    ExpL3 TOK_OROR ExpL4 {
        $$ = new_node(NODETYPE_EXP_LOGOR);
        add_child($$, $1);
        add_child($$, $3);
    }
    | ExpL4 {
        $$ = $1;
    }
    ;

Exp:
    ExpL3 {
        $$ = $1;
    }
    ;

Index: 
    Index '[' Exp ']' {
        $$ = $1;
        add_child($$, $3);
        $$->data.dimensions++;
    }
    | {
        $$ = new_node(NODETYPE_INDEX);
    }
    ;
%%

void yyerror( const char* s) {
    fprintf(stderr, "Syntax errors in line %d\n", yylineno);
}

int main(int argc, char* argv[] )
{
    yyin = fopen( argv[1], "r" );

    // Checks for syntax errors and constructs AST
    if (yyparse() != 0)
        return 1;

    // Traverse the AST to check for semantic errors if no syntac errors
    constructSTT(root);
    //printSTT(root->scope);
    typeCheck(root);
    //print_AST(root, 0);
    dump_reports();
    
    return 0;
}

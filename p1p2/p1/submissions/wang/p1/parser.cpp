#include <stddef.h>                                                             /* for NULL */
#include <stdlib.h>                                                             /* for EXIT_SUCCESS and EXIT_FAILURE */
#include <iostream>
#include "parser.hpp"

// yylex is used to get tokens from lex
extern int yylex();
extern void syntax_error();
int current_token;

// nonterminals
static void Program();
static void MainClass();
static void VarDecl();
static void ExtraVarDecl();
static void VarInit();
static void Type();
static void ArrTail();
static void StatementList();
static void Statement();
static void Expression();
static void Exp();
static void OpExp();
static void Op();
static void LeftValue();
static void LengthTail();
static void Index();

// advance current token
static void consume() {
    current_token = yylex();
}

// return true if current token is expected
// otherwise return false
static bool peek(int expected_token) {
    if(current_token == expected_token) {
        return true;
    }
    return false;
}

static void match(int expected_token) {
    if (!peek(expected_token)) syntax_error();
    consume();
}

static void Index() {
    if (peek(TOK_LBRACKET)) {
        match(TOK_LBRACKET);
        Expression();
        match(TOK_RBRACKET);
        Index();
    }
    else if ( peek(TOK_RBRACKET) || peek(TOK_RPARANTHESES) || 
         peek(TOK_COMMA) || peek(TOK_SEMICOLON) || 
         peek(TOK_ANDAND) || peek(TOK_OROR) || 
         peek(TOK_GR) || peek(TOK_LE) || 
         peek(TOK_GREQ) || peek(TOK_LEQ) || 
         peek(TOK_EQEQ) || peek(TOK_NEQ) || 
         peek(TOK_PLUS) || peek(TOK_MINUS) ||
         peek(TOK_AST) || peek(TOK_FSLASH) ||
         peek(TOK_EQ) || peek(TOK_DOT) ) {
        return;
    }
    else {
        syntax_error();
    }
}

static void LengthTail() {
    if ( peek(TOK_RBRACKET) || peek(TOK_RPARANTHESES) || 
         peek(TOK_COMMA) || peek(TOK_SEMICOLON) || 
         peek(TOK_ANDAND) || peek(TOK_OROR) || 
         peek(TOK_GR) || peek(TOK_LE) || 
         peek(TOK_GREQ) || peek(TOK_LEQ) || 
         peek(TOK_EQEQ) || peek(TOK_NEQ) || 
         peek(TOK_PLUS) || peek(TOK_MINUS) ||
         peek(TOK_AST) || peek(TOK_FSLASH) ) {
        return;
    }
    else if (peek(TOK_DOT)) {
        match(TOK_DOT);
        match(TOK_LENGTH);
    }
    else {
        syntax_error();
    }
}

static void LeftValue() {
    if (peek(TOK_ID)) {
        match(TOK_ID);
        Index();
    }
    else {
        syntax_error();
    }
}

static void Op() {
    if (peek(TOK_ANDAND)) {
        match(TOK_ANDAND);
    }
    else if (peek(TOK_OROR)) {
        match(TOK_OROR);
    }
    else if (peek(TOK_GR)) {
        match(TOK_GR);
    }
    else if (peek(TOK_LE)) {
        match(TOK_LE);
    }
    else if (peek(TOK_GREQ)) {
        match(TOK_GREQ);
    }    
    else if (peek(TOK_LEQ)) {
        match(TOK_LEQ);
    }
    else if (peek(TOK_EQEQ)) {
        match(TOK_EQEQ);
    } 
    else if (peek(TOK_NEQ)) {
        match(TOK_NEQ);
    }
    else if (peek(TOK_PLUS)) {
        match(TOK_PLUS);
    }    
    else if (peek(TOK_MINUS)) {
        match(TOK_MINUS);
    }    
    else if (peek(TOK_AST)) {
        match(TOK_AST);
    }
    else if (peek(TOK_FSLASH)) {
        match(TOK_FSLASH);
    }
    else {
        syntax_error();
    }
}

static void OpExp() {
    if ( peek(TOK_RBRACKET) || peek(TOK_RPARANTHESES) || 
         peek(TOK_COMMA) || peek(TOK_SEMICOLON) ) {
        return;
    }
    if ( peek(TOK_ANDAND) || peek(TOK_OROR) || 
         peek(TOK_GR) || peek(TOK_LE) || 
         peek(TOK_GREQ) || peek(TOK_LEQ) || 
         peek(TOK_EQEQ) || peek(TOK_NEQ) || 
         peek(TOK_PLUS) || peek(TOK_MINUS) ||
         peek(TOK_AST) || peek(TOK_FSLASH) ) {
        Op();
        Exp();
        OpExp();
    }
    else {
        syntax_error();
    }
}

static void Exp() {
    if (peek(TOK_ID)) {
        LeftValue();
        LengthTail();
    }
    else if (peek(TOK_LPARANTHESES)) {
        match(TOK_LPARANTHESES);
        Expression();
        match(TOK_RPARANTHESES);
    }
    else if (peek(TOK_INTLITERAL)) {
        match(TOK_INTLITERAL);
    }
    else if (peek(TOK_STRLITERAL)) {
        match(TOK_STRLITERAL);
    }
    else if (peek(TOK_BOOLTRUE)) {
        match(TOK_BOOLTRUE);
    }
    else if (peek(TOK_BOOLFALSE)) {
        match(TOK_BOOLFALSE);
    }
    else if (peek(KW_NEW)) {
        match(KW_NEW);
        Type();
        match(TOK_LBRACKET);
        Expression();
        match(TOK_RBRACKET);
        Index();
    }
    else {
        syntax_error();
    }
}

static void Expression() {
    if ( peek(TOK_ID) || peek(TOK_LPARANTHESES) || 
         peek(TOK_INTLITERAL) || peek(TOK_STRLITERAL) ||
         peek(TOK_BOOLTRUE) || peek(TOK_BOOLFALSE) || 
         peek(KW_NEW) ) {
        Exp();
        OpExp();
    }
    else {
        syntax_error();
    }
}

static void Statement() {
    if (peek(TOK_ID)) {
        LeftValue();
        match(TOK_EQ);
        Expression();
        match(TOK_SEMICOLON);
    } 
    else if (peek(TOK_LBRACE)) {
        match(TOK_LBRACE);
        StatementList();
        match(TOK_RBRACE);
    }
    else if (peek(KW_STRING) || peek(KW_INT) || peek(KW_BOOL)) {
        Type();
        ArrTail();
        VarDecl();
        ExtraVarDecl();
        match(TOK_SEMICOLON);
    }
    else if (peek(KW_IF)) {
        match(KW_IF);
        match(TOK_LPARANTHESES);
        Expression();
        match(TOK_RPARANTHESES);
        Statement();
        match(KW_ELSE);
        Statement();
    }
    else if (peek(KW_WHILE)) {
        match(KW_WHILE);
        match(TOK_LPARANTHESES);
        Expression();
        match(TOK_RPARANTHESES);
        Statement();
    }
    else if (peek(TOK_PRINTLN)) {
        match(TOK_PRINTLN);
        match(TOK_LPARANTHESES);
        Expression();
        match(TOK_RPARANTHESES);
        match(TOK_SEMICOLON);
    }
    else if (peek(TOK_PRINT)) {
        match(TOK_PRINT);
        match(TOK_LPARANTHESES);
        Expression();
        match(TOK_RPARANTHESES);
        match(TOK_SEMICOLON);
    }
    else if (peek(KW_RETURN)) {
        match(KW_RETURN);
        Expression();
        match(TOK_SEMICOLON);
    }
    else {
        syntax_error();
    }
}

static void StatementList() {
    if ( peek(TOK_ID) || peek(TOK_LBRACE) || peek(KW_RETURN) ||
         peek(KW_STRING) || peek(KW_INT) || peek(KW_BOOL) ||
         peek(KW_IF) || peek(KW_ELSE) || peek(KW_WHILE) ||
         peek(TOK_PRINTLN) || peek(TOK_PRINT) ) {
        Statement();
        StatementList();    
    }
    else if (peek(TOK_RBRACE)) {
        return;
    }
    else {
        syntax_error();
    }
}

static void ArrTail() {
    if (peek(TOK_ID)) {
        return;
    }
    else if (peek(TOK_LBRACKET)) {
        match(TOK_LBRACKET);
        match(TOK_RBRACKET);
        ArrTail();
    }
    else {
        syntax_error();
    }
}

static void Type() {
    if (peek(KW_STRING)) {
        match(KW_STRING);
    }
    else if (peek(KW_INT)) {
        match(KW_INT);
    }
    else if (peek(KW_BOOL)) {
        match(KW_BOOL);
    }
    else {
        syntax_error();
    }
}

static void VarInit() {
    if (peek(TOK_COMMA)) {
        return;
    }
    else if (peek(TOK_EQ)) {
        match(TOK_EQ);
        Expression();
    }
    else if (peek(TOK_SEMICOLON)) {
        return;
    }
    else {
        return;
    }
}

static void ExtraVarDecl() {
    if (peek(TOK_COMMA)) {
        match(TOK_COMMA);
        VarDecl();
        ExtraVarDecl();
    } 
    else if (peek(TOK_SEMICOLON)) {
        return;
    } 
    else {
        syntax_error();
    } 
}

static void VarDecl() {
    if (peek(TOK_ID)) {
        match(TOK_ID);
        VarInit();
    } else {
        syntax_error();
    }
}

static void MainClass() {
    if (peek(KW_CLASS)) {
        match(KW_CLASS);
        match(TOK_ID);
        match(TOK_LBRACE);

        match(KW_PUBLIC);
        match(KW_STATIC);
        match(KW_VOID);
        match(KW_MAIN);

        match(TOK_LPARANTHESES);
        match(KW_STRING);
        match(TOK_LBRACKET);
        match(TOK_RBRACKET);
        match(TOK_ID);
        match(TOK_RPARANTHESES);

        match(TOK_LBRACE);

        StatementList();

        match(TOK_RBRACE);
        match(TOK_RBRACE);
    } else {
        syntax_error();
    }
}

static void Program() {
    consume();
    if (peek(KW_CLASS)) {
        MainClass();
    } else {
        syntax_error();
    }
}

// write code to perform recursive descent based on the grammar after
// rewriting it

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char *path = argv[1];
        FILE *file = fopen(path, "r");
        if(file == NULL) {
            perror("Cannot open file");
            return EXIT_FAILURE;
        }

        set_instream(file);
    }
    Program();
    match(TOK_EOF);

    // call the function to match the start non terminal here
    return EXIT_SUCCESS;
}
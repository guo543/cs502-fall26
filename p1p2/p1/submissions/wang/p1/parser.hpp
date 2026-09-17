#ifndef parser_h
#define parser_h

#include <stdio.h>

// enumerate all tokens (terminals) here
enum Token {
    TOK_ANDAND,                                                                    // operators
    TOK_OROR,
    TOK_GR,
    TOK_LE,
    TOK_GREQ,
    TOK_LEQ,
    TOK_EQEQ,
    TOK_NEQ,
    TOK_PLUS,
    TOK_MINUS,
    TOK_AST,
    TOK_FSLASH,
    TOK_EQ,
    KW_CLASS,                                                                   // keywords
    KW_PUBLIC,
    KW_STATIC,
    KW_VOID,
    KW_MAIN,
    KW_STRING,
    KW_INT,
    KW_BOOL,
    KW_IF,
    KW_ELSE,
    KW_WHILE,
    KW_RETURN,
    KW_NEW,
    TOK_PRINTLN,
    TOK_PRINT,
    TOK_LENGTH,
    TOK_ID,
    TOK_STRLITERAL,
    TOK_INTLITERAL,
    TOK_BOOLTRUE,
    TOK_BOOLFALSE,
    TOK_DOT,                                                                    // other terminals
    TOK_COMMA,
    TOK_SEMICOLON,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_LPARANTHESES,
    TOK_RPARANTHESES,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_EOF
};

void syntax_error();
void set_instream(FILE*);

#endif
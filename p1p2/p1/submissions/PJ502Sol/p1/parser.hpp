#ifndef parser_h
#define parser_h

#include <stdio.h>

// enumerate all tokens (terminals) here
enum Token {
    TOK_PLUS,
    TOK_MINUS,
    TOK_AST,
    TOK_FSLASH,
    TOK_NOT,
    TOK_EQ,
    TOK_LT,
    TOK_GT,
    TOK_ANDAND,                                                                    // operators
    TOK_OROR,
    TOK_GREQ,
    TOK_LEQ,
    TOK_EQEQ,
    TOK_NEQ,
    TOK_PLUSPLUS,
    TOK_MINUSMINUS,
    KW_CLASS,                                                                   // keywords
    KW_PRIVATE,
    KW_PUBLIC,
    KW_STATIC,
    KW_VOID,
    KW_STRING,
    KW_INT,
    KW_BOOL,
    KW_IF,
    KW_ELSE,
    KW_WHILE,
    KW_RETURN,
    KW_NEW,
    KW_THIS,
    KW_EXTENDS,
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
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACKET,
    TOK_RBRACKET,
    TOK_EOF
};

void syntax_error();
void set_instream(FILE*);

#endif

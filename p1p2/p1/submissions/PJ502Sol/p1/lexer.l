%option noyywrap
%option yylineno

%{
#include <stdio.h>                                                              /* for fprintf() */
#include <stdlib.h>                                                             /* for EXIT_FAILURE */
#include <iostream>

#include "parser.hpp"

void syntax_error() {
    fprintf(stderr, "Syntax errors in %d\n", yylineno);
    exit(EXIT_FAILURE);
    std::cout << "hi" << std::endl;
}
%}

%%


    /* write regex to match all terminals */
    /* a few example are given below */

[ \t\r\n]*                  { }                                                 /* whitespace */

"//"[^\n]*                      { }                                                 /* inline comments */

"/*"([^*]|"*"+[^/*])*"*"+"/"    { }                                                 /* block comments */

"+"             { return TOK_PLUS; }
"-"             { return TOK_MINUS; }
"*"             { return TOK_AST; }
"/"             { return TOK_FSLASH; }
"!"             { return TOK_NOT; }
"="             { return TOK_EQ; }
"<"             { return TOK_LT; }
">"             { return TOK_GT; }
"&&"            { return TOK_ANDAND; }                                 /* operators */
"||"            { return TOK_OROR; }
">="            { return TOK_GREQ; }
"<="            { return TOK_LEQ; }
"=="            { return TOK_EQEQ; }
"!="            { return TOK_NEQ; }
"++"            { return TOK_PLUSPLUS; }
"--"            { return TOK_MINUSMINUS; }

"class"         { return KW_CLASS; }                                /* keywords */
"private"       { return KW_PRIVATE; }
"public"        { return KW_PUBLIC; }
"static"        { return KW_STATIC; }
"void"          { return KW_VOID; }
"String"        { return KW_STRING; }
"int"           { return KW_INT; }
"boolean"       { return KW_BOOL; }
"if"            { return KW_IF; }
"else"          { return KW_ELSE; }
"while"         { return KW_WHILE; }
"return"        { return KW_RETURN; }
"new"           { return KW_NEW; }
"this"          { return KW_THIS; }
"extends"	{ return KW_EXTENDS; }

"System.out.println"   { return TOK_PRINTLN; }
"System.out.print"     { return TOK_PRINT; }
"length"               { return TOK_LENGTH; }

    /* identifiers */
    
"true"                      { return TOK_BOOLTRUE; }
"false"                     { return TOK_BOOLFALSE; }
[a-zA-Z][a-zA-Z0-9_]*       { return TOK_ID; }
\"(\\[^\n]|[^"\\\n])*\"     { return TOK_STRLITERAL; }
[0-9]+                      { return TOK_INTLITERAL; }

    /* literals */
    
"."                         { return TOK_DOT; }                                 /* other terminals */
","                         { return TOK_COMMA; }
";"                         { return TOK_SEMICOLON; }
"{"                         { return TOK_LBRACE; }
"}"                         { return TOK_RBRACE; }
"("                         { return TOK_LPAREN; }
")"                         { return TOK_RPAREN; }
"["                         { return TOK_LBRACKET; }
"]"                         { return TOK_RBRACKET; }

.                           { syntax_error(); }                                 /* all other characters */

<<EOF>>                     { return TOK_EOF; }

%%

// yyin is the input stream for lex, not providing a file defaults to
// standard input
void set_instream(FILE *file) {
  yyin = file;
}

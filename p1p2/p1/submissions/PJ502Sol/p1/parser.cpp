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
//static void ExtraVarDecl();
// static void VarInit();
static void Type();
// static void ArrTail();
static void StatementList();
static void Statement();
static void Expression();
static void Exp();
static void ExpList();
// static void MethodCall();
static void OpExp();
static void BinaryOp();
static void LeftValue();
static void LeftValueTail();
static void FactorTail();
//static void LengthTail();
static void Index();
static void Modifiers();
static void VarDeclTail();

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
    else if ( peek(TOK_RBRACKET) || peek(TOK_RPAREN) || 
         peek(TOK_COMMA) || peek(TOK_SEMICOLON) || 
         peek(TOK_ANDAND) || peek(TOK_OROR) || 
         peek(TOK_GT) || peek(TOK_LT) || 
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

static void BinaryOp() {
    if ( peek(TOK_ANDAND)) {
        match(TOK_ANDAND);
    }
    else if (peek(TOK_OROR)) {
        match(TOK_OROR);
    }
    else if (peek(TOK_GT)) {
        match(TOK_GT);
    }
    else if (peek(TOK_LT)) {
        match(TOK_LT);
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
    if ( peek(TOK_RBRACKET) || peek(TOK_RPAREN) || 
         peek(TOK_COMMA) || peek(TOK_SEMICOLON) ) {
        return;
    }
    if ( peek(TOK_ANDAND) || peek(TOK_OROR) || 
         peek(TOK_GT) || peek(TOK_LT) || 
         peek(TOK_GREQ) || peek(TOK_LEQ) || 
         peek(TOK_EQEQ) || peek(TOK_NEQ) || 
         peek(TOK_PLUS) || peek(TOK_MINUS) ||
         peek(TOK_AST) || peek(TOK_FSLASH) ) {
        BinaryOp();
        Expression();
    }
    else {
        syntax_error();
    }
}

static void Exp() { // The leading term of an expression that may be followed
		    // by subexpressions
    if ( peek(TOK_PLUS) || peek(TOK_MINUS) || peek(TOK_NOT) ) {
        // Unary ops
        consume();
	Exp();
    }
    else if (peek(TOK_LPAREN)) {
        match(TOK_LPAREN);
        Expression();
        match(TOK_RPAREN);
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
        consume();
	if ( peek(KW_INT) || peek(KW_BOOL) || peek(KW_STRING) ) {
		// new array
	   consume();
	   Index();
	} else if (peek(TOK_ID)) { // Object instantiation
	   consume();
	   match(TOK_LPAREN);
	   match(TOK_RPAREN);
	}
    } 
    else if (peek(TOK_ID)) {
	consume();
	if ( peek(TOK_LPAREN) ) { // Method invocation
	   consume();
	   ExpList();
	   match(TOK_RPAREN);
	} 
    	else FactorTail();
    }
}

static void FactorTail() {
	//Almost like LeftValueTail, except may also end with
	//the .length operation for arrays.
	if (!(peek(TOK_LBRACKET) || peek(TOK_DOT) )) return;
        if (peek(TOK_LBRACKET)) {
		consume();
		Expression();
		match(TOK_RBRACKET);	
		FactorTail();
    	} else {
          match(TOK_DOT);
	  if (peek(TOK_LENGTH)) {
	      consume();
	      return;
	  }
	  match(TOK_ID);
	  FactorTail();
    	}
}
	
static void Expression() {
    if ( peek(TOK_ID) || peek(TOK_LPAREN) || 
         peek(TOK_INTLITERAL) || peek(TOK_STRLITERAL) ||
         peek(TOK_BOOLTRUE) || peek(TOK_BOOLFALSE) || 
         peek(KW_NEW) || peek(KW_THIS) ) {
        Exp();
        OpExp();
    }
    else {
        syntax_error();
    }
}

static void ExpList() {
    if ( peek(TOK_ID) || peek(TOK_LPAREN) || 
         peek(TOK_INTLITERAL) || peek(TOK_STRLITERAL) ||
         peek(TOK_BOOLTRUE) || peek(TOK_BOOLFALSE) || 
         peek(KW_NEW) || peek(KW_THIS) ) {
	    Expression();
	    while ( !peek(TOK_RPAREN) ) {
	    	match(TOK_COMMA);
	    	Expression();
    	    }
    }
}

static void LeftValueTail() {
    if (!( peek(TOK_DOT) || peek(TOK_LBRACKET) )) return;
    if ( peek(TOK_LBRACKET) ) {   // Index exp
	consume();
	Expression();
	match(TOK_RBRACKET);	
	LeftValueTail();
    } else {
        match(TOK_DOT);
	LeftValue();
    }
}

static void LeftValue() {
    match(TOK_ID);
    LeftValueTail();
}

static void Statement() {
    if ( peek(KW_STRING) || peek(KW_INT) || peek(KW_BOOL) ||
	peek(KW_PRIVATE) || peek(KW_PUBLIC) || peek(KW_STATIC) ) { 
	    //VarDecl, absent the case of type being an ID name,
	    // which is to be handled separately with method invocation
	    // and assignment statements that are not VarDecl
	VarDecl();
    }
    else if (peek(TOK_LBRACE)) {
        consume();
        StatementList();
        match(TOK_RBRACE);
    }
    else if (peek(KW_IF)) {
        match(KW_IF);
        match(TOK_LPAREN);
        Expression();
        match(TOK_RPAREN);
        Statement();
	if ( peek(KW_ELSE) ) {
           consume();
           Statement();
   	}
    }
    else if (peek(KW_WHILE)) {
        consume();
        match(TOK_LPAREN);
        Expression();
        match(TOK_RPAREN);
        Statement();
    }
    else if (peek(TOK_PRINTLN)) {
        consume();
        match(TOK_LPAREN);
        Expression();
        match(TOK_RPAREN);
        match(TOK_SEMICOLON);
    }
    else if (peek(TOK_PRINT)) {
        consume();
        match(TOK_LPAREN);
        Expression();
        match(TOK_RPAREN);
        match(TOK_SEMICOLON);
    }
    else if (peek(KW_RETURN)) {
        consume();
        Expression();
        match(TOK_SEMICOLON);
    }
    else if ( peek(TOK_ID) || peek(KW_THIS) ) { //Could be ASGN, Method Call,
	if ( peek(KW_THIS) ) {
		consume();
		match(TOK_DOT);
	}		
        LeftValue();
	if ( peek(TOK_LPAREN) ) { // Method call
		consume();
		if ( !peek(TOK_RPAREN) ) ExpList();
		match(TOK_RPAREN);
		match(TOK_SEMICOLON);
	} else {
	        match(TOK_EQ);
                Expression();
                match(TOK_SEMICOLON);
	}
    } else syntax_error();
}

static void StatementList() {
    if (peek(TOK_RBRACE))
        return;
    else if ( peek(KW_PRIVATE) || peek(KW_PUBLIC) || peek(KW_STATIC) ||
	 peek(TOK_ID) || peek(TOK_LBRACE) || peek(KW_RETURN) ||
         peek(KW_STRING) || peek(KW_INT) || peek(KW_BOOL) ||
         peek(KW_IF) || peek(KW_WHILE) ||
         peek(KW_THIS) || peek(TOK_PRINTLN) || peek(TOK_PRINT) ) {
        Statement();
        StatementList();    
    }
    else {
        syntax_error();
    }
}

static void Type() {
    if (peek(KW_INT) || peek(KW_BOOL) || peek(TOK_ID) || peek(KW_STRING)) {	
	consume();
	while (peek(TOK_LBRACKET)) {
		consume();
		match(TOK_RBRACKET);
	}
    }
    else syntax_error();
}

static void VarDecl() {
        if ( peek(KW_PRIVATE) || peek(KW_PUBLIC) || peek(KW_STATIC) )
	   Modifiers();

	if ( peek(KW_INT) || peek(KW_BOOL) || peek(TOK_ID) || peek(KW_STRING) ) {	
   	   Type();
	   match(TOK_ID);
	   if ( peek(TOK_EQ) ) {
		   consume();
		   Expression();
	   }
	   VarDeclTail();
	   match(TOK_SEMICOLON);
  	}
}

static void FormalListTail() {
	while ( peek(TOK_COMMA) ) {
		consume();
		Type();
		match(TOK_ID);
	}
}

static void FormalList() {
	if (peek(KW_INT) || peek(KW_BOOL) ||
	       peek(TOK_ID) || peek(KW_STRING)) {	
	   Type();
	   match(TOK_ID);
	   FormalListTail();
	}
}


static void VarDeclTail() {
	while ( !peek(TOK_SEMICOLON) ) {
		match(TOK_COMMA);	
		match(TOK_ID);
		if ( peek(TOK_EQ) ) {
			consume();
			Exp();
		} 
	}
}

static void ClassDecl() {
    match(KW_CLASS);
    match(TOK_ID);

    if (peek(KW_EXTENDS)) {
	match(KW_EXTENDS);
	match(TOK_ID);
    }	

    match(TOK_LBRACE); 	// Class body
    while ( !(peek(TOK_RBRACE)) ) { //  Non-empty class body
        if ( peek(KW_PRIVATE) || peek(KW_PUBLIC) || peek(KW_STATIC) )
	   Modifiers();

	if ( peek(KW_INT) || peek(KW_BOOL) || peek(TOK_ID) || 
		peek(KW_STRING) || peek(KW_VOID) ) {	
	// "Type ID" is common to VarDecl and MethodDecl
	// Since VarDecl is the only "statement" allowed in the top of class body and
	// it requires three token look ahead to distinguish VarDecl from MethodDec,,
	// we treat it differently from VarDecl in StatementList of the Method body
	//
	   if ( peek(KW_VOID) ) { // MethodDecl
		consume();
	   	match(TOK_ID);
	   	match(TOK_LPAREN);
		FormalList();
		match(TOK_RPAREN);
		match(TOK_LBRACE);
		StatementList();
		match(TOK_RBRACE);
		continue;
	   } else {
   	   	Type();
	   	match(TOK_ID);
	   }
	   if (peek(TOK_LPAREN)) { //MethodDecl
	   	consume();
		FormalList();
		match(TOK_RPAREN);
		match(TOK_LBRACE);
		StatementList();
		match(TOK_RBRACE);
	   } else if (peek(TOK_SEMICOLON) )  //End of VarDecl
		consume();
	   else {
	        if (peek(TOK_EQ)) {
	           consume();
		   Exp();
	        }
		if (peek(TOK_COMMA)) {
	       	   VarDeclTail(); 
		   match(TOK_SEMICOLON);
		} else match(TOK_SEMICOLON);
	   }
	 } else syntax_error(); // Does not have a type INT, BOOL, ID, or String
    } // while
    match(TOK_RBRACE);
}

void Modifiers() {
    if ( peek(KW_PRIVATE) || peek(KW_PUBLIC) ) {
	consume();
	if (peek(KW_STATIC)) consume();
    } else if (peek(KW_STATIC)) {
    	consume();
	if (peek(KW_PRIVATE) || peek(KW_PUBLIC))
	   consume();
    } else syntax_error();
}

static void ClassList() {
	while ( peek(KW_CLASS) ) ClassDecl();
}

static void Program() {
    consume();
    if (peek(KW_CLASS)) {
        ClassList();
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

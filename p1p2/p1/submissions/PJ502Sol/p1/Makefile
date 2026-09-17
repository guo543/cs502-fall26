# This is a sample Makefile. You can make changes to it as long as you
# stick to the specifications listed in the handout.

CC = g++
LEX = flex
FLEXFILE = lexer.l

GENERATED = lex.yy.c
BIN = parser

all: clean parser

parser: lex.yy.c parser.cpp
	$(CC) -g lex.yy.c parser.cpp -o parser

lex.yy.c: lexer.l
	$(LEX) lexer.l
	
clean:
	rm -f $(GENERATED) $(BIN)


# CC = gcc
# LEX = lex

# GENERATED = lexer.c lex.yy.c
# BIN = parser

# all: parser

# parser: lex.yy.c parser.c
# 	$(CC) lex.yy.c parser.c -o parser

# lex.yy.c: lexer.l
# 	$(LEX) lexer.l

# clean:
# 	rm -f $(GENERATED) $(BIN)
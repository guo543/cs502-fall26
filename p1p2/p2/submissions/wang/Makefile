all: clean parser

parser: y.tab.c lex.yy.o ast.cc typecheck.cc stt.cc
	g++ stt.cc typecheck.cc ast.cc y.tab.c lex.yy.o  -g -o parser -lfl

y.tab.c: parser.y 
	bison -v -y -d -g -t --verbose parser.y

lex.yy.c: parser.l 
	lex -l parser.l

lex.yy.o: lex.yy.c 
	g++ -c lex.yy.c

lexParser: lex.yy.o 
	gcc lex.yy.o -o lexParser

clean: 
	rm -f lex.yy.c y.tab.c y.tab.h y.dot y.output interpret lex.yy.o parser
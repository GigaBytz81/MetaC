lex lexer.l

yacc -v -d parser2.y
lex lexer.l
gcc -ll y.tab.c
./a.out<input1.c

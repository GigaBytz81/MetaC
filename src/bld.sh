yacc -v -d parse.y
lex lexer.l
gcc -ll y.tab.c

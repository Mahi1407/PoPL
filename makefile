lex_gen:
	flex -olexer.c lexer.l

yacc_gen:
	@make -s lex_gen
	bison -d -o parser.c parser.y

clear:
	cls

yacc_build:
	gcc -w parser.c

run: 
	@make -s yacc_gen
	@make -s yacc_build
	type input1.c|.\a.exe
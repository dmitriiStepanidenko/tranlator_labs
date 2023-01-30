all: 
	cd buildfolder && cmake -DCMAKE_BUILD_TYPE=Debug .. && make -j4 && ./demo
	gcc t.c && ./a.out

all_test: MyGrammar.g4
	antlr4 MyGrammar.g4 -Dlanguage=Cpp #-no-listener -no-visitor
clean_test:
	-rm MyGrammarLexer.cpp MyGrammarParser.cpp MyGrammarBaseListener.cpp MyGrammarListener.cpp
	-rm MyGrammarLexer.h MyGrammarParser.h MyGrammarBaseListener.h MyGrammarListener.h
	-rm MyGrammar.interp MyGrammarLexer.interp MyGrammar.tokens MyGrammarLexer.tokens

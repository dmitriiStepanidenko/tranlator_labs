
// Generated from MyGrammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  MyGrammarLexer : public antlr4::Lexer {
public:
  enum {
    WHITESPACE = 1, EQUAL = 2, LESS = 3, SEMICOLON = 4, INCREMENT = 5, END_BRACK = 6, 
    FOR_START = 7, NUMCONST = 8, PRINT_START = 9, IDENTIFIER = 10
  };

  explicit MyGrammarLexer(antlr4::CharStream *input);

  ~MyGrammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};



// Generated from MyGrammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MyGrammarParser.
 */
class  MyGrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStatement(MyGrammarParser::StatementContext *ctx) = 0;
  virtual void exitStatement(MyGrammarParser::StatementContext *ctx) = 0;

  virtual void enterFunction(MyGrammarParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(MyGrammarParser::FunctionContext *ctx) = 0;

  virtual void enterIden_numconst(MyGrammarParser::Iden_numconstContext *ctx) = 0;
  virtual void exitIden_numconst(MyGrammarParser::Iden_numconstContext *ctx) = 0;

  virtual void enterOpt_plus(MyGrammarParser::Opt_plusContext *ctx) = 0;
  virtual void exitOpt_plus(MyGrammarParser::Opt_plusContext *ctx) = 0;


};


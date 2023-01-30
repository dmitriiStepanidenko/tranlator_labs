
// Generated from MyGrammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarListener.h"


/**
 * This class provides an empty implementation of MyGrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MyGrammarBaseListener : public MyGrammarListener {
public:

  virtual void enterStatement(MyGrammarParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(MyGrammarParser::StatementContext * /*ctx*/) override { }

  virtual void enterFunction(MyGrammarParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(MyGrammarParser::FunctionContext * /*ctx*/) override { }

  virtual void enterIden_numconst(MyGrammarParser::Iden_numconstContext * /*ctx*/) override { }
  virtual void exitIden_numconst(MyGrammarParser::Iden_numconstContext * /*ctx*/) override { }

  virtual void enterOpt_plus(MyGrammarParser::Opt_plusContext * /*ctx*/) override { }
  virtual void exitOpt_plus(MyGrammarParser::Opt_plusContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


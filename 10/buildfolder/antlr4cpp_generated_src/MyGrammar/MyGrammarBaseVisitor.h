
// Generated from MyGrammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarVisitor.h"


/**
 * This class provides an empty implementation of MyGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MyGrammarBaseVisitor : public MyGrammarVisitor {
public:

  virtual std::any visitStatement(MyGrammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(MyGrammarParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIden_numconst(MyGrammarParser::Iden_numconstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOpt_plus(MyGrammarParser::Opt_plusContext *ctx) override {
    return visitChildren(ctx);
  }


};


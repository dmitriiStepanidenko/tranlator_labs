
// Generated from MyGrammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "MyGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MyGrammarParser.
 */
class  MyGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MyGrammarParser.
   */
    virtual std::any visitStatement(MyGrammarParser::StatementContext *context) = 0;

    virtual std::any visitFunction(MyGrammarParser::FunctionContext *context) = 0;

    virtual std::any visitIden_numconst(MyGrammarParser::Iden_numconstContext *context) = 0;

    virtual std::any visitOpt_plus(MyGrammarParser::Opt_plusContext *context) = 0;


};



// Generated from MyGrammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  MyGrammarParser : public antlr4::Parser {
public:
  enum {
    WHITESPACE = 1, EQUAL = 2, LESS = 3, SEMICOLON = 4, INCREMENT = 5, END_BRACK = 6, 
    FOR_START = 7, NUMCONST = 8, PRINT_START = 9, IDENTIFIER = 10
  };

  enum {
    RuleStatement = 0, RuleFunction = 1, RuleIden_numconst = 2, RuleOpt_plus = 3
  };

  explicit MyGrammarParser(antlr4::TokenStream *input);

  MyGrammarParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MyGrammarParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StatementContext;
  class FunctionContext;
  class Iden_numconstContext;
  class Opt_plusContext; 

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    StatementContext *statement();
    antlr4::tree::TerminalNode *PRINT_START();
    Iden_numconstContext *iden_numconst();
    antlr4::tree::TerminalNode *END_BRACK();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR_START();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    std::vector<Iden_numconstContext *> iden_numconst();
    Iden_numconstContext* iden_numconst(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *LESS();
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *END_BRACK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  Iden_numconstContext : public antlr4::ParserRuleContext {
  public:
    Iden_numconstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMCONST();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Opt_plusContext *opt_plus();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Iden_numconstContext* iden_numconst();

  class  Opt_plusContext : public antlr4::ParserRuleContext {
  public:
    Opt_plusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCREMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opt_plusContext* opt_plus();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};



// Generated from MyGrammar.g4 by ANTLR 4.11.1


#include "MyGrammarListener.h"
#include "MyGrammarVisitor.h"

#include "MyGrammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MyGrammarParserStaticData final {
  MyGrammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyGrammarParserStaticData(const MyGrammarParserStaticData&) = delete;
  MyGrammarParserStaticData(MyGrammarParserStaticData&&) = delete;
  MyGrammarParserStaticData& operator=(const MyGrammarParserStaticData&) = delete;
  MyGrammarParserStaticData& operator=(MyGrammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mygrammarParserOnceFlag;
MyGrammarParserStaticData *mygrammarParserStaticData = nullptr;

void mygrammarParserInitialize() {
  assert(mygrammarParserStaticData == nullptr);
  auto staticData = std::make_unique<MyGrammarParserStaticData>(
    std::vector<std::string>{
      "statement", "function", "iden_numconst", "opt_plus"
    },
    std::vector<std::string>{
      "", "", "'='", "'<'", "';'", "'++'", "')'"
    },
    std::vector<std::string>{
      "", "WHITESPACE", "EQUAL", "LESS", "SEMICOLON", "INCREMENT", "END_BRACK", 
      "FOR_START", "NUMCONST", "PRINT_START", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,10,41,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,3,0,17,8,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	2,1,2,1,2,3,2,35,8,2,1,3,1,3,3,3,39,8,3,1,3,0,0,4,0,2,4,6,0,0,39,0,16,
  	1,0,0,0,2,18,1,0,0,0,4,34,1,0,0,0,6,38,1,0,0,0,8,9,3,2,1,0,9,10,3,0,0,
  	0,10,17,1,0,0,0,11,12,5,9,0,0,12,13,3,4,2,0,13,14,5,6,0,0,14,15,5,4,0,
  	0,15,17,1,0,0,0,16,8,1,0,0,0,16,11,1,0,0,0,17,1,1,0,0,0,18,19,5,7,0,0,
  	19,20,5,10,0,0,20,21,5,2,0,0,21,22,3,4,2,0,22,23,5,4,0,0,23,24,5,10,0,
  	0,24,25,5,3,0,0,25,26,3,4,2,0,26,27,5,4,0,0,27,28,5,10,0,0,28,29,5,5,
  	0,0,29,30,5,6,0,0,30,3,1,0,0,0,31,35,5,8,0,0,32,33,5,10,0,0,33,35,3,6,
  	3,0,34,31,1,0,0,0,34,32,1,0,0,0,35,5,1,0,0,0,36,39,5,5,0,0,37,39,1,0,
  	0,0,38,36,1,0,0,0,38,37,1,0,0,0,39,7,1,0,0,0,3,16,34,38
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mygrammarParserStaticData = staticData.release();
}

}

MyGrammarParser::MyGrammarParser(TokenStream *input) : MyGrammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MyGrammarParser::MyGrammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MyGrammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mygrammarParserStaticData->atn, mygrammarParserStaticData->decisionToDFA, mygrammarParserStaticData->sharedContextCache, options);
}

MyGrammarParser::~MyGrammarParser() {
  delete _interpreter;
}

const atn::ATN& MyGrammarParser::getATN() const {
  return *mygrammarParserStaticData->atn;
}

std::string MyGrammarParser::getGrammarFileName() const {
  return "MyGrammar.g4";
}

const std::vector<std::string>& MyGrammarParser::getRuleNames() const {
  return mygrammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& MyGrammarParser::getVocabulary() const {
  return mygrammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MyGrammarParser::getSerializedATN() const {
  return mygrammarParserStaticData->serializedATN;
}


//----------------- StatementContext ------------------------------------------------------------------

MyGrammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MyGrammarParser::FunctionContext* MyGrammarParser::StatementContext::function() {
  return getRuleContext<MyGrammarParser::FunctionContext>(0);
}

MyGrammarParser::StatementContext* MyGrammarParser::StatementContext::statement() {
  return getRuleContext<MyGrammarParser::StatementContext>(0);
}

tree::TerminalNode* MyGrammarParser::StatementContext::PRINT_START() {
  return getToken(MyGrammarParser::PRINT_START, 0);
}

MyGrammarParser::Iden_numconstContext* MyGrammarParser::StatementContext::iden_numconst() {
  return getRuleContext<MyGrammarParser::Iden_numconstContext>(0);
}

tree::TerminalNode* MyGrammarParser::StatementContext::END_BRACK() {
  return getToken(MyGrammarParser::END_BRACK, 0);
}

tree::TerminalNode* MyGrammarParser::StatementContext::SEMICOLON() {
  return getToken(MyGrammarParser::SEMICOLON, 0);
}


size_t MyGrammarParser::StatementContext::getRuleIndex() const {
  return MyGrammarParser::RuleStatement;
}

void MyGrammarParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void MyGrammarParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any MyGrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

MyGrammarParser::StatementContext* MyGrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 0, MyGrammarParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(16);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyGrammarParser::FOR_START: {
        enterOuterAlt(_localctx, 1);
        setState(8);
        function();
        setState(9);
        statement();
        break;
      }

      case MyGrammarParser::PRINT_START: {
        enterOuterAlt(_localctx, 2);
        setState(11);
        match(MyGrammarParser::PRINT_START);
        setState(12);
        iden_numconst();
        setState(13);
        match(MyGrammarParser::END_BRACK);
        setState(14);
        match(MyGrammarParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

MyGrammarParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyGrammarParser::FunctionContext::FOR_START() {
  return getToken(MyGrammarParser::FOR_START, 0);
}

std::vector<tree::TerminalNode *> MyGrammarParser::FunctionContext::IDENTIFIER() {
  return getTokens(MyGrammarParser::IDENTIFIER);
}

tree::TerminalNode* MyGrammarParser::FunctionContext::IDENTIFIER(size_t i) {
  return getToken(MyGrammarParser::IDENTIFIER, i);
}

tree::TerminalNode* MyGrammarParser::FunctionContext::EQUAL() {
  return getToken(MyGrammarParser::EQUAL, 0);
}

std::vector<MyGrammarParser::Iden_numconstContext *> MyGrammarParser::FunctionContext::iden_numconst() {
  return getRuleContexts<MyGrammarParser::Iden_numconstContext>();
}

MyGrammarParser::Iden_numconstContext* MyGrammarParser::FunctionContext::iden_numconst(size_t i) {
  return getRuleContext<MyGrammarParser::Iden_numconstContext>(i);
}

std::vector<tree::TerminalNode *> MyGrammarParser::FunctionContext::SEMICOLON() {
  return getTokens(MyGrammarParser::SEMICOLON);
}

tree::TerminalNode* MyGrammarParser::FunctionContext::SEMICOLON(size_t i) {
  return getToken(MyGrammarParser::SEMICOLON, i);
}

tree::TerminalNode* MyGrammarParser::FunctionContext::LESS() {
  return getToken(MyGrammarParser::LESS, 0);
}

tree::TerminalNode* MyGrammarParser::FunctionContext::INCREMENT() {
  return getToken(MyGrammarParser::INCREMENT, 0);
}

tree::TerminalNode* MyGrammarParser::FunctionContext::END_BRACK() {
  return getToken(MyGrammarParser::END_BRACK, 0);
}


size_t MyGrammarParser::FunctionContext::getRuleIndex() const {
  return MyGrammarParser::RuleFunction;
}

void MyGrammarParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void MyGrammarParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any MyGrammarParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

MyGrammarParser::FunctionContext* MyGrammarParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, MyGrammarParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    match(MyGrammarParser::FOR_START);
    setState(19);
    match(MyGrammarParser::IDENTIFIER);
    setState(20);
    match(MyGrammarParser::EQUAL);
    setState(21);
    iden_numconst();
    setState(22);
    match(MyGrammarParser::SEMICOLON);
    setState(23);
    match(MyGrammarParser::IDENTIFIER);
    setState(24);
    match(MyGrammarParser::LESS);
    setState(25);
    iden_numconst();
    setState(26);
    match(MyGrammarParser::SEMICOLON);
    setState(27);
    match(MyGrammarParser::IDENTIFIER);
    setState(28);
    match(MyGrammarParser::INCREMENT);
    setState(29);
    match(MyGrammarParser::END_BRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Iden_numconstContext ------------------------------------------------------------------

MyGrammarParser::Iden_numconstContext::Iden_numconstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyGrammarParser::Iden_numconstContext::NUMCONST() {
  return getToken(MyGrammarParser::NUMCONST, 0);
}

tree::TerminalNode* MyGrammarParser::Iden_numconstContext::IDENTIFIER() {
  return getToken(MyGrammarParser::IDENTIFIER, 0);
}

MyGrammarParser::Opt_plusContext* MyGrammarParser::Iden_numconstContext::opt_plus() {
  return getRuleContext<MyGrammarParser::Opt_plusContext>(0);
}


size_t MyGrammarParser::Iden_numconstContext::getRuleIndex() const {
  return MyGrammarParser::RuleIden_numconst;
}

void MyGrammarParser::Iden_numconstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIden_numconst(this);
}

void MyGrammarParser::Iden_numconstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIden_numconst(this);
}


std::any MyGrammarParser::Iden_numconstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitIden_numconst(this);
  else
    return visitor->visitChildren(this);
}

MyGrammarParser::Iden_numconstContext* MyGrammarParser::iden_numconst() {
  Iden_numconstContext *_localctx = _tracker.createInstance<Iden_numconstContext>(_ctx, getState());
  enterRule(_localctx, 4, MyGrammarParser::RuleIden_numconst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyGrammarParser::NUMCONST: {
        enterOuterAlt(_localctx, 1);
        setState(31);
        match(MyGrammarParser::NUMCONST);
        break;
      }

      case MyGrammarParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(32);
        match(MyGrammarParser::IDENTIFIER);
        setState(33);
        opt_plus();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opt_plusContext ------------------------------------------------------------------

MyGrammarParser::Opt_plusContext::Opt_plusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MyGrammarParser::Opt_plusContext::INCREMENT() {
  return getToken(MyGrammarParser::INCREMENT, 0);
}


size_t MyGrammarParser::Opt_plusContext::getRuleIndex() const {
  return MyGrammarParser::RuleOpt_plus;
}

void MyGrammarParser::Opt_plusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpt_plus(this);
}

void MyGrammarParser::Opt_plusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<MyGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpt_plus(this);
}


std::any MyGrammarParser::Opt_plusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MyGrammarVisitor*>(visitor))
    return parserVisitor->visitOpt_plus(this);
  else
    return visitor->visitChildren(this);
}

MyGrammarParser::Opt_plusContext* MyGrammarParser::opt_plus() {
  Opt_plusContext *_localctx = _tracker.createInstance<Opt_plusContext>(_ctx, getState());
  enterRule(_localctx, 6, MyGrammarParser::RuleOpt_plus);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(38);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MyGrammarParser::INCREMENT: {
        enterOuterAlt(_localctx, 1);
        setState(36);
        match(MyGrammarParser::INCREMENT);
        break;
      }

      case MyGrammarParser::SEMICOLON:
      case MyGrammarParser::END_BRACK: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void MyGrammarParser::initialize() {
  ::antlr4::internal::call_once(mygrammarParserOnceFlag, mygrammarParserInitialize);
}


// Generated from MyGrammar.g4 by ANTLR 4.11.1


#include "MyGrammarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MyGrammarLexerStaticData final {
  MyGrammarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyGrammarLexerStaticData(const MyGrammarLexerStaticData&) = delete;
  MyGrammarLexerStaticData(MyGrammarLexerStaticData&&) = delete;
  MyGrammarLexerStaticData& operator=(const MyGrammarLexerStaticData&) = delete;
  MyGrammarLexerStaticData& operator=(MyGrammarLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mygrammarlexerLexerOnceFlag;
MyGrammarLexerStaticData *mygrammarlexerLexerStaticData = nullptr;

void mygrammarlexerLexerInitialize() {
  assert(mygrammarlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MyGrammarLexerStaticData>(
    std::vector<std::string>{
      "WHITESPACE", "EQUAL", "LESS", "SEMICOLON", "INCREMENT", "END_BRACK", 
      "FOR_START", "NUMCONST", "PRINT_START", "IDENTIFIER"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,10,74,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,1,0,1,0,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,
  	1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,6,5,6,42,8,6,10,6,12,6,45,9,6,1,6,1,
  	6,1,7,4,7,50,8,7,11,7,12,7,51,1,8,1,8,1,8,1,8,1,8,1,8,1,8,5,8,61,8,8,
  	10,8,12,8,64,9,8,1,8,1,8,1,9,1,9,5,9,70,8,9,10,9,12,9,73,9,9,0,0,10,1,
  	1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,1,0,6,4,0,9,10,13,13,32,32,
  	39,39,4,0,9,10,12,13,32,32,39,39,1,0,48,57,2,0,9,10,12,13,3,0,65,90,95,
  	95,97,122,4,0,48,57,65,90,95,95,97,122,77,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,
  	0,0,17,1,0,0,0,0,19,1,0,0,0,1,21,1,0,0,0,3,25,1,0,0,0,5,27,1,0,0,0,7,
  	29,1,0,0,0,9,31,1,0,0,0,11,34,1,0,0,0,13,36,1,0,0,0,15,49,1,0,0,0,17,
  	53,1,0,0,0,19,67,1,0,0,0,21,22,7,0,0,0,22,23,1,0,0,0,23,24,6,0,0,0,24,
  	2,1,0,0,0,25,26,5,61,0,0,26,4,1,0,0,0,27,28,5,60,0,0,28,6,1,0,0,0,29,
  	30,5,59,0,0,30,8,1,0,0,0,31,32,5,43,0,0,32,33,5,43,0,0,33,10,1,0,0,0,
  	34,35,5,41,0,0,35,12,1,0,0,0,36,37,5,102,0,0,37,38,5,111,0,0,38,39,5,
  	114,0,0,39,43,1,0,0,0,40,42,7,1,0,0,41,40,1,0,0,0,42,45,1,0,0,0,43,41,
  	1,0,0,0,43,44,1,0,0,0,44,46,1,0,0,0,45,43,1,0,0,0,46,47,5,40,0,0,47,14,
  	1,0,0,0,48,50,7,2,0,0,49,48,1,0,0,0,50,51,1,0,0,0,51,49,1,0,0,0,51,52,
  	1,0,0,0,52,16,1,0,0,0,53,54,5,112,0,0,54,55,5,114,0,0,55,56,5,105,0,0,
  	56,57,5,110,0,0,57,58,5,116,0,0,58,62,1,0,0,0,59,61,7,3,0,0,60,59,1,0,
  	0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,65,1,0,0,0,64,62,1,0,
  	0,0,65,66,5,40,0,0,66,18,1,0,0,0,67,71,7,4,0,0,68,70,7,5,0,0,69,68,1,
  	0,0,0,70,73,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,20,1,0,0,0,73,71,1,
  	0,0,0,5,0,43,51,62,71,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mygrammarlexerLexerStaticData = staticData.release();
}

}

MyGrammarLexer::MyGrammarLexer(CharStream *input) : Lexer(input) {
  MyGrammarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mygrammarlexerLexerStaticData->atn, mygrammarlexerLexerStaticData->decisionToDFA, mygrammarlexerLexerStaticData->sharedContextCache);
}

MyGrammarLexer::~MyGrammarLexer() {
  delete _interpreter;
}

std::string MyGrammarLexer::getGrammarFileName() const {
  return "MyGrammar.g4";
}

const std::vector<std::string>& MyGrammarLexer::getRuleNames() const {
  return mygrammarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MyGrammarLexer::getChannelNames() const {
  return mygrammarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MyGrammarLexer::getModeNames() const {
  return mygrammarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MyGrammarLexer::getVocabulary() const {
  return mygrammarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MyGrammarLexer::getSerializedATN() const {
  return mygrammarlexerLexerStaticData->serializedATN;
}

const atn::ATN& MyGrammarLexer::getATN() const {
  return *mygrammarlexerLexerStaticData->atn;
}




void MyGrammarLexer::initialize() {
  ::antlr4::internal::call_once(mygrammarlexerLexerOnceFlag, mygrammarlexerLexerInitialize);
}

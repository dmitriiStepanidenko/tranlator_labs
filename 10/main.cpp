#include "MyGrammarBaseListener.h"
#include "MyGrammarBaseVisitor.h"
#include "MyGrammarLexer.h"
#include "MyGrammarParser.h"
#include <ANTLRInputStream.h>
#include <antlr4-runtime.h>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

struct Symbol {
  int value;
};

std::unordered_map<std::string, Symbol *> hashtable;

// class MyGrammarListener : public antlr4::tree::ParseTreeListener {};
class Listener : public MyGrammarBaseListener {
  void exitStatement(MyGrammarParser::StatementContext *ctx) override {
    if (ctx->iden_numconst() != nullptr) {
      auto identifier = ctx->iden_numconst()->IDENTIFIER();
      if (identifier != nullptr)
        if (hashtable.find(identifier->getText()) == hashtable.end()) {
          throw std::runtime_error("Reference unknow identifier in print");
        }
    }
  }

  void exitFunction(MyGrammarParser::FunctionContext *ctx) override {
    auto identifiers = ctx->IDENTIFIER();
    auto identifier = identifiers[0];
    for (auto i : identifiers) {
      if (i->getText() != identifier->getText()) {
        throw std::runtime_error("Different identifiers in for loop");
      }
    }
    Symbol *s = new Symbol();
    if (hashtable.find(identifier->getText()) != hashtable.end())
      throw std::runtime_error("Identifier already exists");
    hashtable[identifier->getText()] = s;

    auto iden_numconsts = ctx->iden_numconst();
    for (auto i : iden_numconsts) {
      auto identifier = i->IDENTIFIER();
      if (identifier != nullptr)
        if (hashtable.find(identifier->getText()) == hashtable.end()) {
          throw std::runtime_error("Reference unknown identifier in for loop");
        }
    }
  }
};

int getValueFromIdenNumconst(
    MyGrammarParser::Iden_numconstContext *iden_numconst) {
  if (iden_numconst->IDENTIFIER() != nullptr) {
    return hashtable[iden_numconst->IDENTIFIER()->getText()]->value;
  }
  return std::stoi(iden_numconst->NUMCONST()->getText());
}

class Visitor : public MyGrammarBaseVisitor {
  std::any visitStatement(MyGrammarParser::StatementContext *ctx) override {
    if (ctx->function() == nullptr) {
      int value = getValueFromIdenNumconst(ctx->iden_numconst());
      this->visitIden_numconst(ctx->iden_numconst());
      std::cout << value << ";";
      return std::any();
    }
    return this->visitFunction(ctx->function());
  }
  std::any visitFunction(MyGrammarParser::FunctionContext *ctx) override {
    auto identifier = ctx->IDENTIFIER(0);
    if (identifier == nullptr) {
      throw std::runtime_error("identifier == nulptr in vivistFunction");
    }

    auto symbol = hashtable[identifier->getText()];
    if (symbol == nullptr) {
      throw std::runtime_error("symbol == nulptr in vivistFunction");
    }

    int initial_value = getValueFromIdenNumconst(ctx->iden_numconst(0));
    this->visitIden_numconst(ctx->iden_numconst(0));
    symbol->value = initial_value;

    int less_value = getValueFromIdenNumconst(ctx->iden_numconst(1));

    while (symbol->value < less_value) {
      this->visitIden_numconst(ctx->iden_numconst(1));
      this->visitStatement(
          (MyGrammarParser::StatementContext *)(ctx->parent->children[1]));
      symbol->value++;

      less_value = getValueFromIdenNumconst(ctx->iden_numconst(1));
    }
    this->visitIden_numconst(ctx->iden_numconst(1));

    // symbol->value = 0;
    return std::any();
  }
  std::any
  visitIden_numconst(MyGrammarParser::Iden_numconstContext *ctx) override {
    if (ctx->IDENTIFIER() != nullptr) {
      if (ctx->opt_plus() != nullptr) {
        if (ctx->opt_plus()->INCREMENT() != nullptr)
          hashtable[ctx->IDENTIFIER()->getText()]->value++;
      }
    }
    return visitChildren(ctx);
  }
  // std::any visitOpt_plus(MyGrammarParser::Opt_plusContext *ctx) override {
  //   return visitChildren(ctx);
  // }
};

int exec(antlr4::tree::ParseTree *tree) {
  // tree->children;
  Visitor *visitor = new Visitor();
  std::cout << "\n\n";
  visitor->visit(tree);
  std::cout << "\n\n";
  return 0;
}

int main(int argc, const char *argv[]) {
  std::ifstream stream;
  if (argc > 1) {
    stream.open(argv[1]);
    std::cout << argv[1] << std::endl;
  } else {
    stream.open("../testfile.test");
  }
  antlr4::ANTLRInputStream input(stream);

  MyGrammarLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  MyGrammarParser parser(&tokens);
  Listener listener;
  parser.addParseListener(&listener);

  antlr4::tree::ParseTree *tree = parser.statement();

  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

  return exec(tree);
}

#ifndef MATCHER_HPP
#define MATCHER_HPP

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "MatchHandler.hpp"

using namespace clang::ast_matchers;

class ContainerVarDeclCallback : public MatchFinder::MatchCallback {
private:
  MatchHandler match_handler;

public:
  void run(const MatchFinder::MatchResult &result) override;
  MatchHandler &getMatchHandler();

  ~ContainerVarDeclCallback() override = default;
};

void registerMatcher(MatchFinder *finder, ContainerVarDeclCallback *callback,
                     std::string container);

#endif // MATCHER_HPP
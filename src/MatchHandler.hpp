#ifndef MATCH_HANDLER_HPP
#define MATCH_HANDLER_HPP

#include "ContainerMatch.hpp"
#include <vector>

class MatchHandler {
private:
  std::vector<ContainerMatch> matches;

public:
  MatchHandler() {}

  void addMatch(ContainerMatch match);
  std::vector<ContainerMatch> getMatches();
  ContainerMatch *chooseContainer();
};

#endif // MATCH_HANDLER_HPP
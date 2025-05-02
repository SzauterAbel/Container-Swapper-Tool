#include "MatchHandler.hpp"
#include "Log.hpp"
#include <sstream>

void MatchHandler::addMatch(ContainerMatch match) { matches.push_back(match); }

std::vector<ContainerMatch> MatchHandler::getMatches() { return matches; }

static int chooseOption(int min, int max) {
  std::string input;
  std::getline(std::cin, input);

  std::stringstream ss(input);
  int choice;
  if (ss >> choice && ss.eof() && choice >= min && choice <= max) {
    return choice;
  } else {
    return -1;
  }
}

ContainerMatch *MatchHandler::chooseContainer() {
  std::cout << "Choose a variable to swap its type:\n0. Exit\n";
  for (int i = 0; i < matches.size(); ++i) {
    std::cout << i + 1 << ". " << matches.at(i).toString() << "\n";
  }
  int result = chooseOption(0, matches.size());
  if (result == -1) {
    log_error("Invalid option");
    return nullptr;
  }
  if (result == 0) {
    return nullptr;
  }
  return &matches.at(result - 1);
}
#include <CLI/CLI.hpp>
#include <iostream>

#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CompilationDatabase.h"
#include "clang/Tooling/Tooling.h"

#include "Checker.hpp"
#include "Config.hpp"
#include "Log.hpp"

int main(int argc, char **argv) {
  CLI::App app{"Container Swapper Tool"};

  bool verbose = false;
  std::string mode_string{};
  std::vector<std::string> files;

  app.add_flag("-v,--verbose", verbose, "Verbose mode");
  app.add_option("-m,--mode", mode_string,
                 "Modes of the tool: map-to-unordered-map, "
                 "unordered-map-to-map, set-to-unordered-set, "
                 "unordered-set-to-set, list-to-vector, vector-to-list");
  app.add_option("files", files, "Input files to check");

  CLI11_PARSE(app, argc, argv);

  Mode mode = getModeFromString(mode_string);
  if (mode == MISSING) {
    log_error("Missing mode! Please provide a mode (check -h or --help)");
    return 1;
  }
  if (mode == UNKNOWN) {
    log_error("Unkown mode: {}", mode_string);
    return 2;
  }
  Config::getInstance()->setMode(mode);
  Config::getInstance()->setVerbose(verbose);
  Config::getInstance()->setSourceFiles(std::move(files));

  ContainerVarDeclCallback callback;
  MatchFinder match_finder;
  registerMatcher(&match_finder, &callback,
                  getModeSource(Config::getInstance()->getMode()));

  clang::tooling::FixedCompilationDatabase Compilations(".", {"-std=c++20"});
  clang::tooling::ClangTool MatcherTool(
      Compilations, Config::getInstance()->getSourceFiles());

  std::unique_ptr<clang::tooling::FrontendActionFactory> factory =
      clang::tooling::newFrontendActionFactory(&match_finder);
  int result = MatcherTool.run(factory.get());
  if (result != 0) {
    log_error("Cannot search, something was wrong");
    return 3;
  }

  MatchHandler match_handler = callback.getMatchHandler();
  if (match_handler.getMatches().size() == 0) {
    log_error("Cannot find any container");
    return 4;
  }
  ContainerMatch *container = match_handler.chooseContainer();
  if (container == nullptr) {
    return 5;
  }

  return 0;
}
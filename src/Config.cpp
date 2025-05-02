#include "Config.hpp"

Config *Config::instancePtr = nullptr;

Config *Config::getInstance() {
  if (instancePtr == nullptr) {
    instancePtr = new Config();
  }
  return instancePtr;
}

bool Config::getVerbose() { return verbose; }

Mode Config::getMode() { return mode; }

std::vector<std::string> &Config::getSourceFiles() { return source_files; }

void Config::setVerbose(bool v) { verbose = v; }

void Config::setMode(Mode m) { mode = m; }

void Config::setSourceFiles(std::vector<std::string> files) {
  source_files = std::move(files);
}
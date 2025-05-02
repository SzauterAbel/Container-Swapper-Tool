#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "Mode.hpp"
#include <iostream>
#include <vector>

class Config {
private:
  bool verbose;
  Mode mode;
  std::vector<std::string> source_files;

  static Config *instancePtr;
  Config() {}

public:
  Config(const Config &obj) = delete;
  static Config *getInstance();

  bool getVerbose();
  Mode getMode();
  std::vector<std::string> &getSourceFiles();

  void setVerbose(bool v);
  void setMode(Mode m);
  void setSourceFiles(std::vector<std::string> files);
};

#endif // CONFIG_HPP
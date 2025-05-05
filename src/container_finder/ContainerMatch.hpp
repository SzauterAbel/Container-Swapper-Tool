#ifndef CONTAINER_MATCH_HPP
#define CONTAINER_MATCH_HPP

#include <iostream>

class ContainerMatch {
private:
  std::string var_name;
  std::string type;
  std::string decl_file;
  int decl_file_row;

public:
  ContainerMatch(std::string var_name, std::string type, std::string decl_file,
                 int decl_file_row)
      : var_name(var_name), type(type), decl_file(decl_file),
        decl_file_row(decl_file_row) {}

  std::string getVarName();
  std::string getType();
  std::string getDeclFile();
  int getDeclFileRow();
  std::string toString();
};

#endif // CONTAINER_MATCH_HPP
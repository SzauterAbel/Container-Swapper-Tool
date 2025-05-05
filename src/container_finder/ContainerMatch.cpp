#include "ContainerMatch.hpp"

std::string ContainerMatch::getVarName() { return var_name; }

std::string ContainerMatch::getType() { return type; }

std::string ContainerMatch::getDeclFile() { return decl_file; }

int ContainerMatch::getDeclFileRow() { return decl_file_row; }

std::string ContainerMatch::toString() {
  return type + " " + var_name + " in " + decl_file + ":" +
         std::to_string(decl_file_row) + "\n";
}

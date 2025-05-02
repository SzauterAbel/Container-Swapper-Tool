#ifndef MODE_HPP
#define MODE_HPP

#include <iostream>

enum Mode {
  UNORDERED_SET_TO_SET,
  SET_TO_UNORDERED_SET,
  UNORDERED_MAP_TO_MAP,
  MAP_TO_UNORDERED_MAP,
  LIST_TO_VECTOR,
  VECTOR_TO_LIST,
  MISSING,
  UNKNOWN
};

Mode getModeFromString(std::string mode);
std::string getModeSource(Mode mode);

#endif // MODE_HPP
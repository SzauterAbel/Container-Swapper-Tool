#include "Mode.hpp"

Mode getModeFromString(std::string mode) {
  if ("map-to-unordered-map" == mode) {
    return MAP_TO_UNORDERED_MAP;
  }
  if ("unordered-map-to-map" == mode) {
    return UNORDERED_MAP_TO_MAP;
  }
  if ("set-to-unordered-set" == mode) {
    return SET_TO_UNORDERED_SET;
  }
  if ("unordered-set-to-set" == mode) {
    return UNORDERED_SET_TO_SET;
  }
  if ("list-to-vector" == mode) {
    return LIST_TO_VECTOR;
  }
  if ("vector-to-list" == mode) {
    return VECTOR_TO_LIST;
  }
  if ("" == mode) {
    return MISSING;
  }
  return UNKNOWN;
}

std::string getModeSource(Mode mode) {
  switch (mode) {
  case MAP_TO_UNORDERED_MAP:
    return "map";
  case UNORDERED_MAP_TO_MAP:
    return "unordered_map";
  case SET_TO_UNORDERED_SET:
    return "set";
  case UNORDERED_SET_TO_SET:
    return "unordered_set";
  case LIST_TO_VECTOR:
    return "list";
  case VECTOR_TO_LIST:
    return "vector";
  default:
    return "";
  }
}
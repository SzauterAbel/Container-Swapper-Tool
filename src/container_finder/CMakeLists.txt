include_guard()

set(CONTAINER_FINDER Checker.cpp ContainerMatch.cpp MatchHandler.cpp)

add_library(container_finder ${CONTAINER_FINDER})

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

target_include_directories(container_finder PUBLIC ${LLVM_INCLUDE_DIRS})

target_link_libraries(
  container_finder
  PUBLIC clangTooling
         clangFrontend
         clangAST
         clangASTMatchers
         clangToolingCore
         clangSerialization
         clangBasic
  PRIVATE utils)
target_include_directories(container_finder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

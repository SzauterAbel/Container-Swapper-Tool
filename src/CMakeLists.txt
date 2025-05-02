cmake_minimum_required(VERSION 3.11)
project(container_swapper_tool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")

include(FetchContent)

FetchContent_Declare(
  CLI11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG v2.3.2)

FetchContent_MakeAvailable(CLI11)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.11.0)

FetchContent_MakeAvailable(spdlog)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

set(SOURCE main.cpp Config.cpp Checker.cpp ContainerMatch.cpp MatchHandler.cpp
           Mode.cpp)

add_executable(container_swapper_tool ${SOURCE})

target_link_libraries(
  container_swapper_tool
  PRIVATE CLI11::CLI11
          spdlog::spdlog
          clangTooling
          clangFrontend
          clangAST
          clangASTMatchers
          clangToolingCore
          clangSerialization
          clangBasic)

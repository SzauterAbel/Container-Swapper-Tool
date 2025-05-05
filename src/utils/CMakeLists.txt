include_guard()

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

set(UTILS Config.cpp Mode.cpp)
add_library(utils ${UTILS})

target_link_libraries(utils PUBLIC CLI11::CLI11 spdlog::spdlog)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

cmake_minimum_required(VERSION 3.11)
project(container_swapper_tool)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")

add_subdirectory(utils)
add_subdirectory(container_finder)

add_executable(container_swapper_tool main.cpp)

target_link_libraries(container_swapper_tool PRIVATE container_finder utils)

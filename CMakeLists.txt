cmake_minimum_required(VERSION 3.15)
project(RecursionExmples)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 14)
find_package(SFML COMPONENTS system window graphics REQUIRED)


add_executable(RecursionExmples main.cpp)
target_link_libraries(RecursionExmples sfml-system sfml-window sfml-graphics)
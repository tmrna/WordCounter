# Rob Deans
# Lab 2
# 2/2/2023

cmake_minimum_required(VERSION 3.18)
project(word_counter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib)

add_executable(word_counter wordCounter.cpp)

target_link_libraries(word_counter WordList Lexer)

enable_testing()

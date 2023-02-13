# Rob Deans
# Lab 2
# 2/2/2023


add_subdirectory(Lexer)
add_subdirectory(WordList)
add_executable(testRead test/testRead.cpp)
target_link_libraries(testRead Lexer WordList)
add_test(NAME testRead COMMAND testRead)
enable_testing()

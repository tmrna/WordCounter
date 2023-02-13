# Rob Deans
# Lab 2
# 2/2/2023

add_library(Lexer
            Lexer.hpp
            Lexer.cpp
            )



macro(genTest TEST)

  add_executable(Lexer_${TEST} "test/Lexer_${TEST}.cpp")
  target_link_libraries(Lexer_${TEST} Lexer)
  add_test(NAME Lexer_${TEST} COMMAND Lexer_${TEST})

endmacro()

genTest(testHello)
genTest(testLexer)

enable_testing()

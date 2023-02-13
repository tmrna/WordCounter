/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include <cassert>
#include <iostream>
#include <fstream>
#include "../Lexer.hpp"

int main(){

  std::ofstream hello("hello.txt");
  hello.clear();
  hello << "Hello World!!!!";
  hello.close();
  Lexer test("hello.txt");
  assert(test.readable());
  while(!test.eof()){
    if(test.fetchNextWord()){
      std::cout << test.getWord() << std::endl;
    }
  }
}

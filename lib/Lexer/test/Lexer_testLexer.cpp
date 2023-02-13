/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include <cmath>
#include <iostream>
#include <cassert>
#include "../Lexer.hpp"
#include <fstream>
#include <vector>

int main(){
  std::ofstream testFile("test.txt");
  testFile.clear();
  for(int i = 0; i < 250000; ++i){
    testFile << char(32 + i % 94);
  }
  testFile.close();
  Lexer file("test.txt");
  assert(file.readable());
  std::vector<std::string> words;
  while(!file.eof()){
    file.fetchNextWord();
    words.push_back(file.getWord());
  }
}

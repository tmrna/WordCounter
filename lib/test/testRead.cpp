/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "../Lexer/Lexer.hpp"
#include "../WordList/WordList.hpp"
#include <fstream>
#include <iostream>
#include <cassert>

int main(){
  std::ofstream writtenFile ("tstFile.txt");

  writtenFile.clear();

  writtenFile << "this is a test, long form....." << std::endl;

  for(int i = 0; i < 100; ++i){
    if(i % 2 == 0) writtenFile << "hello World!" << std::endl;
    if(i % 3 == 0) writtenFile << "                                     filler";
    if(i%5) writtenFile << "testingOnMultOfFive";
  }

  writtenFile.close();

  Lexer read("tstFile.txt");
  assert(read.readable());
  WordList lst;
  while(!read.eof()){
    read.fetchNextWord();
    lst.addWord(read.getWord());
  }
  lst.print();
  Lexer longRead("Lexer/test.txt");
  while(!longRead.eof()){
    longRead.fetchNextWord();
    lst.addWord(longRead.getWord());
  }
  lst.print();
}

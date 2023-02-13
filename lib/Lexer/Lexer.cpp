/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "Lexer.hpp"
#include <cctype>
#include <iostream>
Lexer::~Lexer(){
  if(file_.is_open()) file_.close();
}

// if the file_ is unreadable then for all practical purposes we have reached the end
bool Lexer::eof(){
  if(!file_.is_open()) return true;
  return file_.eof();
}

// overloaded assignment does not preserve place in the file!
Lexer& Lexer::operator=(const Lexer & rhs){
  path = rhs.path;
  file_.open(path);
  word = rhs.word;
  letter = rhs.letter;
  return *this;
  
}

// returns if the current file_ is readable
bool Lexer::readable(){
  return file_.is_open();
}

// returns if the file_ at the given path is readable
bool Lexer::readable(const std::string& designatedPath){
  Lexer tester(designatedPath);
  // no need to close, handled by dtor
  return tester.readable();
}

bool Lexer::fetchNextChar(){
  if(!readable() || eof()) return false;
  
  file_.get(letter);
  // returns true if not a number, whitespace or punctuation. 
  return std::isalnum(letter) != 0;
}

bool Lexer::fetchNextWord(){
  // clear current word
  word = "";

  while(fetchNextChar()){
    word += letter;
  }

  return word != "";
}

std::string Lexer::getWord(){
  return word;
}

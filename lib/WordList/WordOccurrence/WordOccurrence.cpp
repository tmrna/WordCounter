/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "WordOccurrence.hpp"

// cpy ctor and dtor -----------------------------------------------

WordOccurrence::~WordOccurrence(){}

WordOccurrence::WordOccurrence(const WordOccurrence& rhs){
  *this = rhs;
}

// overloaded assignment -------------------------------------------

WordOccurrence& WordOccurrence::operator=(const WordOccurrence& rhs){
  word_ = rhs.word_;
  num_ = rhs.num_;
  return *this;
}


// accessors -------------------------------------------------------

int WordOccurrence::getNum() const{
  return num_;
}

std::string WordOccurrence::getWord() const{
  return word_;
}

bool WordOccurrence::matchWord(const std::string& givenStr) const{
  return givenStr == word_;
}

bool WordOccurrence::operator==(const WordOccurrence & rhs) const{
  return num_ == rhs.num_ && word_ == rhs.word_;
}

bool WordOccurrence::operator!=(const WordOccurrence & rhs) const{
  return !(*this == rhs);
}

// mutators -------------------------------------------------------

void WordOccurrence::increment(){
  ++num_;
}

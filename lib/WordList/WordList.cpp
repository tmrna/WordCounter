/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "WordList.hpp"

// dtor, overloaded assignment, cpy ctor ---------------------------------

//                    overloaded assignment
//---------------------------------------------------------------------
//
WordList& WordList::operator=(const WordList & rhs){
  wordArray_ = rhs.wordArray_;
  return *this;
}

//                    ctor
//--------------------------------------------------------------------
//            
WordList::WordList(const WordList & rhs){
  *this = rhs;
}


// comparison at position -----------------------------------------

//                        match
//------------------------------------------------------------------
//

// returns if the word at the given position matches
bool WordList::match(int pos, const std::string & givenStr) const{
  return wordArray_[pos].getWord() == givenStr;
}

//                      check neighbor
//-----------------------------------------------------------
//

//--------------------------LEFT-----------------------------

// checks if current element needs moved to the left
bool WordList::checkNeighborLeft(int pos) const{

  // we can't access left so return false, no reorder is possible
  if(pos == 0){
    return false;
  }
  // check if we need to reorder
  return wordArray_[pos - 1].getNum() < wordArray_[pos].getNum();
}

//-----------------------RIGHT------------------------------

// checks if the current element needs moved to the right
bool WordList::checkNeighborRight(int pos) const{

  // we can't access above size() - 1, so return false
  if(pos == size() - 1) return false;

  // check if we need to reorder
  return wordArray_[pos + 1].getNum() > wordArray_[pos].getNum();
}

// adding words ---------------------------------------------

//                            addOne
//-----------------------------------------------------------
//

// increments the current element and then re-arranges if neccessary
void WordList::addOne(int loc){
  // increment the element
  wordArray_[loc].increment();
  // check if we need to move the element to the left
  // if we do, move until we are in the correct region
  while(checkNeighborLeft(loc)){
    wordArray_.swap(loc, loc - 1);
    --loc;
  }
  // check if we need to move to the right
  while(checkNeighborRight(loc)){
    wordArray_.swap(loc, loc - 1);
    ++loc;
  }
}

//                      addWord
//-----------------------------------------------------------
//

// adds an Occurrence of the word. if the string is empty does nothing.
void WordList::addWord(const std::string & givenStr){

  if(givenStr == "") return;

  // iterate through and check for a match
  for(int left = 0, right = size() - 1; left <= right; ++left, --right){

    // if we find a match increment and re-arrange if neccessary
    if(match(left, givenStr)){
      addOne(left);
      return;
    }
    if(match(right, givenStr)){
      addOne(right);
      return;
    }
  }

  // no match was found, push a new element.
  wordArray_.push(WordOccurrence(givenStr));
}

// checking if two lists are equal

// iterates through both lists and checks if there is a match
// if size differs returns false
bool equal(const WordList & lhs, const WordList & rhs){
  if(lhs.size() == rhs.size()){
    for(int i = 0; i < rhs.size(); ++i){

      if(lhs.wordArray_[i] != rhs.wordArray_[i]){
        return false;
      }
    }
    return true;
  }
  return false;
}

// prints from the end of the list to the beginning
// as lowest counts are at the end
void WordList::print() const{
  WordList prt(*this);
  std::cout << std::endl; 
  for(int i = size() - 1; i < size(); --i){
      std::cout << "Occurrences : " << prt.wordArray_[i].getNum()
                << "  of word : " << '"'<<prt.wordArray_[i].getWord()<<'"' << std::endl;
  }

  std::cout << std::endl;
}

// returns the size of the array
unsigned WordList::size() const{
  return wordArray_.size();
}

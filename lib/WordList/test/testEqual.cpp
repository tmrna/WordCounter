/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "../WordList.hpp"
#include <cassert>
int main(){
  WordList test1;
  WordList test2;
  test1.addWord("hello");
  test1.addWord("world");
  test2.addWord("hello");
  test2.addWord("world");
  assert(equal(test1, test2));
}

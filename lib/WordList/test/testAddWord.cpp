/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "../WordList.hpp"
#include <cassert>
int main() {
  WordList testList;
  testList.addWord("this");
  testList.addWord("is");
  testList.addWord("a");
  testList.addWord("test");
  testList.addWord("this");
  testList.addWord("is");
  testList.addWord("a");
  testList.addWord("test");  testList.print();
}

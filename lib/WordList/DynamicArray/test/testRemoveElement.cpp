/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#include "../DynamicArray.hpp"
#include <iostream>
int main() {
  DynamicArray<int> stuff;
  for(int i = 0; i < 100; ++i){
    stuff.push(i);
  }
  while(stuff.remove(4));
  for(int i = 0; i < stuff.size(); ++i){
    std::cout << stuff[i] << std::endl;
  }
  while(stuff.remove(0));
  for(int i = 0; i < stuff.size(); ++i){
    std::cout << stuff[i];
  }
}

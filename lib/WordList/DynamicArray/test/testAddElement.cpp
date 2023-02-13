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
  DynamicArray<int> nums;
  for(int i = 0, j = 329; i < 20; ++i, ++j){
    nums.push(i);
    nums.push(j);
  }
 for(int i = 0; i < nums.size(); ++i){
    std::cout << nums[i] << std::endl;
  }
}

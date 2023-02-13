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
  for(int i = 0; i < 20; ++i){
    nums.push(i);
  }
  nums.insert(3, 2000);
  for(int i = 0; i < nums.size(); ++i){
    std::cout << nums[i] << std::endl;
  }
}

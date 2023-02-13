#include <string>
#include <fstream>
#include <iostream>

#include "lib/Lexer/Lexer.hpp"
#include "lib/WordList/WordList.hpp"

int main(int argc, char* argv[]){

  if(argc != 2){
    std::cout << "Need to supply one relative file path" << std::endl;
    return 1;
  }

  else{
    Lexer reader(argv[1]);
    if(!reader.readable()){
      std::cout << "failed to read file " << argv[1] << std::endl;
      return 1;
    }
    WordList listing;
    while(!reader.eof()){
      reader.fetchNextWord();
      listing.addWord(reader.getWord());
    }
    std::cout << "printing counts for file: " << argv[1] << std::endl;
    listing.print();
  }
  return 0;
}

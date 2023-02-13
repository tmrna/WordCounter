/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#ifndef Lexer_HPP
#define Lexer_HPP

#include <fstream>
#include <string>

class Lexer{
  private:
    std::ifstream file_;
    std::string path;

    std::string word;
    char letter;

  public:

    Lexer(const std::string& filePath = "") : path(filePath), word(""), letter('\0'){if(path != "") file_.open(path);}
    
    // closes file_
    ~Lexer();

    Lexer(const Lexer&);

    Lexer& operator=(const Lexer&);

    // opens new file_ at designated path, returns false if unopenable 
    bool setPath(const std::string&);

    // returns if the current file_ is open
    bool readable();

    // returns if the file_ at the given path is openable 
    bool readable(const std::string&);

    // returns if we have reached eof
    bool eof();

    // if we have reached eof return false
    bool fetchNextChar();

    // if eof returns false, otherwise reads till end of next word and stores
    bool fetchNextWord();

    // returns current word that has been parsed
    std::string getWord();

};

#endif

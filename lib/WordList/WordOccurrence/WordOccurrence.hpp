/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#ifndef WORDOCCURRENCE_HPP
#define WORDOCCURRENCE_HPP

#include <string>


class WordOccurrence {
public:
    WordOccurrence(const std::string& word="", int num=1): word_(word), num_(num){}
    ~WordOccurrence();
    WordOccurrence(const WordOccurrence&);
    WordOccurrence& operator=(const WordOccurrence&);

    bool matchWord(const std::string &) const; // returns true if word matches stored
    void increment(); // increments number of occurrences
    std::string getWord() const; 
    int getNum() const;

    bool operator==(const WordOccurrence &) const;
    bool operator!=(const WordOccurrence &) const;
private:
    std::string word_;
    int num_;
};

#endif

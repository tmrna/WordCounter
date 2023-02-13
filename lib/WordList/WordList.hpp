/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#ifndef WORDLIST_HPP
#define WORDLIST_HPP

#include <string>
#include <iostream>

#include "DynamicArray/DynamicArray.hpp"
#include "WordOccurrence/WordOccurrence.hpp"


class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList(int size = 0): wordArray_(size) {}
    ~WordList(){/*handled by DynamicArray and WordOccurrence*/}
    WordList& operator=(const WordList &);
    WordList(const WordList &);

    bool match(int, const std::string &) const;

    // implement comparison as friend
    friend bool equal(const WordList &, const WordList &);

    void addWord(const std::string &);
    void print() const;
    unsigned size() const;

private:
    DynamicArray<WordOccurrence> wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    bool checkNeighborLeft(int) const;
    bool checkNeighborRight(int) const;
    void addOne(int);
};

#endif

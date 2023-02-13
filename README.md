# WordCounter
WordCounter assignment csIII 2022

# Assignment requirements
No use of stl containers, WordList must contain a dynamically allocated array.

# Initially given

```c++
/class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const; 
    int getNum() const;

private:
    string word_;
    int num_;
};

```
and
```c++
/class WordList{
public:
    // add copy constructor, destructor, overloaded assignment

    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &);
    void print();
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};
```

required to pass lib/WordList/test/testWordList.cpp 

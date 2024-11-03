#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "BST.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Dictionary {
private:
    vector<BST<string>> bstArray; // Array of 36 BSTs (26 letters + 10 digits)

    int getIndex(char c) const; // Helper to get index from character
    string toLower(const string &word) const; // Helper to convert words to lowercase
    int hammingDistance(const string &a, const string &b) const; // Helper to calculate Hamming Distance



public:
    // Constructor
    Dictionary();

    // Read "corpus.txt" to build the dictionary directly using BSTs
    void buildDictionary();

    // Save the BST dictionary to "dictionary.txt"
    void saveDictionaryToDisk();

    // Spell check using a local "input.txt" file next to the class
    void spellCheck();

    // Add or remove words from dictionary
    void addWord(const string &word);
    void removeWord(const string &word);

    // Helper to get the closest words for suggestions
    vector<string> getClosestWords(const string &word);

    // New helper methods for testing >>Mohamed<<
    bool containsWord(const std::string& word);
    bool isWordInBST(char c, const std::string& word);
};

#endif // DICTIONARY_H
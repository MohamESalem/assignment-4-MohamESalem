/********************************************************************************
 * WARNING: Please do not remove or modify this comment block.
 *
 * Student Information:
 * Name: Mohammed Salem
 * Student ID: 900232609
 * Section Number: 2
 *
 * Instructions:
 * - Fill out your name, student ID, and section number above.
 * - This information is mandatory for the submission of your assignment.
 * - Do not modify this file beyond the specified tasks and guidelines.
 *
 ********************************************************************************/

#include "Dictionary.h"
#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

// Helper: Convert character to index (0-35)
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
int Dictionary::getIndex(char c) const {
    if (isdigit(c)) return c - '0' + 26; // '0' -> 26, '1' -> 27, ..., '9' -> 35
    if (isalpha(c)) return tolower(c) - 'a'; // 'a' -> 0, ..., 'z' -> 25
    return -1;
}

// Helper: Convert word to lowercase
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
string Dictionary::toLower(const string &word) const {
    string lowerWord = word;
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
    return lowerWord;
}

// Student Task: Implement the hammingDistance function (Private Helper)
// hammingDistance: Calculates the Hamming Distance between two strings `a` and `b`
// This function should determine how different two strings are by comparing their characters one by one.
// Think about how to handle strings of different lengths and how you might count the mismatched characters.
// Consider the significance of Hamming Distance in finding similar or different strings.
int Dictionary::hammingDistance(const string &a, const string &b) const {
    // Student Task: Implement the hammingDistance function

    size_t LA = a.length();
    size_t LB = b.length();
    size_t minLength = min(LA, LB);

    int matches = 0;

    for (size_t i = 0; i < minLength; ++i) {
        if (a[i] == b[i]) {
            ++matches;
        }
    }

    int distance = max(LA, LB) - matches;

    return distance;
    // : Compare the characters of `a` and `b` to determine how many are different.
    // : Think about how to handle cases where the strings are not the same length.
}

// Constructor
Dictionary::Dictionary() : bstArray(36) {}

// Build Dictionary from "corpus.txt" Located Next to Class Files
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
void Dictionary::buildDictionary() {
    string corpusFile = "../Code_lib/corpus.txt"; // Define the file name to look for
    ifstream infile(corpusFile);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open corpus file '" << corpusFile << "'." << endl;
        return;
    }

    string line, word;
    while (getline(infile, line)) {
        stringstream ss(line);
        while (ss >> word) {
            // Clean and convert to lowercase before storing
            word = toLower(word);
            int index = getIndex(word[0]);
            if (index != -1) {
                // Insert the word into the corresponding BST directly
                bstArray[index].insert(word);
            }
        }
    }

    cout << "Dictionary built successfully from " << corpusFile << "." << endl;
}

// Save the BST Dictionary to "dictionary.txt"
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
void Dictionary::saveDictionaryToDisk() {
    ofstream outfile("../Code_lib/dictionary.txt");
    if (!outfile.is_open()) {
        cerr << "Error: Unable to open output file 'dictionary.txt'." << endl;
        return;
    }

    for (int i = 0; i < 36; ++i) {
        outfile << "BST #" << i << endl;

        // Redirect output of traverse to stringstream
        stringstream ss;
        streambuf* oldCoutBuf = cout.rdbuf(); // Save the current buffer of cout
        cout.rdbuf(ss.rdbuf()); // Redirect cout to the stringstream

        // Call the traverse method (which outputs to cout)
        bstArray[i].traverse();

        cout.rdbuf(oldCoutBuf); // Restore the original cout buffer

        // Write the captured output to the file
        string word;
        while (getline(ss, word)) {
            if (!word.empty()) {
                outfile << word << endl;
            }
        }

        outfile << endl; // Separate each BST with a newline
    }

    cout << "Dictionary saved successfully to 'dictionary.txt'." << endl;
}

// Student Task: Implement the addWord function
// addWord: Adds a new `word` to the appropriate Binary Search Tree (BST) in the dictionary
// This function should make use of helper functions to correctly add the word:
// - Use `getIndex` to find out which BST corresponds to the first character of the `word`.
// - Use `toLower` to ensure the word is stored in a case-insensitive manner.
// - Use the `insert` function to add the word to the identified BST.
// Consider how each of these functions can work together to efficiently add the word to the dictionary.
void Dictionary::addWord(const string &word) {
    // Student Task: Implement the addWord function
    string lowerWord = toLower(word);
    int num = getIndex(lowerWord[0]);
    bstArray[num].insert(lowerWord);
    // : Use `getIndex` to determine which BST corresponds to the first character of `word`.
    // : Convert `word` to lowercase using `toLower` to maintain consistency.
    // : Use the `insert` method to add the lowercase word to the appropriate BST.
}

// Student Task: Implement the removeWord function
// removeWord: Removes a specific `word` from the appropriate Binary Search Tree (BST) in the dictionary
// This function should make use of helper functions to correctly locate and remove the word:
// - Use `getIndex` to determine which BST corresponds to the first character of `word`.
// - Use `toLower` to ensure the word is handled in a case-insensitive manner when removing it.
// - Use the `remove` function from the appropriate BST to delete the word.
// Think about how these helper functions can be combined to efficiently remove the word from the dictionary.
void Dictionary::removeWord(const string &word) {
    // Student Task: Implement the removeWord function
    string lowerWord = toLower(word);
    int num = getIndex(lowerWord[0]);
    bstArray[num].remove(lowerWord);
    // : Use `getIndex` to find out which BST corresponds to the first character of `word`.
    // : Convert `word` to lowercase using `toLower` for consistent handling.
    // : Use the `remove` method to delete the word from the identified BST.
}

// Student Task: Implement the core part of the spellCheck function
// spellCheck: Reads words from a local "input.txt" file and checks if they are present in the dictionary
// This function should help identify misspelled words and provide suggestions for correction.
// Consider how to use existing helper functions to determine if a word is correctly spelled:
// - Use `toLower` to ensure the word is handled in a case-insensitive manner.
// - Use `getIndex` to find out which BST corresponds to the first character of the word.
// - Use the `search` function to check if the word is present in the appropriate BST.
// - If the word is misspelled, call `getClosestWords` to suggest corrections and display them.
void Dictionary::spellCheck() {
    string inputFile = "../Code_lib/input.txt";
    ifstream infile(inputFile);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open input file '" << inputFile << "'." << endl;
        return;
    }

    string word;
    while (infile >> word) {
        // Student Task: Implement the logic to handle spelling checks for each word
        string lowerWord = toLower(word);
        int num = getIndex(lowerWord[0]);
        if (!bstArray[num].search(lowerWord)) {
            cout << "Misspelled: " << word<<endl;
            getClosestWords(lowerWord);
        }
        // : Convert `word` to lowercase using `toLower`.
        // : Use `getIndex` to find out which BST corresponds to the first character of the `word`.
        // : Use the `search` function to check if the word is in the dictionary.
        // : If the word is not found, print "Misspelled: <word>" and call `getClosestWords` to find and display suggestions.
    }
}

// Helper: Get Closest Words (based on Hamming Distance)
vector<string> Dictionary::getClosestWords(const string &word) {
    int index = getIndex(word[0]);
    if (index == -1) return {};
    vector<string> candidates;

    // Capture the output of the `traverse` method to collect all words
    stringstream ss;
    streambuf* oldCoutBuf = cout.rdbuf(); // Save the current buffer of cout
    cout.rdbuf(ss.rdbuf()); // Redirect cout to the stringstream

    // Traverse the BST; it will output to the stringstream instead of the console
    bstArray[index].traverse();

    cout.rdbuf(oldCoutBuf); // Restore the original cout buffer

    // Read words from the stringstream
    string capturedWord;
    // Student Task: Extract words captured from the stringstream and add them to `candidates`
    while (getline(ss, capturedWord)) {
        if (!capturedWord.empty()) {
            candidates.push_back(capturedWord);
        }
    }
    // : Read words from `ss` one line at a time.
    // : Make sure to only add non-empty words to `candidates`.

    // Calculate distances and find the closest words
    vector<pair<int, string>> distances;
    // Student Task: Calculate Hamming distances for each word and store them
    for (size_t i = 0; i < candidates.size(); ++i) {
        int distance = hammingDistance(word, candidates[i]);
        distances.push_back(make_pair(distance, candidates[i])); // Fix to store candidates[i]
    }
    // : Loop through each word in `candidates` and calculate its Hamming Distance to `word`.
    // : Store each distance along with the corresponding word in `distances`.

    // Sort by distance and limit to 5 suggestions
    // Student Task: Sort the words based on Hamming Distance and limit to the top 5 closest words
    sort(distances.begin(), distances.end());
    vector<string> closestWords;
    for (size_t i = 0; i < min(distances.size(), static_cast<size_t>(5)); ++i) {
        closestWords.push_back(distances[i].second);
    }
    // TODO: Sort the `distances` vector so that the closest words are at the beginning.
    // TODO: Select the top 5 closest words (or fewer if there aren't that many) and add them to `closestWords`.

    return closestWords;
}


// Student Task: Implement the containsWord function
// containsWord: Checks if a specific `word` is present in the dictionary across any of its Binary Search Trees (BSTs)
// This function should make use of the helper functions to achieve its purpose:
// - Use `toLower` to ensure the word is case-insensitive when searching in the dictionary.
// - Use `getIndex` to find out which BST corresponds to the first character of the word.
// - Use the `search` function from the appropriate BST to check if the word is present.
// Consider how these existing functions can be combined to efficiently determine if the word is in the dictionary.
bool Dictionary::containsWord(const std::string& word) {
    // Student Task: Implement the containsWord function
    string lowerWord = toLower(word);
    int num = getIndex(lowerWord[0]);
    return bstArray[num].search(lowerWord);
    // : Convert `word` to lowercase using `toLower` to ensure case insensitivity.
    // : Use `getIndex` to determine the correct BST for the first character of `lowerWord`.
    // : Use the `search` function to check if the word is present in the identified BST.
    // : Return the result of the search.
}

// Student Task: Implement the isWordInBST function
// isWordInBST: Checks if a specific `word` is present in the Binary Search Tree (BST) corresponding to the character `c`
// This function should use the existing helper functions to accomplish the task:
// - Use `getIndex` to determine which BST corresponds to the character `c`.
// - Use `toLower` to ensure the word is case-insensitive when checking for presence in the BST.
// - Use the `search` function from the BST to check if the word is present.
// Think about how these functions can be combined to implement this logic efficiently.
bool Dictionary::isWordInBST(char c, const std::string& word) {
    int num = getIndex(c);
    string lowerWord = toLower(word);
    return bstArray[num].search(lowerWord);
    // Student Task: Implement the isWordInBST function
    // : Use `getIndex` to get the correct index for the character `c`.
    // : Make sure the word is in lowercase using `toLower` before searching.
    // : Use the `search` method of the BST to determine if the word is present.
}
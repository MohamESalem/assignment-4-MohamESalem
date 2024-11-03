#include "Dictionary.h"
#include <gtest/gtest.h>
#include <iostream> // For std::cout
#include <fstream> // For file operations
#include <string>

using namespace std;

// Helper Functions
void createCorpusFile(const std::string& filename, const std::string& content) {
    std::ofstream outfile(filename);
    outfile << content;
    outfile.close();
}

void createInputFile(const std::string& filename, const std::string& content) {
    std::ofstream outfile(filename);
    outfile << content;
    outfile.close();
}

void removeFile(const std::string& filename) {
    std::remove(filename.c_str());
}

// Test Suite for Dictionary
class DictionaryTest : public ::testing::Test {
protected:
    Dictionary dict;

    void SetUp() override {
        createCorpusFile("../Code_lib/corpus.txt", "apple banana orange apricot berry cherry");
        createInputFile("../Code_lib/input.txt", "appl bananna organe berryy figg");
        dict.buildDictionary();
    }

    void TearDown() override {
        removeFile("../Code_lib/corpus.txt");
        removeFile("../Code_lib/input.txt");
        removeFile("../Code_lib/dictionary.txt");
    }
};

// 1. Test Build Dictionary
TEST_F(DictionaryTest, BuildDictionary) {
    EXPECT_NO_THROW(dict.buildDictionary()) << "1. Oops! Something went wrong while building the dictionary. Make sure the corpus file exists and is read correctly.";
    EXPECT_TRUE(dict.containsWord("apple")) << "1. It seems 'apple' was not added to the dictionary correctly.";
    EXPECT_TRUE(dict.containsWord("banana")) << "1. 'banana' should be present in the dictionary. Double-check your build logic.";
    EXPECT_FALSE(dict.containsWord("grape")) << "1. 'grape' wasn't in the corpus file, so it shouldn't be in the dictionary.";
    cout << "1. Great job! The dictionary was built successfully." << endl;
}

// 2. Test Save Dictionary to Disk
TEST_F(DictionaryTest, SaveDictionaryToDisk) {
    dict.saveDictionaryToDisk();
    ifstream infile("../Code_lib/dictionary.txt");
    EXPECT_TRUE(infile.is_open()) << "2. Unable to open 'dictionary.txt'. Ensure the dictionary is saved to the correct path.";

    string line;
    EXPECT_TRUE(getline(infile, line)) << "2. The 'dictionary.txt' file is empty. Ensure your save logic works correctly.";
    infile.close();
    cout << "2. Well done! The dictionary was saved successfully." << endl;
}

// 3. Test Add Word
TEST_F(DictionaryTest, AddWord) {
    dict.addWord("fig");
    EXPECT_TRUE(dict.containsWord("fig")) << "3. Hmm, 'fig' should be in the dictionary but wasn't found. Check your addWord logic.";
    dict.addWord("fig"); // Attempt to add duplicate
    EXPECT_TRUE(dict.containsWord("fig")) << "3. Adding 'fig' again shouldn't cause any issues.";
    cout << "3. Excellent! The addWord function works perfectly." << endl;
}

// 4. Test Remove Word
TEST_F(DictionaryTest, RemoveWord) {
    dict.addWord("kiwi");
    EXPECT_TRUE(dict.containsWord("kiwi")) << "4. 'kiwi' should have been added to the dictionary.";
    dict.removeWord("kiwi");
    EXPECT_FALSE(dict.containsWord("kiwi")) << "4. 'kiwi' should have been removed from the dictionary.";
    EXPECT_NO_THROW(dict.removeWord("nonexistent")) << "4. Removing a non-existent word should not cause an error.";
    cout << "4. Good job! The removeWord function handles both existing and non-existent words correctly." << endl;
}

// 5. Test Spell Check
TEST_F(DictionaryTest, SpellCheck) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    dict.spellCheck();

    std::cout.rdbuf(oldCout);
    std::string output = buffer.str();

    EXPECT_NE(output.find("Misspelled: appl"), std::string::npos) << "5. 'appl' was misspelled, but it was not identified correctly.";
    EXPECT_NE(output.find("Misspelled: bananna"), std::string::npos) << "5. 'bananna' should have been flagged as misspelled.";
    EXPECT_NE(output.find("Misspelled: organe"), std::string::npos) << "5. 'organe' was misspelled, but it wasn't flagged.";
    EXPECT_NE(output.find("Misspelled: berryy"), std::string::npos) << "5. 'berryy' should have been flagged as misspelled.";
    EXPECT_NE(output.find("Misspelled: figg"), std::string::npos) << "5. 'figg' was misspelled, but it wasn't identified.";

    cout << "5. Spell checking function works as expected! Well done." << endl;
}

// 6. Test Get Closest Words
TEST_F(DictionaryTest, GetClosestWords) {
    std::vector<std::string> suggestions = dict.getClosestWords("appl");
    EXPECT_FALSE(suggestions.empty()) << "6. Suggestions were expected for 'appl', but none were provided. Check your logic.";
    EXPECT_EQ(suggestions[0], "apple") << "6. The closest suggestion for 'appl' should be 'apple'.";

    suggestions = dict.getClosestWords("bananna");
    EXPECT_FALSE(suggestions.empty()) << "6. Suggestions were expected for 'bananna', but none were provided.";
    EXPECT_EQ(suggestions[0], "banana") << "6. The closest suggestion for 'bananna' should be 'banana'.";

    cout << "6. The suggestion system correctly identifies the closest matches. Keep it up!" << endl;
}
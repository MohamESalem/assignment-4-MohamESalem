#include "BST.h"
#include "Dictionary.h"
#include <string>

using namespace std;

int main() {
    BST<string> bst;

    bst.insert("dog");
    bst.insert("cat");
    bst.insert("fish");
    bst.insert("bird");
    bst.insert("elephant");
    bst.insert("ant");
    bst.insert("zebra");

    cout << "In-Order Traversal:" << endl;
    bst.traverse();

    cout << "\nTree Visualization:" << endl;
    bst.print();

    /* Second part */

    Dictionary dict;

    // Step 1: Build the dictionary from "corpus.txt"
    dict.buildDictionary();

    // Step 2: Save the dictionary to "dictionary.txt"
    dict.saveDictionaryToDisk();

    // Step 3: Perform spell checking on "input.txt"
    dict.spellCheck();
    return 0;
}
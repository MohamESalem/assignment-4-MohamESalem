[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/VXAFjYAw)
<h2 align="center">CSCE 2211 Fall 2024 Applied Data Structures</h2>
<h3 align="center">Assignment 4</h3>

> [!IMPORTANT]  
> Avoid deduction by writing your name, section number, and ID in comment at the beginning of each file, then push your changes. 📝

<table border="0">
 <tr>
    <td><b style="font-size:20px">📋 Prerequisites for the Assignment</b></td>
    <td><b style="font-size:20px">🛠️ How It Works (Testing Cases)</b></td>
 </tr>
 <tr>
    <td>
    1. Create a <a href="https://account.jetbrains.com/login" target="_blank">JetBrains Account</a> & apply for the student pack. 🎓<br>    
    2. Download <a href="https://www.jetbrains.com/clion/download/#section=mac" target="_blank">CLion for Windows & Mac</a> and sign in with your account. 💻<br>    
    3. Sign in to the GitHub Desktop app on your PC. 🔗<br>  
    4. Clone this repository to start working on the assignment. 📂<br>
    5. Write your name and ID in a comment at the beginning of each file, then push your changes. 📝<br>
    </td>
    <td>
    1. Open the repo folder as a project in CLion IDE. 🚀<br> 
    2. Start writing your code in the <strong>Code_lib</strong> directory. 🖊️<br>
    3. After completing the required parts, go to <strong>Google_tests</strong> and run <strong>TestBST.cpp</strong> and <strong>TestDictionary.cpp</strong> to test your code. 🧪<br>
    4. The test suite files will show which tests have passed and which have failed. ✅❌<br>
    </td>
 </tr>
</table>

> [!WARNING]  
> - Your submission time affect the assignment grade; pay attention to your grades and submit on time.
> - You have to commit and push your code to Github at the end of each change.


## 🔍 Overview of the Assignment
This assignment consists of implementing a spell checker using Binary Search Trees (BSTs). The assignment focuses on building and maintaining a dictionary using dynamic data structures, enabling efficient search operations, and implementing functions for text processing and spell-checking. The project is divided into two main parts: 
1.	**The BST ADT Implementation** (50 points)
2.  **Spell Checker using BST-based Dictionary** (50 points)

Each part of the assignment builds on fundamental data structure concepts, particularly focusing on binary search trees and efficient search algorithms. 
📕 [Check the Assignment PDF](CSCE_2211_Assignment4.pdf)

> [!TIP]
> Use the [visualization tool]([https://visualgo.net/en/list](https://www.cs.usfca.edu/~galles/visualization/BST.html))

***

## 🧱 The BST ADT (50 Points) [Go to the BST Code](Code_lib/BST.cpp)

The BST (Binary Search Tree) is a hierarchical data structure that stores elements in a way that allows for efficient searching, insertion, and deletion. Each node in the tree has a maximum of two children: a left child and a right child. The left child contains values less than its parent, and the right child contains values greater than its parent.

🔨 Required Implementation

You are required to implement a template class DEQ using a Simple Linked List (SLL). The DEQ should support the following operations:

- **Constructor**: Initialize an empty BST.
- **Copy Constructor**: Create a deep copy of an existing BST.
- **Destructor**: Properly destroy and deallocate memory for the BST.
- **insert**: Add an element to the BST.
- **empty**: Check if the BST is empty.
- **search**: Search for a key in the BST.
- **retrieve**: Retrieve data for a given key.
- **traverse**: Perform an in-order traversal of the BST.
- **preorder**: Perform a pre-order traversal of the BST.
- **levelorder**: Perform a level-order traversal of the BST.
- **remove**: Remove an element from the BST.

📁 Files to Implement: `BST.cpp - Implementation of the BST functions.`

🚀 Instructions

- Implement all required member functions in BST.cpp.
- Comment your code and document any assumptions you made while implementing the BST.
- Test your BST implementation using the provided unit tests in the TestBST.cpp file.

***

## 📖 Spell Checker using BST-based Dictionary (50 Points) [Go to BST-based Dictionary Code](Code_lib/Dictionary.cpp)

The spell checker uses a dynamic dictionary implemented as an array of BSTs, where each BST stores words that begin with a particular letter or digit. The spell checker can efficiently determine whether a word is correctly spelled and suggest alternative words based on Hamming distance.

#### ✍️ Required Implementation

You are required to implement the following functions in the Dictionary class:

- buildDictionary: Read words from a text corpus and build the BST-based dictionary.
- saveDictionaryToDisk: Save the dictionary to a text file for later use.
- addWord: Add a new word to the dictionary.
- removeWord: Remove a word from the dictionary.
- spellCheck: Check if words from an input file are spelled correctly and suggest alternatives.
- getClosestWords: Identify and return the closest words based on Hamming distance.


📁 Files to Implement `Simulation.cpp - Implementation of the airport simulation.`

#### 🚀 Instructions

- Implement the Dictionary class using the provided skeleton files.
- Ensure that your spell checker can efficiently read words from a corpus, store them in a BST, and check spelling accurately.
- Use helper functions to calculate Hamming distance and suggest the closest words.
- Test your spell checker using the provided unit tests in the TestDictionary.cpp file.

### 🔧 Testing Your Code
- Run the BST tests [Test your BST code](Google_tests/TestBST.cpp).
- Run the Dictionary tests [Test your Dictionary code](Google_tests/TestDictionary.cpp).

Ensure that all test cases pass before submitting your assignment.

### 📬 Submission Instructions:
- Comment your code and document any assumptions you made.

***
📝 To-Do List
- [ ] Run all test cases successfully.
- [ ] Commit and push your code regularly to GitHub.
- [ ] Submit your final code before the deadline (November 2nd, 2024, 11:59 CLT).

:white_check_mark: Use `git status` to list all new or modified files that haven't yet been committed.

<p align="center">
  <b>Created by</b><br>
  <b>Mohamed Ibrahim Hany</b>
</p>


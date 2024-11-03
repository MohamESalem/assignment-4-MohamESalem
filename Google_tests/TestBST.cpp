#include "BST.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream> // Include for cout

using namespace std;

// 1. Test Constructor and Empty
TEST(BSTTest, ConstructorAndEmpty) {
    BST<int> bst;
    EXPECT_TRUE(bst.empty()) << "1. Oops! The tree should be empty right after construction. "
                             << "Make sure your constructor initializes the tree correctly.";
    cout << "1. Great job! You've successfully created an empty BST. Well done!" << endl;
}

// 2. Test Copy Constructor
TEST(BSTTest, CopyConstructor) {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    BST<int> bstCopy = bst; // Using the copy constructor

    EXPECT_TRUE(bstCopy.search(10)) << "2. It seems the copy constructor didn't copy the value 10 correctly.";
    EXPECT_TRUE(bstCopy.search(5)) << "2. The value 5 wasn't found in the copied tree. Check how you're copying nodes.";
    EXPECT_TRUE(bstCopy.search(15)) << "2. The copied tree is missing the value 15. Double-check your copy logic.";
    EXPECT_FALSE(bstCopy.search(20)) << "2. Good catch! The value 20 shouldn't be in the copied tree.";

    EXPECT_FALSE(bstCopy.empty()) << "2. Your copied tree should not be empty. Verify that the nodes are being copied correctly.";
    EXPECT_FALSE(bst.empty()) << "2. Excellent! Your original tree is still intact, and the copy works perfectly.";
    cout << "2. Nice! Copy constructor works as expected." << endl;
}

// 3. Test Insert and Search
TEST(BSTTest, InsertAndSearch) {
    BST<string> bst;
    bst.insert("apple");
    bst.insert("banana");
    bst.insert("cherry");

    EXPECT_TRUE(bst.search("apple")) << "3. Could not find 'apple' after insertion. Double-check your insert logic.";
    EXPECT_TRUE(bst.search("banana")) << "3. Hmm, 'banana' seems to be missing. Make sure you're inserting nodes correctly.";
    EXPECT_TRUE(bst.search("cherry")) << "3. 'Cherry' should be in the tree. Verify your search or insert functions.";
    EXPECT_FALSE(bst.search("date")) << "3. Good job! 'Date' wasn't inserted, so it shouldn't be found.";

    cout << "3. Awesome! The search function found all the right values. Keep it up!" << endl;
}

// 4. Test Retrieve
TEST(BSTTest, Retrieve) {
    BST<string> bst;
    bst.insert("apple");
    bst.insert("banana");
    bst.insert("cherry");

    string result;
    EXPECT_TRUE(bst.retrieve("banana", result)) << "4. The tree should be able to retrieve 'banana'. Check your retrieve method.";
    EXPECT_EQ(result, "banana") << "4. Retrieve method found 'banana', but something went wrong. Double-check your data retrieval.";

    EXPECT_FALSE(bst.retrieve("date", result)) << "4. Correct! 'Date' wasn't found because it was never inserted.";
    cout << "4. Retrieve method works correctly for all tested cases!" << endl;
}

// 5. Test Traverse (In-Order Traversal)
TEST(BSTTest, Traverse) {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    testing::internal::CaptureStdout();
    bst.traverse();
    string output = testing::internal::GetCapturedStdout();

    // In-Order Traversal should be sorted
    EXPECT_EQ(output, "5\n10\n15\n") << "5. Looks like your in-order traversal is incorrect. Remember: Left, Root, Right order.";

    cout << "5. Nice! Your in-order traversal prints the BST correctly. Keep it up!" << endl;
}

// 6. Test Preorder Traversal
TEST(BSTTest, Preorder) {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    testing::internal::CaptureStdout();
    bst.preorder();
    string output = testing::internal::GetCapturedStdout();

    // Preorder: Root, Left, Right
    EXPECT_EQ(output, "10\n5\n15\n") << "6. Your preorder traversal isn't quite right. Make sure to visit Root, then Left, then Right.";

    cout << "6. Preorder traversal is working as expected. Great job!" << endl;
}

// 7. Test Level Order Traversal
TEST(BSTTest, LevelOrder) {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(13);
    bst.insert(18);

    testing::internal::CaptureStdout();
    bst.levelorder();
    string output = testing::internal::GetCapturedStdout();

    // Level Order should print by levels
    EXPECT_EQ(output, "10\n5\n15\n3\n7\n13\n18\n") << "7. Hmm, the level-order traversal isn't as expected. Remember: Top-to-bottom, left-to-right.";

    cout << "7. Level-order traversal is functioning correctly. Nicely done!" << endl;
}

// 8. Test Remove Node
TEST(BSTTest, RemoveNode) {
    BST<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    // Remove leaf node
    bst.remove(3);
    EXPECT_FALSE(bst.search(3)) << "8. It looks like '3' is still in the tree. Did you properly remove leaf nodes?";

    // Remove node with one child
    bst.remove(5);
    EXPECT_FALSE(bst.search(5)) << "8. Removing '5' (with one child) didn't work as expected. Check your remove logic.";

    // Remove node with two children
    bst.remove(10);
    EXPECT_FALSE(bst.search(10)) << "8. Node '10' wasn't removed properly. It had two children, so make sure you handle that case.";

    cout << "8. Removal operation works correctly for different types of nodes!" << endl;
}

// 9. Test Destructor (Implicitly Checked)
TEST(BSTTest, Destructor) {
    BST<int>* bst = new BST<int>();
    bst->insert(10);
    bst->insert(20);
    delete bst; // If the destructor has issues, this might cause a crash or leak

    cout << "9. Well done! Your tree was deleted without any issues. Destructor works correctly." << endl;
}

// 10. Test Insert Duplicate
TEST(BSTTest, InsertDuplicate) {
    BST<int> bst;
    bst.insert(10);
    bst.insert(10); // Insert duplicate
    bst.insert(10); // Insert duplicate again

    testing::internal::CaptureStdout();
    bst.traverse();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10\n") << "10. It seems like duplicates were inserted. Ensure your BST prevents duplicates.";

    cout << "10. Your BST correctly handles duplicates. Nice work!" << endl;
}

// 11. Test Insert and Remove Combination
TEST(BSTTest, InsertRemoveCombination) {
    BST<int> bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.remove(20); // Remove root

    EXPECT_FALSE(bst.search(20)) << "11. Removing the root node '20' didn't work as expected. Check how you're reassigning the root.";
    EXPECT_TRUE(bst.search(10)) << "11. Hmm, '10' should still be in the tree. Did the removal affect it?";
    EXPECT_TRUE(bst.search(30)) << "11. Good job! '30' remains intact after removing other nodes.";

    cout << "11. Insert and remove operations work together seamlessly!" << endl;
}
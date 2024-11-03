#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Private helper functions
    void destroyTree(Node* node);
    Node* copyTree(const Node* node);
    Node* insert(Node* node, const T& value);
    Node* search(Node* node, const T& value) const;
    bool retrieve(Node* node, const T& value, T& result) const;
    void inOrderTraversal(Node* node) const;
    void preOrderTraversal(Node* node) const;
    void levelOrderTraversal(Node* node) const;
    Node* remove(Node* node, const T& value);
    Node* findMin(Node* node);

    // New helper function for printing the tree
    void printTree(Node* node, int indent = 0) const;

public:
    // Constructor and Destructor
    BST();
    BST(const BST& other); // Copy constructor
    ~BST();

    // Public member functions
    void insert(const T& value);
    bool empty() const;
    bool search(const T& value) const;
    bool retrieve(const T& value, T& result) const;
    void traverse() const;
    void preorder() const;
    void levelorder() const;
    void remove(const T& value);

    // Public function to print the tree
    void print() const;
};

#endif // BST_H
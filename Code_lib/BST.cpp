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

#include "BST.h"
#include <iomanip> // Required for 'setw'

using namespace std;

// Constructor: construct an empty tree
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
BST<T>::BST() : root(nullptr) {}

// Copy Constructor: copy the tree from an existing tree
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
BST<T>::BST(const BST& other) {
    root = copyTree(other.root);
}

// Destructor: Destroy tree
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
BST<T>::~BST() {
    destroyTree(root);
}

// Student Task: Implement the destroyTree function (Private)
// destroyTree: Recursively deletes all nodes in the Binary Search Tree (BST)
// This function is responsible for freeing up the memory allocated for each node in the tree.
// You will need to use a recursive approach to delete all nodes, starting from the given `node`.
// 1. If `node` is not `nullptr`, recursively call `destroyTree` on its `left` and `right` children.
// 2. After the recursive calls, delete the current `node` to free its memory.
// This function ensures that all nodes are removed and no memory leaks occur when the tree is destroyed.
template<typename T>
void BST<T>::destroyTree(Node* node) {
    // Student Task: Implement the destroyTree function
    if(node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    } else {
        return;
    }
    // : 1. Check if `node` is not `nullptr`. If it is, there is nothing to delete.
    // : 2. Recursively call `destroyTree` on the `left` child of `node`.
    // : 3. Recursively call `destroyTree` on the `right` child of `node`.
    // : 4. Delete the `node` to free up its memory.
}

// Student Task: Implement the copyTree function (Private)
// copyTree: Recursively creates a deep copy of the Binary Search Tree (BST)
// This function is used to make an exact duplicate of the existing tree starting from the given `node`.
// You need to use a recursive approach to copy each node and its children.
// 1. If `node` is `nullptr`, return `nullptr` as there is nothing to copy.
// 2. Create a new node using the data from the current `node`.
// 3. Recursively copy the `left` and `right` children of the current `node` and assign them to the new node's `left` and `right` pointers.
// 4. Return the new node, which will be linked to the copied tree.
template<typename T>
typename BST<T>::Node* BST<T>::copyTree(const Node* node) {
    // Student Task: Implement the copyTree function
    if(node == nullptr) {
      return nullptr;
    }
      Node* newNode = new Node(node->data);
      newNode->left = copyTree(node->left);
      newNode->right = copyTree(node->right);
      return newNode;
    // : 1. Check if `node` is `nullptr`. If it is, return `nullptr` because there is no node to copy.
    // : 2. Create a new `Node` using the data from the current `node`.
    // : 3. Recursively call `copyTree` on the `left` child of `node` and assign it to `newNode->left`.
    // : 4. Recursively call `copyTree` on the `right` child of `node` and assign it to `newNode->right`.
    // : 5. Return the `newNode`, which now has its own left and right children copied.
}

// Student Task: Implement the insert function (Private)
// insert: Recursively inserts a new element into the Binary Search Tree (BST)
// This function adds a new node with the specified `value` into the correct position in the tree.
// It uses recursion to find the appropriate location for the new node based on the binary search tree property.
// 1. If `node` is `nullptr`, this means you've found an empty spot where the new node should be placed.
//    Create a new `Node` with the given `value` and return it.
// 2. If `value` is less than `node->data`, recursively call `insert` on the `left` child to find the correct spot in the left subtree.
// 3. If `value` is greater than `node->data`, recursively call `insert` on the `right` child to find the correct spot in the right subtree.
// 4. After placing the new node, return the `node` to link the tree correctly.
template<typename T>
typename BST<T>::Node* BST<T>::insert(Node* node, const T& value) {
    // Student Task: Implement the insert function
    if(node == nullptr) {
        Node* newNode = new Node(value);
        return newNode;
    } else if (node->data==value) {
        return node;
    }
    else if(value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
    // : 1. Check if `node` is `nullptr`. If it is, create a new `Node` with `value` and return it.
    // : 2. If `value` is less than `node->data`, recursively call `insert` on `node->left`.
    // : 3. If `value` is greater than `node->data`, recursively call `insert` on `node->right`.
    // : 4. Return `node` to maintain the links and structure of the tree.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::insert(const T& value) {
    root = insert(root, value);
}

// Student Task: Implement the empty function
// empty: Checks if the Binary Search Tree (BST) is empty
// This function should return `true` if the tree is empty and `false` otherwise.
// 1. To determine if the tree is empty, check if the `root` is `nullptr`.
// 2. If `root` is `nullptr`, that means there are no nodes in the tree, so return `true`.
// 3. If `root` points to a node, return `false` because the tree has at least one element.
template<typename T>
bool BST<T>::empty() const {
    // Student Task: Implement the empty function
    if (root == nullptr) {
        return true;
    }
    else {
        return false;
    }
    // : 1. Check if `root` is `nullptr`. If it is, return `true`.
    // : 2. If `root` is not `nullptr`, return `false` because the tree has elements.
}

// Student Task: Implement the search function (Private)
// search: Recursively searches for a specific `value` in the Binary Search Tree (BST)
// This function should traverse the tree starting from the given `node` to find the `value`.
// Consider how you would navigate the tree to locate the correct node based on comparisons.
// Think about when you should return the `node` and when to keep searching.
template<typename T>
typename BST<T>::Node* BST<T>::search(Node* node, const T& value) const {
    // Student Task: Implement the search function
    if(node == nullptr) {
        return nullptr;
    }
    else if(node->data==value) {
        return node;
    } else if (value>node->data) {
        return search(node->right, value);
    } else if (value<node->data){
        return search(node->left, value);
    } else {
        return nullptr;
    }
    // : Determine when to stop the search and return the `node`.
    // : Use comparisons to decide whether to search the left or right subtree.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
bool BST<T>::search(const T& value) const {
    return search(root, value) != nullptr;
}

// Student Task: Implement the retrieve function (Private)
// retrieve: Searches for a specific `value` in the Binary Search Tree (BST) and retrieves it if found
// This function should use an existing search method to locate the `value` starting from `node`.
// If the value is found, store it in `result` and return a success indicator.
// Think about how you can utilize the search operation and what to do with the outcome.
template<typename T>
bool BST<T>::retrieve(Node* node, const T& value, T& result) const {
    // Student Task: Implement the retrieve function
    Node* temp = search(node, value);
    if(temp != nullptr) {
        result = temp->data;
        return true;
    } else {
        return false;
    }

    // : Use the search function to find the node containing `value`.
    // : If the value is found, store it in `result` and indicate success.
    // : If the value is not found, return an appropriate result.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
bool BST<T>::retrieve(const T& value, T& result) const {
    return retrieve(root, value, result);
}

// Student Task: Implement the inOrderTraversal function (Private)
// inOrderTraversal: Performs an in-order traversal of the Binary Search Tree (BST)
// This function should traverse the tree starting from the given `node` and print each element in order.
// Consider how you might need to visit nodes to ensure the data is printed in sorted order.
// Think about the typical steps of an in-order traversal and how recursion helps achieve this.
template<typename T>
void BST<T>::inOrderTraversal(Node* node) const {
    // Student Task: Implement the inOrderTraversal function
    if(node == nullptr) {
        return;
    } else {
        inOrderTraversal(node->left);
        cout << node->data << "\n";
        inOrderTraversal(node->right);
    }
    // : Decide how to use recursion to visit nodes in the correct order.
    // : Make sure that elements are printed in a way that maintains the natural ordering of the tree.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::traverse() const {
    inOrderTraversal(root);
}

// Student Task: Implement the preOrderTraversal function (Private)
// preOrderTraversal: Performs a pre-order traversal of the Binary Search Tree (BST)
// This function should traverse the tree starting from the given `node` and print each element in a specific order.
// Consider the typical steps of a pre-order traversal and how it differs from other traversal methods.
// Think about which part of the node should be processed first, and how recursion helps navigate the tree.
template<typename T>
void BST<T>::preOrderTraversal(Node* node) const {
    // Student Task: Implement the preOrderTraversal function
    if(node == nullptr) {
        return;
    } else {
        cout << node->data << "\n";
        inOrderTraversal(node->left);
        inOrderTraversal(node->right);
    }
    // : Determine how to use recursion to visit nodes in the pre-order sequence.
    // : Ensure the elements are processed in the correct order to reflect the pre-order traversal method.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::preorder() const {
    preOrderTraversal(root);
}

// Student Task: Implement the levelOrderTraversal function (Private)
// levelOrderTraversal: Performs a level-order traversal of the Binary Search Tree (BST)
// This function should visit and process each node in the tree level by level, starting from the root.
// Consider how you can explore each level of the tree systematically.
// Think about using a different approach than recursion and how you might keep track of nodes at each level.
template<typename T>
void BST<T>::levelOrderTraversal(Node* node) const {
    // Student Task: Implement the levelOrderTraversal function
    queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << "\n";
        if(temp->left != nullptr) {q.push(temp->left);}
        if(temp->right != nullptr) {q.push(temp->right);}
    }
    // : Use a suitable data structure to manage nodes as you process them level by level.
    // : Ensure that each node is visited once, starting from the root, then moving across each level.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::levelorder() const {
    levelOrderTraversal(root);
}

// Student Task: Implement the findMin function (Private)
// findMin: Finds and returns the node with the minimum value in the Binary Search Tree (BST)
// This function should locate the smallest value in the tree starting from the given `node`.
// Think about how the properties of the BST can help you find the minimum value without checking every node.
// Consider what direction you should move in the tree to find the smallest element.
template<typename T>
typename BST<T>::Node* BST<T>::findMin(Node* node) {
    // Student Task: Implement the findMin function
    if(node == nullptr) {
        return nullptr;
    } else {
        while(node->left != nullptr) {
            node = node->left;
        }

        return node;
    }
    // TODO: Use the properties of the BST to locate the minimum value node starting from `node`.
    // TODO: Make sure the function returns the node containing the smallest value.
}

// Student Task: Implement the remove function (Private)
// remove: Removes a specified `value` from the Binary Search Tree (BST)
// This function should find and delete the node containing `value`, maintaining the BST structure afterward.
// Consider how you would handle different scenarios: a node with no children, a node with one child, and a node with two children.
// Think carefully about how to replace or rearrange nodes to ensure the tree remains valid.
template<typename T>
typename BST<T>::Node* BST<T>::remove(Node* node, const T& value) {
    // Student Task: Implement the remove function
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
    }

    return node;


    // TODO: Determine how to find the node with the specified `value` in the tree.
    // TODO: Think about how to handle the different cases:
    // - When the node is a leaf (no children).
    // - When the node has one child.
    // - When the node has two children.
    // TODO: Make sure that the BST properties are maintained after the node is removed.
}

// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::remove(const T& value) {
    root = remove(root, value);
}

// Helper function to print the tree without arrows or slashes
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::printTree(Node* node, int indent) const {
    if (node != nullptr) {
        if (node->right) {
            printTree(node->right, indent + 4);
        }

        if (indent) {
            cout << setw(indent) << ' ';
        }

        // Print the current node
        cout << node->data << endl;

        if (node->left) {
            printTree(node->left, indent + 4);
        }
    }
}

// Public function to call the print helper
// Note for Students: Do NOT modify this function. It is already implemented correctly.
// This function is complete, and no further changes are necessary.
template<typename T>
void BST<T>::print() const {
    printTree(root);
}

// Explicit template instantiation
template class BST<string>;
template class BST<int>;
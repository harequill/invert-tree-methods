#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <queue>

struct Node {
  int data; // value of the node
  Node* left; // pointer to left child
  Node* right; // pointer to right child 

  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
  private:
    Node* root; // entry point node
 
  public:
    BinaryTree() : root(nullptr) {};

    Node* getRoot() { return root; };
    void setRoot(Node* newRoot) { root = newRoot; }

    // Method 1: recursively
    // Uses call stack to swap left and right children at each node
    Node* invertRecursive(Node* node);

    // Method 2: iteratively
    // Search with a queue,swapping level by level.
    Node* invertIterative(Node* node);

    void print(Node* node); // print tree values like left -> root -> right
};

#endif

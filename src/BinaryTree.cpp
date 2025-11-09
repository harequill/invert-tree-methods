#include "../include/BinaryTree.h"
#include <iostream>

// Recursive inversion: goes down the tree and swaps left/right children at each node.
Node* BinaryTree::invertRecursive(Node* node) {
  // Empty node as base case
  if (node == nullptr) {
    return nullptr;
  }

  Node* temp = node->left;
  node->left = node->right;
  node->right = temp;

  invertRecursive(node->left);
  invertRecursive(node->right);

  return node;
}

// Print tree in left->root->right order
void BinaryTree::print(Node* node) {
  if (node != nullptr) {
    print(node->left);
    std::cout << node->data << " ";
    print(node->right);
  }
}


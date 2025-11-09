#include <iostream>
#include "../include/BinaryTree.h"

using namespace std;

int main() {
  cout << "BINARY TREE INVERSION";

  // In-order: 1, 2, 3, 4, 6, 7, 9
  // Sample:
  //      4
  //    /  \
  //   2    7
  //  / \  / \
  // 1  3 6  9

  // expected result: 9, 7, 6, 4, 3, 2, 1
  //  Sample:
  //      4
  //    /  \
  //   7    2
  //  / \  / \
  // 9  6 3  1

  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(6);
  root->right->right = new Node(9);

  BinaryTree tree;
  tree.setRoot(root);

  cout << "\nOriginal tree: ";
  tree.print(tree.getRoot());

  tree.invertRecursive(tree.getRoot());
  cout << "\nAfter recursive inversion: ";
  tree.print(tree.getRoot());

  cout << "\nNow it will return to original format after iterative inversion.";
  tree.invertIterative(tree.getRoot());
  cout << "\nAfter iterative inversion: ";
  tree.print(tree.getRoot());

  return 0;
}


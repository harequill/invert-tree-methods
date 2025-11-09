# Binary Tree Inversion - Demonstration

A practical demonstration of two different approaches to inverting a binary tree: recursive and iterative methods.

## Table of Contents
- [What is Binary Tree Inversion?](#what-is-binary-tree-inversion)
- [The Problem](#the-problem)
- [Project Overview](#project-overview)
- [Core Concepts](#core-concepts)
- [Code Walkthrough](#code-walkthrough)
- [How It Works](#how-it-works)
- [Output Example](#output-example)
- [Key Takeaways](#key-takeaways)
- [Running the Project](#running-the-project)

## What is Binary Tree Inversion?

Binary tree inversion is a fundamental tree manipulation operation where you swap all left and right children at every node in the tree. This operation essentially creates a mirror image of the original tree.

**Visual Example:**

```
Original Tree:              Inverted Tree:
      4                           4
    /   \                       /   \
   2     7        =====>       7     2
  / \   / \                   / \   / \
 1   3 6   9                 9   6 3   1
```

This operation is commonly asked in coding interviews and helps demonstrate understanding of:
- Tree traversal algorithms
- Recursion vs iteration
- Data structure manipulation

## The Problem

Given a binary tree, invert it so that the left and right children of all nodes are swapped.

**Input:** Root node of a binary tree  
**Output:** Root node of the inverted binary tree  
**In-order traversal changes:** `1, 2, 3, 4, 6, 7, 9` -> `9, 7, 6, 4, 3, 2, 1`

## Project Overview

This project demonstrates two different approaches to solving the binary tree inversion problem:

1. **Recursive approach**: Uses the call stack to traverse and swap nodes
2. **Iterative approach**: Uses a queue (BFS) to traverse and swap nodes

### Project Structure

```
invert_tree/
|-- build/                              # Compiled binaries
|-- include/
|   |-- BinaryTree.h                    # Header file with class definition
|── src/
    |-- BinaryTree.cpp                  # Implementation of inversion methods
    |-- main.cpp                        # Entry point and demonstration
```

## Core Concepts

### 1. **Binary Tree Node Structure**

```cpp
struct Node {
  int data;           // value stored in the node
  Node* left;         // pointer to left child
  Node* right;        // pointer to right child
  
  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
```

Each node contains:
- A data value (integer)
- Pointers to left and right children
- Constructor for easy initialization

### 2. **Binary Tree Class**

```cpp
class BinaryTree {
  private:
    Node* root;                          // entry point node
  
  public:
    Node* invertRecursive(Node* node);   // recursive inversion
    Node* invertIterative(Node* node);   // iterative inversion
    void print(Node* node);              // in-order traversal print
};
```

The class encapsulates:
- Root node management
- Two inversion algorithms
- Utility method for printing (in-order traversal)

## Code Walkthrough

### 1. Recursive Inversion (BinaryTree.cpp)

```cpp
Node* BinaryTree::invertRecursive(Node* node) {
  // Empty node as base case
  if (node == nullptr) {
    return nullptr;
  }

  // Swap left and right children
  Node* temp = node->left;
  node->left = node->right;
  node->right = temp;

  // Recursively invert subtrees
  invertRecursive(node->left);
  invertRecursive(node->right);

  return node;
}
```

**How it works:**
1. **Base Case**: If node is null, return null (end recursion)
2. **Swap**: Exchange left and right child pointers
3. **Recurse**: Call the function on both children
4. **Return**: Return the current node (now inverted)

**Time Complexity**: O(n) -> visits each node once  
**Space Complexity**: O(h) -> recursion stack depth (h = height of tree)

**Advantages:**
- Clean and intuitive code
- Naturally follows tree structure
- Easy to understand and maintain

**Disadvantages:**
- Uses call stack (risk of stack overflow if tree is too deep)
- Slightly harder to debug

### 2. Iterative Inversion (BinaryTree.cpp)

```cpp
Node* BinaryTree::invertIterative(Node* node) {
  if (node == nullptr) {
    return nullptr;
  }

  std::queue<Node*> q;
  q.push(node);

  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();

    // Swap children
    Node* temp = curr->left;
    curr->left = curr->right;
    curr->right = temp;

    // Add children to queue for processing
    if (curr->left != nullptr) {
      q.push(curr->left);
    }
    if (curr->right != nullptr) {
      q.push(curr->right);
    }
  }

  return node;
}
```

**How it works:**
1. **Initialize**: Create a queue and add root node
2. **Level-by-level processing**:
   - Remove node from queue
   - Swap its children
   - Add non-null children to queue
3. **Repeat**: Continue until queue is empty

**Time Complexity**: O(n) -> visits each node once  
**Space Complexity**: O(w) -> maximum width of tree (queue size)

**Advantages:**
- No recursion (no stack overflow risk)
- Easier to visualize level-by-level processing
- More control over execution flow

**Disadvantages:**
- Requires additional data structure (queue)
- Slightly more verbose code

### 3. Utility Method: Print In-Order

```cpp
void BinaryTree::print(Node* node) {
  if (node != nullptr) {
    print(node->left);           // Visit left subtree
    std::cout << node->data << " "; // Visit current node
    print(node->right);          // Visit right subtree
  }
}
```

In-order traversal prints nodes in left -> root -> right order, which gives sorted output for a Binary Search Tree.

### 4. Main Application (main.cpp)

```cpp
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
```

The program inverts the tree twice (once with each method), effectively returning to the original structure after the second inversion.

## How It Works

### Recursive Execution Flow

When `invertRecursive(root)` is called on node 4:

```
Step 1: invertRecursive(4)
  - Swap children: 2 <-> 7
  - Call invertRecursive(7)  [was left, now right]
  - Call invertRecursive(2)  [was right, now left]

Step 2: invertRecursive(7)
  - Swap children: 6 <-> 9
  - Call invertRecursive(9)
  - Call invertRecursive(6)
  - Both return (leaf nodes)

Step 3: invertRecursive(2)
  - Swap children: 1 <-> 3
  - Call invertRecursive(3)
  - Call invertRecursive(1)
  - Both return (leaf nodes)

Result: Entire tree inverted
```

### Iterative Execution Flow

When `invertIterative(root)` is called:

```
Initial queue: [4]

Iteration 1: Process 4
  - Swap: 2 <-> 7
  - Queue: [7, 2]

Iteration 2: Process 7
  - Swap: 6 <-> 9
  - Queue: [2, 9, 6]

Iteration 3: Process 2
  - Swap: 1 <-> 3
  - Queue: [9, 6, 3, 1]

Iterations 4-7: Process leaf nodes
  - No children to swap
  - Queue eventually empty

Result: Entire tree inverted
```

## Output Example

When you run the program, you'll see:

```
BINARY TREE INVERSION
Original tree: 1 2 3 4 6 7 9 
After recursive inversion: 9 7 6 4 3 2 1 
Now it will return to original format after iterative inversion.
After iterative inversion: 1 2 3 4 6 7 9
```

- **Original**: In-order traversal gives `1 2 3 4 6 7 9`
- **After recursive inversion**: Tree is mirrored, traversal gives `9 7 6 4 3 2 1`
- **After iterative inversion**: Tree is inverted again, returning to original order

## Key Takeaways

### Algorithm Comparison

| Aspect | Recursive | Iterative |
|--------|-----------|-----------|
| **Code Clarity** | More concise | More verbose |
| **Space Complexity** | O(h) - stack | O(w) - queue |
| **Risk** | Stack overflow | Memory for queue |
| **Debugging** | Harder | Easier |
| **Understanding** | Requires recursion knowledge | Straightforward |

### When to Use Each Approach

**Recursive:**
- Tree depth is reasonable (< 10,000 nodes in most systems)
- Code clarity is prioritized
- Working with naturally recursive problems
- Interview settings (usually interviewer enjoys the elegance)

**Iterative:**
- Very deep trees (stack overflow risk)
- Need to control memory usage
- Easier debugging required
- Learning BFS/level-order traversal

### Real-World Applications

While tree inversion itself is primarily an academic exercise, the techniques demonstrated apply to:

- **Tree Serialization/Deserialization**: Converting trees to/from strings
- **Tree Comparison**: Checking if one tree is a mirror of another
- **Graphics Programming**: Mirroring visual tree structures (Big shout out to [MrsRina](https://github.com/MrsRina) | [VokeGPU](https://github.com/vokegpu), girl is trully a baddass!)
- **Game Development**: Inverting decision trees or behavior trees
- **Data Structure Manipulation**: General tree transformations

### Important Lessons

1. **Multiple Valid Solutions**: Many problems have both recursive and iterative solutions
2. **Trade-offs**: Each approach has advantages and disadvantages
3. **Tree Traversal**: Understanding DFS (recursion) vs BFS (iteration) is crucial
4. **Pointer Manipulation**: Careful handling of node pointers is essential
5. **Base Cases**: Always handle null/empty cases first

## Running the Project

### Prerequisites
- C++ compiler with C++11 support or higher (g++, clang++)
- Standard library (STL) with `<queue>` support

### Compile and Run

```bash
# Create build directory
mkdir -p build

# Compile
g++ -I ./include -o build/invert_tree src/main.cpp src/BinaryTree.cpp

# Run
./build/invert_tree
```

## Conclusion

This project demonstrates two fundamental approaches to binary tree inversion, showcasing the difference between recursive and iterative algorithms. Both methods achieve O(n) time complexity but differ in space usage and implementation style.

**Key Points:**
- Recursion offers cleaner, more intuitive code
- Iteration provides better control and avoids stack issues
- Understanding both approaches makes you a more versatile programmer (and is also fun)
- Tree manipulation is a core skill for technical interviews

The techniques here apply broadly to tree algorithms, making this a valuable foundation for understanding more complex tree operations like balancing, searching, and transformations.

## Further Reading

- [Binary Tree Inversion on LeetCode](https://leetcode.com/problems/invert-binary-tree/)
- [Tree Traversal Algorithms](https://en.wikipedia.org/wiki/Tree_traversal)
- [Recursion vs Iteration](https://stackoverflow.com/questions/72209/recursion-or-iteration)

---

**License:** The Unlicense

Feel free to use this project as a learning resource or starting point for your own tree algorithm implementations.
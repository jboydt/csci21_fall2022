// ASSIGNMENT NAME
// PROGRAMMER NAME
//
// DATE
#pragma once

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class BSTree {
public:
  // Default constructor.
  // Initialize the tree with size 0 and null root.
  BSTree() {

  }

  // Destructor.
  // Clear the tree.
  ~BSTree() {

  }

  // Returns the size (number of nodes) of this tree.
  unsigned int getSize() {

  }

  // Clear the tree of all nodes. Reset head to nullptr and size to 0.
  void clear() {

  }

  // Insert the data in the tree. Returns true if the data is not a
  // duplicate, and can be inserted. Returns false otherwise.
  bool insert(T data) {

  }

  // Find the target data in the tree. Returns true if target is found.
  // Returns false otherwise.
  bool find(T target) {

  }

  // Remove the target data from the tree. Returns true if the target
  // is found and removed. Returns false otherwise.
  bool remove(T target) {

  }

  // Return a pointer to the target data. Returns nullptr if the target
  // data is not found.
  T *get(T target) {

  }

  // Print the data in the tree to STDOUT, in-order (ascending).
  void printInOrder() {

  }

  // Print the data in the tree to STDOUT, reverse-order (descending).
  void printReverseOrder() {

  }

private:
  unsigned int size; // the number of nodes in the tree

  // A binary search tree node with constructor.
  struct Node {
    T data;
    Node *leftChild;
    Node *rightChild;

    Node(T newData) : data(newData), leftChild(nullptr), rightChild(nullptr) {}
  } * root; // the root of the tree

  // Helper functions to hide internal node pointers from the public API.

  void clear(Node *&troot) {

  }

  bool insert(T newData, Node *&troot) {

  }

  bool find(T target, Node *troot) {

  }

  bool remove(T target, Node *&troot) {

  }

  void removeMax(T &removed, Node *&troot) {

  }

  T *get(T target, Node *troot) {

  }

  void printInOrder(Node *troot) {

  }

  void printReverseOrder(Node *troot) {

  }
};

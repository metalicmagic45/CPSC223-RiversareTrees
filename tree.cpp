#include "tree.hpp"
#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::queue;


// Constructor
BinaryTree::BinaryTree() {
    root = nullptr;
}

// Destructor
BinaryTree::~BinaryTree() {
    deleteTree(root);
}

// Delete all nodes recursively
void BinaryTree::deleteTree(Node* node) {
    if (!node) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Recursive helper to add a node
Node* addNode(Node* current, string name, string type, string metadata) {
    if (current == nullptr) {
        return new Node(name, type, metadata);
    }

// Example condition: Rivers go to the left, others to the right
    if (type == "left") {
        current->left = addNode(current->left, name, type, metadata);
    } else if (type == "right") {
        current->right = addNode(current->right, name, type, metadata);
    } else {
        cout << "Invalid type, try again\n";
    }

    return current;
}

// Public add method
void BinaryTree::add(string name, string type, string metadata) {
    root = addNode(root, name, type, metadata);
}

// Inorder traversal
void BinaryTree::inorder(Node* node) {
    if (!node) return;

    // Traverse left subtree
    inorder(node->left);

    // Visit current node
    cout << node->name << " (" << node->type << "): " << node->metadata << "\n";

    inorder(node->right);
}

void BinaryTree::traversetree(string s) {
    if (s == "inorder") {
        cout << "Inorder Traversal:\n";
        inorder(root); // Start traversal from the root
    } else {
        cout << "Invalid traversal type. Only 'inorder' is supported right now.\n";
    }
}


// Display method 
void BinaryTree::display() {
  if (root == nullptr) {
    cout << "Tree is empty.\n";
    return;
  }
  cout << endl;
  printTree(root, "", false); 
}
void BinaryTree::printTree(Node *node, std::string indent, bool last) {
  if (node != nullptr) {
    std::cout << indent;
    if (last) {
      std::cout << "└── ";
      indent += "    ";
    } else {
      std::cout << "├── ";
      indent += "│   ";
    }

    std::cout << node->name << std::endl;

    printTree(node->left, indent, false); 
    printTree(node->right, indent, true);  
  }
}
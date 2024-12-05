#include "tree.hpp"
#include <iostream>

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
Node* addNode(Node* current, std::string name, std::string type, std::string metadata) {
    if (current == nullptr) {
        return new Node(name, type, metadata);
    }

// Example condition: Rivers go to the left, others to the right
    if (type == "left") {
        current->left = addNode(current->left, name, type, metadata);
    } else if (type == "right") {
        current->right = addNode(current->right, name, type, metadata);
    } else {
        std::cout << "Invalid type, try again\n";
    }

    return current;
}

// Public add method
void BinaryTree::add(std::string name, std::string type, std::string metadata) {
    root = addNode(root, name, type, metadata);
}

// Inorder traversal
void BinaryTree::inorder(Node* node) {
    if (!node) return;

    // Traverse left subtree
    inorder(node->left);

    // Visit current node
    std::cout << node->name << " (" << node->type << "): " << node->metadata << "\n";

    inorder(node->right);
}

void BinaryTree::traversetree(std::string s) {
    if (s == "inorder") {
        std::cout << "Inorder Traversal:\n";
        inorder(root); // Start traversal from the root
    } else {
        std::cout << "Invalid traversal type. Only 'inorder' is supported right now.\n";
    }
}

// Display method
void BinaryTree::display() {
    std::cout << "Display method not implemented yet.\n";
}

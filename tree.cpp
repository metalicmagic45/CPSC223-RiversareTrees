#include "tree.hpp"
#include <iostream>

// Constructor
BinaryTree::BinaryTree() {
    root = nullptr;
} 

// Destructor
BinaryTree::~BinaryTree() {
    //Implement a destructor to delete all nodes if dynamic memory is used
    deleteTree(root);
}

void::BinaryTree::deleteTree(Node*node) {
    if(!node) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Node* addNode(Node* current, std::string name, std::string type, std::string metadata) {
    // Base case: If the current node is null, create a new node
    if (current == nullptr) {
        return new Node(name, type, metadata);
    }

    // Example condition: Rivers go to the left, others to the right
    if (type == "left") {
        current->left = addNode(current->left, name, type, metadata);
    } else if(type == "right") {
        current->right = addNode(current->right, name, type, metadata);
    } else {
        std::cout << "Invalid type, try again";
    }

    return current;
}

void BinaryTree::traversetree(std::string s) {
    
}

//Display Method
void BinaryTree::display() {

}

// Public add method
void BinaryTree::add(std::string name, std::string type, std::string metadata) {
    root = addNode(root, name, type, metadata);
}

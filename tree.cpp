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

void BinaryTree::traversetree() {
    Node* current = root;
    std::string s;
    cout << "Type: 'inorder' to do inorder traversal\n";
    std::cout << "Input: ";
    std::cin >> s;
    if (s == "inorder") {
        cout << "Inorder Traversal:\n";
        inorder(root); // Start traversal from the root
    } else {
        int input;
        cout << "Input 1 or 2, 1: right, 2: left, -1: break\n";
        printTree(current,"", false);
        while(input != -1) {
            std::cout << "Input: ";
            std::cin >> input;
            if(input == 1) {  
                if(current->right == nullptr) {
                    std::cout << "End of right branch\n";
                    continue;
                }
                current = current->right;
                    printTree(current, "", false);
            } else if (input == 2) {
                if(current->left == nullptr) {
                    std::cout << "End of left branch\n";
                    continue;
                }
                current = current->left;
                    printTree(current,"", false);
            }
        }
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
            std::cout << "+-- "; // Replace "└──" with "+--"
            indent += "    ";   // Add plain spaces
        } else {
            std::cout << "|-- "; // Replace "├──" with "|--"
            indent += "|   ";   // Add a pipe and spaces
        }

        std::cout << node->name << std::endl;

        // Only print the immediate children without further recursion
        if (node->left) {
            std::cout << indent << "+-- " << node->left->name << std::endl;
        }
        if (node->right) {
            std::cout << indent << "+-- " << node->right->name << std::endl;
        }
    }
}


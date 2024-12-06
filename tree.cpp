#include "tree.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <limits>

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

void BinaryTree::deleteNode(string name) {
    root = deleteNodeRec(root, name);
}

Node* BinaryTree::deleteNodeRec(Node* node, string name) {
    if(node == nullptr) {
        cout << "Node not found. \n";
        return node;
    }

    if (node->name == name) {
        // Node with only one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            if (temp != nullptr) temp->parent = node->parent;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            if (temp != nullptr) temp->parent = node->parent;
            delete node;
            return temp;
        }

        // Node with two children: find the in-order successor 
        Node* successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left; // Traverse to the leftmost node
        }
        // Replace current node's data with the successor's data
        node->name = successor->name;
        node->type = successor->type;
        node->metadata = successor->metadata;

         // Delete the successor node
        node->right = deleteNodeRec(node->right, successor->name);
    } else if (node->type == "left") { 
        node->left = deleteNodeRec(node->left, name);
    } else if( node -> type == "right") {
        node->right = deleteNodeRec(node->right, name);
    } else {
        cout << "Invalid Node Type. \n";
    }

    return node;


}


// Recursive helper to add a node with a parent
Node* addNode(Node* current, Node* parent, string name, string type, string metadata) {
    if (current == nullptr) {
        Node* newNode = new Node(name, type, metadata);
        newNode->parent = parent;  // Set the parent of the new node
        return newNode;
    }

    // Example condition: Rivers go to the left, others to the right
    if (type == "left") {
        current->left = addNode(current->left, current, name, type, metadata);
    } else if (type == "right") {
        current->right = addNode(current->right, current, name, type, metadata);
    } else {
        cout << "Invalid type, try again\n";
    }

    return current;
}

void BinaryTree::addAt(Node* start, Node* parent, string name, string type, string metadata) {
    if(start == nullptr) {
        if(root == nullptr) {
            root = addNode(start, start->parent, name, type, metadata);
        } else {
            std::cout << "Cannot add root node.";
        }
    } else {
        addNode(start, start->parent, name, type, metadata); //Add at node
    }
}

// Public add method
void BinaryTree::add(string name, string type, string metadata) {
    root = addNode(root, nullptr, name, type, metadata);  // Start with no parent (root has no parent)
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
        cout << "Input integers, 1: right, 2: left, 3: parent, 4: add(if allowed), -1: break\n";
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
            } else if (input == 3) {
                if(current == root) {
                    std::cout << "At root\n";
                    continue;
                }
                current = current->parent;
                printTree(current, "", false);
            } else if (input == 4) {
                std::string name;
                std::string t;
                std::string metadata;
                if((current->left != nullptr) && (current->right != nullptr)) {
                    std::cout << "Not allowed to add\n";
                    continue;
                }
                std::cout << "You can add, enter inputs:\n";
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter left or right: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> t;
                if(t == "left" && current->left != nullptr) {
                    std::cout << "Not allowed";
                    continue;
                }
                if(t == "right" && current->right != nullptr) {
                    std::cout << "Not allowed";
                    continue;
                }
                std::cout << "Enter metadata: ";
                std::cin >> metadata; 
                addAt(current, current->parent, name, t, metadata);
                printTree(current, "", false);
            } else {
                std::cout << "Invalid input: Breaking";
                break;
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


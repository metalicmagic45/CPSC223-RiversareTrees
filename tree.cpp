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

Node* BinaryTree:: getRoot() {
    return root;
}

void BinaryTree::deleteNode(string name) {
    cout << "Deleting " << name << std::endl;
    root = deleteNodeRec(root, name);
}

Node* BinaryTree::deleteNodeRec(Node* node, const string &name) {
    if (node == nullptr) {
        // Node not found
        return nullptr;
    }

    if (node->name == name) {
        // If we've found the node, delete its entire subtree
        deleteTree(node); // deleteTree(node) deletes node and all its descendants
        return nullptr;   // Return nullptr so parent's pointer to this node is cleared
    }

    // Recursively search the left subtree
    node->left = deleteNodeRec(node->left, name);
    // Recursively search the right subtree
    node->right = deleteNodeRec(node->right, name);

    // If we reach here, it means we didn't find the node in this path,
    // so just return the node unchanged.
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

// Preorder traversal (Root, Left, Right)
void BinaryTree::preorder(Node* node) {
    if (!node) return;

    cout << node->name << " (" << node->type << "): " << node->metadata << "\n";
    preorder(node->left);
    preorder(node->right);
}

// Postorder traversal (Left, Right, Root)
void BinaryTree::postorder(Node* node) {
    if (!node) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->name << " (" << node->type << "): " << node->metadata << "\n";
}

Node* BinaryTree::searchNode(Node* current, const string& name) {
    if (!current) return nullptr;  // Base case: node not found

    if (current->name == name) return current;  // Node found

    // Search recursively in the left and right subtrees
    Node* found = searchNode(current->left, name);
    if (found) return found;  // If found in left subtree, return it

    return searchNode(current->right, name);  // Otherwise, search in the right subtree
}


void BinaryTree::traversetree() {
    Node* current = root;
    std::string s;
    cout << "Type: 'inorder' to do inorder traversal. Type something else to go to tree traversal\n";
    std::cout << "Input: ";
    std::cin >> s;
if (s == "inorder") {
    cout << "Inorder Traversal:\n";
    inorder(root); // Start traversal from the root
} else if (s == "preorder") { // Preorder
    cout << "\nPreorder Traversal:\n";
    preorder(root);
} else if (s == "postorder") { // Postorder
    cout << "\nPostorder Traversal:\n";
    postorder(root);
} else {
        int input;
        cout << "Input integers, 1: right, 2: left, 3: parent, 4: add(if allowed), 5: delete, 6: search, -1: break\n";
        printTree(current,"", false);
        while(input != -1) {
            if (root == nullptr) {
                cout << "Tree is empty\n";
                current = nullptr; // No more nodes to traverse
            }  
            std::cout << "Input: ";
            std::cin >> input;
            if(root == nullptr) {
                if(input == -1) {
                    break;
                }
                if(input == ((1) || (2) || (3) || (4) || (5))) {
                    std::cout << "Not allowed, tree empty\n";
                    continue;
                }
            }
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
            } else if(input == 5) {
                if(current == nullptr) {
                    cout << "Node doesn't exist\n";
                    continue;
                }
                deleteNode(current->name);  
            } else if (input == 6) { // Search option
                cout << "Enter the name of the node to search for: ";
                string nodeName;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, nodeName); // Allow multi-word names

                Node* target = searchNode(root, nodeName);
                if (target) {
                    cout << "Found Node: " << target->name << " (" << target->type
                         << "): " << target->metadata << "\n";
                } else {
                    cout << "Node not found.\n";
                }
            } else if (input == -1) {
                break;
            } else {
                std::cout << "Invalid input: Breaking\n";
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


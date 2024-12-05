#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>

struct Node {
    std::string name;       // Name of the water body or dam
    std::string type;       // Type (e.g., River, Lake, Dam)
    std::string metadata;   // Metadata (e.g., length, capacity, etc.)
    Node* left;             // Left child
    Node* right;            // Right child

    // Constructor
    Node(std::string n, std::string t, std::string m) {
        name = n;     
        type = t;
        metadata = m;     
        left = nullptr;     
        right = nullptr;
    } 
};

class BinaryTree {
private:
    Node* root; // Root of the binary tree

    // Private traversal helper methods
    void inorder(Node* node);    // Inorder Traversal (Left, Root, Right)
    void preorder(Node* node);   // Preorder Traversal (Root, Left, Right)
    void postorder(Node* node);  // Postorder Traversal (Left, Right, Root)

public:
    // Constructor
    BinaryTree();

    // Destructor
    ~BinaryTree();

    // Add a node to the tree
    void add(std::string name, std::string type, std::string metadata);

    // Display the tree structure
    void display();

    // Search for a specific feature
    void search(std::string name);

    // Delete the tree
    void deleteTree(Node*node);

    // Traverse the tree
    void traversetree(std::string input);
};

#endif // BINARYTREE_HPP
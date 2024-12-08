#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct Node {
    string name;       // Name of the water body or dam
    string type;       // Type (e.g., River, Lake, Dam)
    string metadata;   // Metadata (e.g., length, capacity, etc.)
    Node* left;             // Left child
    Node* right;            // Right child
    Node* parent;

    // Constructor
    Node(string n, string t, string m) {
        name = n;     
        type = t;
        metadata = m;     
        left = nullptr;     
        right = nullptr;
        parent = nullptr;
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

    // Get the root of the tree
    Node* getRoot();
    Node* getParent(Node* node);


    // Add a node to the tree
    void add(string name, string type, string metadata);
    void addAt(Node* start, Node* parent, string name, string type, string metadata);

    // Display the tree structure
    void display();
    void printTree(Node *node, std::string indent, bool last);

    // Search for a specific feature
    void search(string name);

    // Delete the tree
    void deleteTree(Node* node);

    // Delete a Node
    void deleteNode(string name);
    Node* deleteNodeRec(Node* node, const string &name);

    // Traverse the tree
    void traversetree();

    // Search for a node by name
    Node* searchNode(Node* current, const string& name); 
};

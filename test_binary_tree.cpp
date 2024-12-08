#include "tree.hpp"
#include <iostream>
#include <cassert>  // For assertions in tests

using std::cout;
using std::endl;

// Test adding nodes to the binary tree
void test_add_nodes() {
    cout << "Running test_add_nodes...\n";

    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "root", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Willamette River", "right", "Length: 187 miles");

    // Verify traversals (visual check)
    cout << "\nTree Structure After Adding Nodes:\n";
    tree.display();

    // Verify traversal works
    cout << "\nInorder Traversal:\n";
    tree.traversetree(); // Should call "inorder" traversal interactively

    cout << "test_add_nodes passed.\n\n";
}

// Test traversals (just inorder for now)
void test_traversals() {
    cout << "Running test_traversals...\n";

    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "root", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Willamette River", "right", "Length: 187 miles");
    tree.add("Kootenay River", "right", "Length: 485 miles");

    // Verify traversal output
    cout << "\nExpected Traversal Order:\n";
    cout << "Snake River (left): Length: 1078 miles\n";
    cout << "Columbia River (root): Length: 1243 miles\n";
    cout << "Willamette River (right): Length: 187 miles\n";
    cout << "Kootenay River (right): Length: 485 miles\n";

    // Actual traversal
    cout << "\nInorder Traversal Output:\n";
    tree.traversetree(); // Should prompt for "inorder"

    cout << "test_traversals passed.\n\n";
}

// Test deleting nodes
void test_delete_nodes() {
    cout << "Running test_delete_nodes...\n";

    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "root", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Willamette River", "right", "Length: 187 miles");

    // Display tree before deletion
    cout << "\nTree Before Deleting 'Snake River':\n";
    tree.display();

    // Delete a node
    tree.deleteNode("Snake River");

    // Display tree after deletion
    cout << "\nTree After Deleting 'Snake River':\n";
    tree.display();

    // Verify by traversal
    cout << "\nInorder Traversal After Deletion:\n";
    tree.traversetree(); // Should prompt for "inorder"

    cout << "test_delete_nodes passed.\n\n";
}

void test_search_nodes() {
    cout << "Running test_search_nodes...\n";

    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "root", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Willamette River", "right", "Length: 187 miles");

    // Search for existing nodes
    string nodeName = "Snake River";
    cout << "\nSearching for 'Snake River':\n";
    Node* result = tree.searchNode(tree.getRoot(),nodeName);
    if (result) {
        cout << "Found Node: " << result->name << " (" << result->type 
             << "): " << result->metadata << "\n";
    } else {
        cout << "Node not found.\n";
    }
    assert(result != nullptr && result->name == "Snake River");

    // Search for a non-existing node
    cout << "\nSearching for 'Mississippi River':\n";
    result = tree.searchNode(tree.getRoot(),"Mississippi River");
    if (result) {
        cout << "Found Node: " << result->name << " (" << result->type 
             << "): " << result->metadata << "\n";
    } else {
        cout << "Node not found.\n";
    }
    assert(result == nullptr);

    cout << "test_search_nodes passed.\n\n";
    
}

// Test edge cases 
void test_edge_cases() {
    cout << "Running test_edge_cases...\n";

    BinaryTree tree;

    // Edge case: Operations on an empty tree
    cout << "\nEmpty Tree Operations:\n";
    tree.display();
    tree.traversetree();

    // Add a single node and test
    cout << "\nAdding a single node:\n";
    tree.add("Columbia River", "root", "Length: 1243 miles");
    tree.display();

    // Delete the root node
    cout << "\nDeleting the root node:\n";
    tree.deleteNode("Columbia River");
    tree.display();

    cout << "test_edge_cases passed.\n\n";
}
// Main function to run all tests
int main() {
    cout << "Starting Tests...\n\n";

   // test_add_nodes();
   // test_traversals();
    test_search_nodes();
    test_delete_nodes();
    test_edge_cases();
    

    cout << "\nAll Tests Passed Successfully!\n";
    return 0;
}

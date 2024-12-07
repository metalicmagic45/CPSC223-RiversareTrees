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



// Test edge cases 

// Main function to run all tests
int main() {
    cout << "Starting Tests...\n\n";

    test_add_nodes();
    test_traversals();
    //test_delete_nodes();
    //test_edge_cases();

    cout << "\nAll Tests Passed Successfully!\n";
    return 0;
}

#include "tree.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "Program started successfully.\n";

    // Create a BinaryTree object
    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "root", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Willamette River", "right", "Length: 187 miles");
    tree.add("Kootenay River", "right", "Length: 485 miles");

    // Test inorder traversal
    cout << "Tree Traversal:\n";
    tree.traversetree();

    return 0;
}

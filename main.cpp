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
    tree.add("Kootenay River", "left", "Length: 485 miles");
    tree.add("Pend Oreille River", "right", "Length: 130 miles");
    tree.add("Spokane River", "left", "Length: 111 miles");
    tree.add("Yakima River", "right", "Length: 214 miles");
    tree.add("Deschutes River", "left", "Length: 252 miles");
    tree.add("Cowlitz River", "right", "Length: 105 miles");
    tree.add("John Day River", "left", "Length: 284 miles");

    // Test inorder traversal
    cout << "Tree Traversal:\n";
    tree.traversetree();

    return 0;
}

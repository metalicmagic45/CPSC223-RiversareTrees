#include "tree.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {

    cout << "Program started successfully.\n";
    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "right", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Grand Coulee Dam", "right", "Capacity: 9.26 million acre-feet");
    tree.add("Bonneville Dam", "right", "Capacity: 537,000 acre-feet");

    // Test inorder traversal
    tree.traversetree();

    return 0;
}


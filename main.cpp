#include "tree.hpp"
#include <iostream>

int main() {
    std::cout << "Program started successfully.\n";
    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "right", "Length: 1243 miles");
    tree.add("Snake River", "left", "Length: 1078 miles");
    tree.add("Grand Coulee Dam", "right", "Capacity: 9.26 million acre-feet");
    tree.add("Bonneville Dam", "right", "Capacity: 537,000 acre-feet");

    // Test inorder traversal
    tree.traversetree("inorder");

    return 0;
}

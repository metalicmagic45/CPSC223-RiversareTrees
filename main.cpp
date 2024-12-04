#include "tree.hpp"
#include<iostream>

int main() {
    BinaryTree tree;

    // Add nodes to the tree
    tree.add("Columbia River", "River", "Length: 1243 miles");
    tree.add("Snake River", "River", "Length: 1078 miles");
    tree.add("Grand Coulee Dam", "Dam", "Capacity: 9.26 million acre-feet");
    tree.add("Bonneville Dam", "Dam", "Capacity: 537,000 acre-feet");

    // Display tree structure (to be implemented)
    tree.display();

    return 0;
}

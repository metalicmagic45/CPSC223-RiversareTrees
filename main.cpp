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

    tree.add("Columbia River", "root", "Length: 1243 miles, Dam: Bonneville Dam"); 

    // Add major tributaries using addAt and searchNode
    Node* columbia = tree.searchNode(tree.getRoot(), "Columbia River"); 

    // Level 2
    tree.addAt(columbia, tree.getParent(columbia), "Willamette River", "left", "Length: 301 miles, Dam: Detroit Dam, Confluence: Willamette Falls"); 
    tree.addAt(columbia, tree.getParent(columbia), "Snake River", "right", "Length: 1078 miles, Dam: Hells Canyon Dam"); 

    // Level 3
    Node* willamette = tree.searchNode(tree.getRoot(), "Willamette River"); 
    Node* snake = tree.searchNode(tree.getRoot(), "Snake River");
    tree.addAt(willamette, tree.getParent(willamette), "McKenzie River", "left", "Length: 90 miles, Dam: Cougar Dam");
    tree.addAt(willamette, tree.getParent(willamette), "Clackamas River", "right", "Length: 83 miles, Dam: North Fork Dam"); 
    tree.addAt(snake, tree.getParent(snake), "Clearwater River", "left", "Length: 75 miles, Dam: Dworshak Dam");
    tree.addAt(snake, tree.getParent(snake), "Salmon River", "right", "Length: 425 miles"); 

    // Level 4
    Node* mckenzie = tree.searchNode(tree.getRoot(), "McKenzie River");
    Node* clackamas = tree.searchNode(tree.getRoot(), "Clackamas River");
    Node* clearwater = tree.searchNode(tree.getRoot(), "Clearwater River");
    Node* salmon = tree.searchNode(tree.getRoot(), "Salmon River");
    tree.addAt(mckenzie, tree.getParent(mckenzie), "Blue River", "left", "Length: 27 miles");  
    tree.addAt(clackamas, tree.getParent(clackamas), "Oak Grove Fork Clackamas River", "left", "Length: Unknown"); 
    tree.addAt(clearwater, tree.getParent(clearwater), "North Fork Clearwater River", "left", "Length: 75 miles"); 
    tree.addAt(clearwater, tree.getParent(clearwater), "Middle Fork Clearwater River", "right", "Length: 86 miles, Confluence: Kooskia, Idaho"); 
    tree.addAt(salmon, tree.getParent(salmon), "Middle Fork Salmon River", "left", "Length: 104 miles"); 
    tree.addAt(salmon, tree.getParent(salmon), "South Fork Salmon River", "right", "Length: 86 miles"); 

    // Level 5 
    Node* blue = tree.searchNode(tree.getRoot(), "Blue River");
    Node* northForkClearwater = tree.searchNode(tree.getRoot(), "North Fork Clearwater River");
    Node* middleForkClearwater = tree.searchNode(tree.getRoot(), "Middle Fork Clearwater River");
    Node* middleForkSalmon = tree.searchNode(tree.getRoot(), "Middle Fork Salmon River"); 
    tree.addAt(blue, tree.getParent(blue), "South Fork McKenzie River", "left", "Length: Unknown"); 
    tree.addAt(northForkClearwater, tree.getParent(northForkClearwater), "Lochsa River", "left", "Length: 70 miles"); 
    tree.addAt(middleForkClearwater, tree.getParent(middleForkClearwater), "Lochsa River", "right", "Length: 70 miles, Confluence: Lowell, Idaho"); 
    tree.addAt(middleForkSalmon, tree.getParent(middleForkSalmon), "Little Salmon River", "left", "Length: 161 miles"); 



    // Test inorder traversal
    cout << "Tree Traversal:\n";
    tree.traversetree();

    return 0;
}

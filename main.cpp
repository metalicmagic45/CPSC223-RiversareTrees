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



    // Add the Columbia River as the root (using add)
    tree.add("Columbia River", "root", "Length: 1243 miles, Dam: Bonneville Dam (Washington/Oregon border)");

    // Add major tributaries using addAt and getParent
    Node* columbia = tree.getRoot(); 

    // Left tributaries
    tree.addAt(columbia, tree.getParent(columbia), "Snake River", "left", "Length: 1078 miles, Dam: Hells Canyon Dam (Idaho/Oregon border)");
    tree.addAt(columbia, tree.getParent(columbia), "John Day River", "right", "Length: 281 miles, Dam: John Day Dam (Oregon/Washington border)");

    // Snake River tributaries
    Node* snake = tree.searchNode(tree.getRoot(), "Snake River"); 
    tree.addAt(snake, tree.getParent(snake), "Clearwater River", "right", "Length: 74 miles");
    tree.addAt(snake, tree.getParent(snake), "Salmon River", "left", "Length: 425 miles");

    // Clearwater River tributaries
    Node* clearwater = tree.searchNode(tree.getRoot(), "Clearwater River");
    tree.addAt(clearwater, tree.getParent(clearwater), "North Fork Clearwater River", "left", "Length: 75 miles");
    tree.addAt(clearwater, tree.getParent(clearwater), "Little North Fork Clearwater River", "right", "Length: 35 miles");

    // North Fork Clearwater River tributaries
    Node* northForkClearwater = tree.searchNode(tree.getRoot(), "North Fork Clearwater River");
    tree.addAt(northForkClearwater, tree.getParent(northForkClearwater), "Kelly Creek", "right", "Length: 25 miles");
    tree.addAt(northForkClearwater, tree.getParent(northForkClearwater), "Orofino Creek", "left", "Length: 21 miles");

    // Salmon River tributaries
    Node* salmon = tree.searchNode(tree.getRoot(), "Salmon River");
    tree.addAt(salmon, tree.getParent(salmon), "Middle Fork Salmon River", "right", "Length: 113 miles");
    tree.addAt(salmon, tree.getParent(salmon), "South Fork Salmon River", "left", "Length: 61 miles");

    // Middle Fork Salmon River tributaries
    Node* middleForkSalmon = tree.searchNode(tree.getRoot(), "Middle Fork Salmon River");
    tree.addAt(middleForkSalmon, tree.getParent(middleForkSalmon), "Valley Creek", "left", "Length: 17 miles");
    tree.addAt(middleForkSalmon, tree.getParent(middleForkSalmon), "Bear Valley Creek", "right", "Length: 31 miles");

    // John Day River tributaries
    Node* johnDay = tree.searchNode(tree.getRoot(), "John Day River");
    tree.addAt(johnDay, tree.getParent(johnDay), "North Fork John Day River", "left", "Length: 122 miles");
    tree.addAt(johnDay, tree.getParent(johnDay), "Middle Fork John Day River", "right", "Length: 63 miles");

    // North Fork John Day River tributaries
    Node* northForkJohnDay = tree.searchNode(tree.getRoot(), "North Fork John Day River");
    tree.addAt(northForkJohnDay, tree.getParent(northForkJohnDay), "Desolation Creek", "right", "Length: 15 miles");
    tree.addAt(northForkJohnDay, tree.getParent(northForkJohnDay), "Camas Creek", "left", "Length: 14 miles");

    // Desolation Creek tributaries
    Node* desolationCreek = tree.searchNode(tree.getRoot(), "Desolation Creek");
    tree.addAt(desolationCreek, tree.getParent(desolationCreek), "Big Creek", "left", "Length: 11 miles");
    tree.addAt(desolationCreek, tree.getParent(desolationCreek), "Granite Creek", "right", "Length: 11 miles");

    // Middle Fork John Day River tributaries
    Node* middleForkJohnDay = tree.searchNode(tree.getRoot(), "Middle Fork John Day River");
    tree.addAt(middleForkJohnDay, tree.getParent(middleForkJohnDay), "Lake Creek", "left", "Length: 14 miles");
    tree.addAt(middleForkJohnDay, tree.getParent(middleForkJohnDay), "South Fork John Day River", "right", "Length: 74 miles");



    // Test inorder traversal
    cout << "Tree Traversal:\n";
    tree.traversetree();

    return 0;
}

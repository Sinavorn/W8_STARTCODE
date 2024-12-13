#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;

    bst.insert(7);
    bst.insert(5);
    bst.insert(9);
    bst.insert(1);
    bst.insert(6);
    bst.insert(8);
    bst.insert(11);

    std::cout<< "In-order traversal of the BST: ";
    bst.inOrder();

    std::cout<<"Searching for 7 in the BST: " ;
    int searchValue = 7;
    if (bst.search(searchValue)){
        std::cout<<" found in the BST."<<std::endl;
    }else {
        std::cout<<" not found in the BST."<<std::endl;
    }

    std::cout <<"Deleting 5 from the BST." << std::endl;
    bst.deleteNode(5);

    std::cout <<"In-order traversal after deletion: ";
    bst.inOrder();
    return 0;
}

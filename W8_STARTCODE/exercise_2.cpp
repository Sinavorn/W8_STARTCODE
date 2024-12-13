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
    std::cout<<"Level-Order Traversal: " <<bst.levelOrderTraverse() <<std::endl;
    return 0;
}

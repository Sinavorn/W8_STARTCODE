#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include <queue>

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

public:
    //exercise 1
    bool search(Node* root, int key){
        //your code here
       if (!root) return false;
       if (root->data ==key) return true;
       if (key< root->data){
        return search(root->left,key);
       }else{
        return search(root->right,key);
       }
           
    }
    bool search(int value){
        return search(root, value);
    }
    void insert(Node* &root, int newValue) {
        //your code here
        if (!root){
            root = new Node(newValue);
            return;
        }
        if (newValue< root->data){
            insert(root->left,newValue);
        }
        else if (newValue> root->data){
            insert(root->right,newValue);
        }   
    }
    void insert(int newValue){
        insert(root,newValue);

    }
    Node* deleteNode(Node* &root, int value){
        //your code here
        if (!root) return root;
        if (value<root->data){
            root->left = deleteNode(root->left,value);
        }else if (value>root->data){
            root->right = deleteNode(root->right,value); 

        }else{
            if (!root->left){
              Node* temp= root->right;
              delete root;
              return temp; 
            }else if (!root->right){
              Node* temp = root->left;
              delete root;
              return temp;    
            }

            Node* temp = findMin(root->right);
            root->data = temp->data; 
            root->right = deleteNode(root->right, temp->data); 
        }
        return root;          
    }
    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left; // Traverse to the leftmost node
        }
        return node;
    }
    void deleteNode(int value) {
        deleteNode(root, value);
    }
    void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
    }
    void inOrder() {
    inOrder(root);
    std::cout << std::endl;
    }

    //exercise 2
    std::string levelOrderTraverse() {
        std::string result = "";
        //your code here
        //Important note: you are allowed to use the std::queue class to implement this function
        std::queue<Node*> q; 
        q.push(root);              
        while (!q.empty()){
            Node* current =q.front();
            q.pop();                   
            result += std::to_string(current->data) + " "; 

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        return result;
    }
    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
    

};

#endif // BINARYTREE_H
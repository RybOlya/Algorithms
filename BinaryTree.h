//
// Created by RybOlya on 25.09.2022.
//

#ifndef UNTITLED_BINARYTREE_H
#define UNTITLED_BINARYTREE_H


#include <iostream>
#include <fstream>
#include "vector"
#include <map>
using namespace std;

template <typename T>
class Node {
public:
    T keyValue;
    Node* leftPtr;
    Node* rightPtr;
    explicit Node(T key);
};
template <typename T>
class BinaryTree {
public:

    Node<T>* root = nullptr;
    map<int,vector<T>> pathsMap;
    void insert(T vertex);
    void inorder();
    void minDepth();

    void readFromFile(const string& filePath);
    void writeMinPath();
private:
    void printInorder(Node<T>* node);
    Node<T>* insertNode(Node<T>* node, T vertex);
    void pathMin(Node<T> *node, vector<T> pathToLeaf);

};


#endif //UNTITLED_BINARYTREE_H

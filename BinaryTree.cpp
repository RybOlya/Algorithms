//
// Created by RybOlya on 25.09.2022.
//

#include "BinaryTree.h"

template<typename T>
Node<T>::Node(T key) {
    keyValue = key;
    leftPtr = nullptr;
    rightPtr = nullptr;
}

template<typename T>
void BinaryTree<T>::insert(T vertex) {
    root = insertNode(root, vertex);
}
template<typename T>
void BinaryTree<T>::inorder() {
    printInorder(root);
    cout << endl;
}
template<typename T>
void BinaryTree<T>::minDepth() {
    vector<int> nums;
    pathMin(root, nums);
    cout<< "Minimal depth: "<<pathsMap.begin()->first<<"\n";

    cout << "Minimal path: ";
    for (auto& c: pathsMap.begin()->second) {
        cout << c << " ";
    }
    cout << endl;
}

template<typename T>
void BinaryTree<T>::printInorder(Node<T> *node) {
    if (node == nullptr) return;
    printInorder(node->leftPtr);
    cout << node->keyValue << " \n";
    printInorder(node->rightPtr);
}


template<typename T>
Node<T> *BinaryTree<T>::insertNode(Node<T> *node, T vertex) {
    if (node == nullptr)
    {
        auto* temp = new Node<T>(vertex);
        return temp;
    }
    if (vertex < node->keyValue) node->leftPtr = insertNode(node->leftPtr, vertex);
    else if (vertex > node->keyValue) node->rightPtr = insertNode(node->rightPtr, vertex);
    return node;
}
template<typename T>
void BinaryTree<T>::pathMin(Node<T> *node, vector<T> pathToLeaf) {
    if (node == nullptr)
    {
        return;
    }
    pathToLeaf.push_back(node->keyValue);
    if (node->leftPtr == nullptr && node->rightPtr == nullptr)
    {
        pathsMap[pathToLeaf.size()] = pathToLeaf;
    }
    else
    {
        pathMin(node->leftPtr,pathToLeaf );
        pathMin(node->rightPtr,pathToLeaf );
    }
}

template<typename T>
void BinaryTree<T>::writeMinPath() {
    ofstream outfile (R"(C:\Users\RybOlya\CLionProjects\untitled\sources\output.txt)");
    outfile<< "Minimal depth: "<<pathsMap.begin()->first<<"\n";
    outfile << "Minimal path: ";
    for (auto& c: pathsMap.begin()->second) {
        outfile << c << " ";
    }
    outfile << endl;
    outfile.close();
}

template<typename T>
void BinaryTree<T>::readFromFile(const string& filePath) {
    std::ifstream infile(filePath);
    cout<<filePath;
    int vertexStart,vertexEnd;
    if (infile.is_open())
    {
        cout << "File successfully open" << endl;
        while (infile >> vertexStart && infile >> vertexEnd)
        {
            cout<<vertexStart<<" "<< vertexEnd<<"\n";
            insert(vertexStart);
            insert(vertexEnd);
        }
        inorder();
    }
    else
    {
        cout << "Error opening file";
    }
}

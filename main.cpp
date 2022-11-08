#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <iostream>


int main()
{
    BinaryTree<int> binaryTree;
    binaryTree.readFromFile(R"(C:\Users\RybOlya\CLionProjects\untitled\sources\input.txt)");
    binaryTree.minDepth();
    binaryTree.writeMinPath();
}
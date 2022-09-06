#include <iostream>

using namespace std;

template <typename T>

class AVLTree {
public:
    class Node {
    public:
        T keyValue;
        Node* leftPtr;
        Node* rightPtr;
        int height;
        Node(T key) {
            height = 1;
            keyValue = key;
            leftPtr = nullptr;
            rightPtr = nullptr;
        }
    };
    Node* root = nullptr;
    void insert(T newNodeKey) {
        root = insertNode(root, newNodeKey);
    }
    void remove(T newNodeKey) {
        root = removeNode(root, newNodeKey);
    }
    void inorder() {
        printInorder(root);
        cout << endl;
    }
private:
    int height(Node* node)
    {
        if (node == nullptr) return 0;
        return node->height;
    }
    Node* rightRotation(Node* node) {
        Node* newNode = node->leftPtr;
        node->leftPtr = newNode->rightPtr;
        newNode->rightPtr = node;
        node->height = 1 + max(height(node->leftPtr), height(node->rightPtr));
        newNode->height = 1 + max(height(newNode->leftPtr), height(newNode->rightPtr));
        return newNode;
    }
    Node* leftRotation(Node* node) {
        Node* newNode = node->rightPtr;
        node->rightPtr = newNode->leftPtr;
        newNode->leftPtr = node;
        node->height = 1 + max(height(node->leftPtr), height(node->rightPtr));
        newNode->height = 1 + max(height(newNode->leftPtr), height(newNode->rightPtr));
        return newNode;
    }
    void printInorder(Node* node) {
        if (node == nullptr) return;
        printInorder(node->leftPtr);
        cout << node->keyValue << " ";
        printInorder(node->rightPtr);
    }
    Node* insertNode(Node* node, T newNodeKey)
    {
        if (node == nullptr)
        {
            Node* temp = new Node(newNodeKey);
            return temp;
        }
        if (newNodeKey < node->keyValue) node->leftPtr = insertNode(node->leftPtr, newNodeKey);
        else if (newNodeKey > node->keyValue) node->rightPtr = insertNode(node->rightPtr, newNodeKey);
        node->height = 1 + max(height(node->leftPtr), height(node->rightPtr));
        int balanceFactor = height(node->leftPtr) - height(node->rightPtr);
        if (balanceFactor > 1)
        {
            if (newNodeKey < node->leftPtr->keyValue)
            {
                return rightRotation(node);
            }
            else {
                node->leftPtr = leftRotation(node->leftPtr);
                return rightRotation(node);
            }

        }
        else if (balanceFactor < -1)
        {
            if (newNodeKey > node->rightPtr->keyValue) {
                return leftRotation(node);
            }
            else {
                node->rightPtr = rightRotation(node->rightPtr);
                return leftRotation(node);
            }
        }
        return node;
    }
    Node* findNode(Node* node, T newNodeKey)
    {
        if(node == nullptr) return nullptr;
        if(newNodeKey == node->keyValue) return node;
        if(newNodeKey < node->keyValue) return findNode(node->leftPtr, newNodeKey);
        if(newNodeKey > node->keyValue) return findNode(node->rightPtr, newNodeKey);

    }
    Node* removeNode(Node* node, T newNodeKey) {
        if(node==nullptr) return nullptr;
        if(newNodeKey < node->keyValue){
            node->leftPtr = removeNode(node->leftPtr, newNodeKey);
        }else if(newNodeKey > node->keyValue){
            node->rightPtr = removeNode(node->rightPtr, newNodeKey);
        }else {
            Node *r = node->rightPtr;
            Node *l = node->leftPtr;
            if (r == nullptr) {
                delete (node);
                node = l;
            } else if (l == nullptr) {
                delete (node);
                node = r;
            } else {
                while (r->leftPtr != nullptr) r = r->leftPtr;
                node->keyValue = r->keyValue;
                node->rightPtr = removeNode(node->rightPtr, r->keyValue);
            }
        }
        if (node == nullptr)return node;
        node->height = 1 + max(height(node->leftPtr), height(node->rightPtr));
        int balanceFactor = height(node->leftPtr) - height(node->rightPtr);
        if (balanceFactor > 1) {
            if (height(node->leftPtr) >= height(node->rightPtr)) {
                return rightRotation(node);
            } else {
                node->leftPtr = leftRotation(node->leftPtr);
                return rightRotation(node);
            }

        } else if (balanceFactor < -1) {
            if (height(node->rightPtr) >= height(node->leftPtr)) {
                return leftRotation(node);
            } else {
                node->rightPtr = rightRotation(node->rightPtr);
                return leftRotation(node);
            }
        }
        return node;
    }
};
int main()
{
    AVLTree<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(16);
    avlTree.insert(23);
    avlTree.insert(81);
    avlTree.insert(3);
    avlTree.insert(130);
    avlTree.insert(130);
    avlTree.inorder();
    avlTree.remove(5);
    avlTree.remove(81);
    avlTree.inorder();

}
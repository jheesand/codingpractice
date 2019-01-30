#pragma once
#include <vector>
#include <iostream>
#include <queue>

#include "treenode.h"
template <typename T>
class BST {
    public:
        BST() : root_(0) {}
        ~BST() {
            deleteTree_(root_);
        }
        BST(std::vector<T> const& sortedArr);
        void printBreadthTree();
    private:
        //depth post order traversal before deletion
        void deleteTree_(Tree::BNode<T>* root);
        Tree::BNode<T>* createMidNodeRecursive_(std::vector<T> const& sortedArr, unsigned leftIndex, unsigned rightIndex);
        Tree::BNode<T>* root_;
};

template <typename T>
Tree::BNode<T>* BST<T>::createMidNodeRecursive_(std::vector<T> const& sortedArr, unsigned leftIndex, unsigned endIndex) {
    if (leftIndex == endIndex) {
        return 0;
    }

    unsigned midIndex  = (leftIndex + endIndex) / 2;
    Tree::BNode<T>* mid = new Tree::BNode<T>(sortedArr[midIndex]);
    Tree::BNode<T>* left = createMidNodeRecursive_(sortedArr, leftIndex, midIndex);
    Tree::BNode<T>* right = createMidNodeRecursive_(sortedArr, midIndex + 1, endIndex);
    mid->setLeftNode(left);
    mid->setRightNode(right);

    return mid;
}

template <typename T>
BST<T>::BST(std::vector<T> const& sortedArr) {
    root_ = createMidNodeRecursive_(sortedArr, 0, sortedArr.size());
}

template <typename T>
void BST<T>::deleteTree_(Tree::BNode<T>* root) {
    if (root == 0) {
        return;
    }

    deleteTree_(root->getLeftNode());
    deleteTree_(root->getRightNode());
    delete root;
    root = 0;
}

template <typename T>
void BST<T>::printBreadthTree() {
    std::queue<Tree::BNode<T>* > nodeContainer;
    nodeContainer.push(root_);
    std::cout << "Printing tree: "<< std::endl;
    while (!nodeContainer.empty()) {
        Tree::BNode<T>* node = nodeContainer.front();
        nodeContainer.pop();
        std::cout << node->getValue() << " ";

        std::pair<Tree::BNode<T>*, Tree::BNode<T>* > children = node->getChildren();
        if (children.first) {
            nodeContainer.push(children.first);
        }

        if (children.second) {
            nodeContainer.push(children.second);
        }
    }
}
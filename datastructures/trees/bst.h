#pragma once
#include <array>
#include "treenode.h"
template <typename T>
class BST {
    public:
        BST() : root_(NULL) {}
        ~BST() {}
        BST(std::array<T> const& sortedArr);
    private:
        Tree:BNode<T>* createMidNodeRecursive_(std::array<T> const& sortedArr, unsigned leftIndex, unsigned size);
        Tree:BNode<T>* root_;
};

template <typename T>
Tree::BNode<T>* createMidNodeRecursive_(std::array<T> const& sortedArr, unsigned leftIndex, unsigned size) {
    if (size == 1) {
        return new Tree::Node<T>(sortedArr[leftIndex]);
    }
    else if (size == 0) {
        return NULL;
    }

    unsigned midIndex  = (leftIndex + size) / 2;
    Tree::BNode<T>* mid = new Tree::Node<T>(sortedArr[midIndex])
    Tree::BNode<T>* left = createMidNodeRecursive_(sortedArr, leftIndex, midIndex);
    Tree::BNode<T>* right = createMidNodeRecursive_(sortedArr, midIndex + 1, size - midIndex + 1);
    mid->setLeftNode(left);
    mid->setRightNode(right);

    return mid;
}

template <typename T>
BST<T>::BST(std::array<T> const& sortedArr) {
    root_ = createMidNodeRecursive_(sortedArr, 0, sortedArr.size());
}
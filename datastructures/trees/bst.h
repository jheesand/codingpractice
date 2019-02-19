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
		bool validate();   /* check if it is a bst */
        bool isBalanced(); /* height diff of substrees do not exceed 1 */
        Tree::BNode<T>* doublyLinkedLeaves();
    private:
        //depth post order traversal before deletion
        void deleteTree_(Tree::BNode<T>* root);
        bool checkMinMax_(Tree::BNode<T>* root, T min, T max);
        int checkHeight_(Tree::BNode<T>* root);
        void sewLeavesToDbLL_(Tree::BNode<T>* root, Tree::BNode<T>** headPP, Tree::BNode<T>** tailPP);

        Tree::BNode<T>* createMidNodeRecursive_(std::vector<T> const& sortedArr, unsigned leftIndex, unsigned rightIndex);
        Tree::BNode<T>* root_;
};

#include "bst.cpp"
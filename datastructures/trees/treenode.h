#pragma once
#include <utility>

namespace Tree {
    template <typename T>
    class BNode {
        public:
            BNode() : left_(0), right_(0) {}
            BNode(T value) : value_(value), left_(0), right_(0) {}
            T const getValue() {
                return value_;
            }
            void setValue(T value) {
                value_ = value;
            }
            BNode<T>* getLeftNode() {
                return left_;
            }
            BNode<T>* getRightNode() {
                return right_;
            }
            std::pair<BNode<T>*, BNode<T>* > getChildren() {
                return std::make_pair(left_, right_);
            }
            void setLeftNode(BNode<T>* node) {
                left_ = node;
            }
            void setRightNode(BNode<T>* node) {
                right_ = node;
            }
            bool isLeafNode() {
                return left_ == 0 && right_ == 0;
            }
        private:
            T value_;
            BNode<T>* left_;
            BNode<T>* right_;
    };
}
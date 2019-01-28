#pragma once

namespace Tree {
    template <typename T>
    class BNode {
        public:
            BNode() : left_(NULL), right_(NULL) {}
            BNode(T value) : value_(value), left_(NULL), right(NULL) {}
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
            void setLeftNode(BNode<T>* node) {
                left_ = node;
            }
            void setRightNode(BNode<T>* node) {
                right_ = node;
            }
        private:
            T value_;
            BNode<T>* left_;
            BNode<T>* right_;
    };
}
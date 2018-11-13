#pragma once
#include <vector>

template <class T>
class Node {
    public:
        Node();
        Node(T value);

        ~Node();

        //getters
        void setValue(T value);
        void setNextNode(Node<T>* next);

        //setters
        T getValue();
        Node<T>* getNextNode();

    private:
        T value_;
        Node<T>* next_;
};

#include "node.cpp"  //implementation file
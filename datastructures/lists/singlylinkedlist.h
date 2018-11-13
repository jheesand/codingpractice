#pragma once
#include "../node.h"

template <class T>
class SinglyLinkedList {
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void pushFront(Node<T>* nodePtr);
        void pushBack(Node<T>* nodePtr);
        void clearList();

        void printTraverse();
        // void sortList();

        //2.1
        void removeDuplicateValues(bool useBuffer = true);
    private:
        void removeNodeInList_(Node<T>* prevNodePtr, Node<T>* nodePtr);
        //2.1 follow-up
        void removeDuplicateValuesNoBuffer_();
        Node<T>* head_;
};

#include "singlylinkedlist.cpp"
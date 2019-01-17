#pragma once
#include "../node.h"

template <class T>
class SinglyLinkedList {
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void pushFront(Node<T>* nodePtr);
        Node<T>* popFront();
        void pushBack(Node<T>* nodePtr);
        void clearList();
        Node<T>* getHead();

        void printTraverse();
        //2.4
        void partitionList(T value);
        //2.6
        bool isPalindrome();

        // void sortList();

        //2.1
        void removeDuplicateValues(bool useBuffer = true);
        //2.2
        Node<T>* returnKthToLast(unsigned k);
    private:
        void removeNodeInList_(Node<T>* prevNodePtr, Node<T>* nodePtr);
        //2.1 follow-up
        void removeDuplicateValuesNoBuffer_();
        Node<T>* head_;
};

#include "singlylinkedlist.cpp"
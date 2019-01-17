#pragma once
#include "singlylinkedlist.h"

namespace LinkedListHelper {
    template <class T>
    unsigned getNumNodesInList(Node<T>* startNode);

    //2.3 Deleting node
    template <class T>
    void deleteMiddleNode(Node<T>* mid);

    //2.5 each node represents a single digit
    //    for both reversed and forward orders
    template <class T>
    SinglyLinkedList<T> sumList(Node<T>* num1, Node<T>* num2, bool reverseOrder);

    //2.7 find intersecting Node of 2-singly linked list and we are assuming that
    //    return NULL if intersection not found
    template <class T>
    Node<T>* getIntersectNode(Node<T>* pHead1, Node<T>* pHead2);

    //2.8 Loop detection
    template <class T>
    Node<T>* getStartCycle(Node<T>* pHead);
}

#include "linkedlisthelper.cpp"
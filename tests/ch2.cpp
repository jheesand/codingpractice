#include <cstdlib>
#include "ch2.h"
#include "../datastructures/lists/linkedlisthelper.h"

void Ch2Tests::init() {
    int loopCount = rand() % 30 + 30; 
    for (int i = 0; i < 6; ++i) {
        intSLLs_.push_back(SinglyLinkedList<int>());
    }

    for (int i = 0; i <= loopCount; ++i) {
        intSLLs_[0].pushFront(new Node<int>(1));
        intSLLs_[1].pushFront(new Node<int>(loopCount - i));
        intSLLs_[2].pushFront(new Node<int>(rand() % 100));
        intSLLs_[3].pushFront(new Node<int>(rand() % 30));
        intSLLs_[4].pushFront(new Node<int>(i % 2 == 0 ? 1 : 2));
        intSLLs_[5].pushFront(new Node<int>(i/10));
    }

    intSLLs_.push_back(SinglyLinkedList<int>());
    intSLLs_[6].pushFront(new Node<int>(6));
    intSLLs_[6].pushFront(new Node<int>(1));
    intSLLs_[6].pushFront(new Node<int>(7));
    intSLLs_.push_back(SinglyLinkedList<int>());
    intSLLs_[7].pushFront(new Node<int>(2));
    intSLLs_[7].pushFront(new Node<int>(9));
    intSLLs_[7].pushFront(new Node<int>(5));
    intSLLs_.push_back(SinglyLinkedList<int>());
    intSLLs_[8].pushFront(new Node<int>(7));
    intSLLs_[8].pushFront(new Node<int>(1));
    intSLLs_[8].pushFront(new Node<int>(8));
    intSLLs_.push_back(SinglyLinkedList<int>());
    intSLLs_[9].pushFront(new Node<int>(5));
    intSLLs_[9].pushFront(new Node<int>(9));
    intSLLs_[9].pushFront(new Node<int>(2));

    intSLLs_.push_back(SinglyLinkedList<int>());
    intSLLs_[10].pushFront(new Node<int>(1));
    intSLLs_[10].pushFront(new Node<int>(3));
    intSLLs_[10].pushFront(new Node<int>(2));
    intSLLs_[10].pushFront(new Node<int>(2));
    intSLLs_[10].pushFront(new Node<int>(3));
    intSLLs_[10].pushFront(new Node<int>(1));

    intSLLs_.push_back(SinglyLinkedList<int>());
    intSLLs_[11].pushFront(new Node<int>(1));
    intSLLs_[11].pushFront(new Node<int>(3));
    intSLLs_[11].pushFront(new Node<int>(2));
    intSLLs_[11].pushFront(new Node<int>(3));
    intSLLs_[11].pushFront(new Node<int>(1));
}

void Ch2Tests::printAllLinkedLists() {
    for (unsigned i = 0; i < intSLLs_.size(); ++i) {
        intSLLs_[i].printTraverse();
    }
}

void Ch2Tests::printLinkedList(unsigned index) {
    if (!checkIndex_(index)) {
        return;
    }

    intSLLs_[index].printTraverse();
}

bool Ch2Tests::checkIndex_ (unsigned index) {
    if (index > intSLLs_.size()) {
        std::cout << "No index " << index << " choose from 0 - " << (intSLLs_.size() - 1) << std::endl;
        return false;
    }
    return true;
}

void Ch2Tests::removeDuplicatesTest_(unsigned index) {
    if (!checkIndex_(index)) {
        return;
    }
    std::cout << "Original List: " << std::endl;
    printLinkedList(index);
    std::cout << "New List: " << std::endl;
    intSLLs_[index].removeDuplicateValues();
    printLinkedList(index);
}

void Ch2Tests::partitionListByValue_ (unsigned index, int value) {
    if (!checkIndex_(index)) {
        return;
    }

    std::cout << "Original List: " << std::endl;
    printLinkedList(index);
    std::cout << "New List: " << std::endl;
    intSLLs_[index].partitionList(value);
    printLinkedList(index);
}

void Ch2Tests::returnKthToLast_(unsigned index, int k) {
    if (!checkIndex_(index)) {
        return;
    }
    std::cout << "Original List: " << std::endl;
    printLinkedList(index);
    std::cout << "New List: " << std::endl;
    std::cout << k << "-th to last node value: " << intSLLs_[index].returnKthToLast(k)->getValue() << std::endl;
}

void Ch2Tests::sumLists_(unsigned index1, unsigned index2) {
    if (!(checkIndex_(index1) && checkIndex_(index1))) {
        return;
    }
    std::cout << "Original Lists: " << std::endl;
    printLinkedList(index1);
    printLinkedList(index2);
    intSLLs_.push_back(LinkedListHelper::sumList<int>(intSLLs_[index1].getHead(), intSLLs_[index2].getHead(), false));
    std::cout << "Sum List: " << std::endl;
    printLinkedList(intSLLs_.size() - 1);
}

bool Ch2Tests::checkPalindrome_(unsigned index) {
    if (!checkIndex_(index)) {
        return false;
    }
    std::cout << "Original List: " << std::endl;
    printLinkedList(index);
    bool isPalin = intSLLs_[index].isPalindrome();
    std::cout << "Palindrome: " << isPalin << std::endl;
    return isPalin;
}

bool Ch2Tests::checkIntersect_(unsigned index1, unsigned index2) {
    if (!(checkIndex_(index1) && checkIndex_(index1))) {
        return false;
    }
    std::cout << "Original Lists: " << std::endl;
    printLinkedList(index1);
    printLinkedList(index2);
    Node<int>* node = LinkedListHelper::getIntersectNode(intSLLs_[index1].getHead(), intSLLs_[index2].getHead());

    if (node != NULL) {
        return true;
		std::cout << "Intersecting Node: " << node << " w/ value: " << node->getValue() << std::endl;
    }
    return false;
}


void Ch2Tests::run() {
    checkIntersect_(7,9);
}

void Ch2Tests::cleanup() {
    for (unsigned i = 0; i < intSLLs_.size(); ++i) {
        SinglyLinkedList<int> s = intSLLs_[i];
        Node<int>* node = s.popFront();
        while (node != NULL) {
            delete node;
            node = s.popFront();
        }
    }
    while (!intSLLs_.empty()) {
        intSLLs_.pop_back();
    }
}
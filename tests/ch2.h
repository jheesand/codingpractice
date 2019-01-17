/**
* 2.1 tests
*/
#pragma once
#include "../datastructures/lists/singlylinkedlist.h"
#include <vector>
#include <string>

class Ch2Tests {
    public:
        void init();
        void run();
        void cleanup();
        void printAllLinkedLists();
        void printLinkedList(unsigned index);
    private:
        void removeDuplicatesTest_(unsigned index);
        bool checkIndex_(unsigned index);
        void partitionListByValue_(unsigned index, int value);
        void returnKthToLast_(unsigned index, int k);
        void sumLists_(unsigned index, unsigned index2);
        bool checkPalindrome_(unsigned index);
        bool checkIntersect_(unsigned index, unsigned index2);
        std::vector< SinglyLinkedList<int> > intSLLs_;
};

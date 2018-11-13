/**
* 2.1 tests
*/
#pragma once
#include "../datastructures/node.h"
#include "../datastructures/lists/singlylinkedlist.h"
#include <vector>
#include <string>

class Ch2Tests {
    public:
        //hehehe
        enum TestId {
            ONE,
            TWO,
            THREE,
            FOUR,
            FIVE,
            SIX,
            SEVEN,
            EIGHT,
            TOTAL
        };

        void init();
        void run(TestId num = TOTAL);
        void cleanup();
    private:
        std::vector< SinglyLinkedList<int> > intSLLs;
        std::vector< SinglyLinkedList<char> > charSLLs;
        std::vector< SinglyLinkedList<std::string> > strSLLs;
        std::vector< SinglyLinkedList<double> > dblSLLs;

        void genSinglyLinkedListsOfInt(std::vector< SinglyLinkedList<int> >& slls);
        void genSinglyLinkedListsOfChar(std::vector< SinglyLinkedList<char> >& clls);
        void genSinglyLinkedListsOfStr(std::vector< SinglyLinkedList<char> >& strlls);
        void genSinglyLinkedListsOfDbl(std::vector< SinglyLinkedList<char> >& dbllls);

        bool genDataSets();
        bool cleanDataSets();


        // this gross syntax means:
        // an array of pointers to functions that take nothing and return a bool
        // bool (* fPtr[NUM_TESTS])(void) = [
        //     test0
        // ];
};

#include "ch2.cpp"

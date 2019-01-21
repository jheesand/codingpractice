#include <stack>
namespace LinkedListHelper {
    template <class T>
    void deleteMiddleNode(Node<T>* mid) {
        Node<T>* iter = mid;
        Node<T>* next = iter->getNextNode();
        //cannot delete middle node (only 1-node list)
        if (next == NULL) {
            return;
        }

        while (next->getNextNode() != NULL) {
            iter->setValue(next->getValue());
            iter = next;
            next = next->getNextNode();
        }

        iter->setValue(next->getValue());
        iter->setNextNode(NULL);
    }
//notetoself-- this is really gross- refactor please
    template <class T>
    SinglyLinkedList<T> sumList(Node<T>* num1, Node<T>* num2, bool reverseOrder) {
        Node<T>* iter1 = num1;
        Node<T>* iter2 = num2;
        SinglyLinkedList<T> answer;
        T carryOver = 0;

        if (reverseOrder) {    
            while (iter1 != NULL && iter2 != NULL) {
                T val3 = iter1->getValue() + iter2->getValue() + carryOver;
                carryOver = 0;
                if (val3 >= 10) {
                    carryOver = 1;
                    val3 = val3 - 10;
                }
                Node<T>* newDig = new Node<T>(val3);
                answer.pushBack(newDig);
                iter1 = iter1->getNextNode();
                iter2 = iter2->getNextNode();
            }

            Node<T>* remainingDig = iter1;
            if (iter2) {
                remainingDig = iter2;
            }

            while (remainingDig != NULL) {
                T sum = remainingDig->getValue() + carryOver;
                carryOver = 0;
                if (sum > 10) {
                    carryOver = 1;
                    sum = sum - 10;
                }
                Node<T>* newDig = new Node<T>(sum);
                answer.pushBack(newDig);
                remainingDig = remainingDig->getNextNode();
            }
        }
        else {
            unsigned i = 0;
            std::stack<T> s1; 
            std::stack<T> s2;
            while (iter1 != NULL) {
                s1.push(iter1->getValue());
                iter1 = iter1->getNextNode();
            }
            while (iter2 != NULL) {
                s2.push(iter2->getValue());
                iter2 = iter2->getNextNode();
            }

            while (!s1.empty() && !s2.empty()) {
                T dig = s1.top() + s2.top() + carryOver;
                carryOver = 0;
                if (dig >= 10) {
                    carryOver = 1;
                    dig -= 10;
                }
                else {
                    carryOver = 0;
                }
                s1.pop();
                s2.pop();
                Node<T>* newDig = new Node<T>(dig);
                answer.pushFront(newDig);
            }
            std::stack<T> s3 = s1;
            if (s1.empty()) {
                s3 = s2;
            }

            while (!s3.empty()) {
                T sum = s3.top() + carryOver;
                carryOver = 0;
                if (sum > 10) {
                    carryOver = 1;
                    sum = sum - 10;
                }
                Node<T>* newDig = new Node<T>(sum);
                answer.pushBack(newDig);
                s3.pop();
            }
        }

        if (carryOver == 1) {
            if (reverseOrder) {
                answer.pushBack(new Node<T>(carryOver));
            }
            else {
                answer.pushFront(new Node<T>(carryOver));
            }
        }

        return answer;
    }

    template <class T>
    unsigned getNumNodesInList(Node<T>* startNode) {
        Node<T>* iter = startNode;
        unsigned count = 0;

        //DRY THIS UP
        while (iter != NULL) {
            ++count;
            iter = iter->getNextNode();
        }

        return count;
    }

    template <class T>
    Node<T>* getIntersectNode(Node<T>* pHead1, Node<T>* pHead2) {
        unsigned count1 = getNumNodesInList(pHead1);
        unsigned count2 = getNumNodesInList(pHead2);

        Node<T>* longerIter = pHead1;
        Node<T>* otherIter = pHead2;
        unsigned extraSteps = count1 - count2;  //if neg-- extremely high

        if (count2 > count1) {
            longerIter = pHead2;
            otherIter = pHead1;
            extraSteps = count2 - count1;
        }

        //pulling the starting node pos up to the other node list
        while (extraSteps > 0) {
            longerIter = longerIter->getNextNode();
            --extraSteps;
        }

        while (longerIter != NULL && otherIter != NULL) {
            if (longerIter == otherIter) {
                //found the intersection
                return longerIter;
            }

            longerIter = longerIter->getNextNode();
            otherIter = otherIter->getNextNode();
        }
        return NULL;
    }
}  //end of namespace LinkedListHelper
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
}
#include <unordered_map>
#include <iostream>
#include <stack>
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head_(NULL){
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clearList();
}

template <class T>
void SinglyLinkedList<T>::removeNodeInList_(Node<T>* prevNodePtr, Node<T>* nodePtr) {
    prevNodePtr->setNextNode(nodePtr->getNextNode());
    nodePtr->setNextNode(NULL);
}

/**
 * Inefficient way of removing duplicate values
*/
template <class T>
void SinglyLinkedList<T>::removeDuplicateValuesNoBuffer_() {
    std::cout << "Removing Duplicates W/O TEMP buffer" << std::endl;
    Node<T>* slowIter = head_;
    if (slowIter == NULL) {
        return;
    }

    Node<T>* runner = NULL;  //second iterator
    Node<T>* lagger = NULL;  //right behind runner

    while (slowIter != NULL) {
        T value = slowIter->getValue();

        lagger = slowIter;
        runner = slowIter->getNextNode();

        while (runner != NULL) {
            T runnerValue = runner->getValue();
            if (runnerValue == value) {
                removeNodeInList_(lagger, runner);
            }
            else {
                lagger = runner;
            }
            runner = runner->getNextNode();
        }

        slowIter = slowIter->getNextNode();
    }
}

/**
 * inserts a node at the very beginning of the list
*/
template <class T>
void SinglyLinkedList<T>::pushFront(Node<T>* nodePtr) {
    //if list is empty take node as new head
    if (head_ == NULL) {
        head_ = nodePtr;
        return;
    }

    nodePtr->setNextNode(head_);
    head_ = nodePtr;
}
/**
 * removes front node
*/
template <class T>
Node<T>* SinglyLinkedList<T>::popFront() {
    if (head_ == NULL) {
        return NULL;
    }

    Node<T>* temp = head_;
    head_ = temp->getNextNode();
    temp->setNextNode(NULL);
    return temp;
}

/**
 * adds a node to the very end of the list
*/
template <class T>
void SinglyLinkedList<T>::pushBack(Node<T>* nodePtr) {
    Node<T>* iter = head_;
    if (head_ == NULL) {
        head_ = nodePtr;
        return;
    }

    while(iter->getNextNode()) {
        iter = iter->getNextNode();
    }

    iter->setNextNode(nodePtr);
}

/**
 *
*/
template <class T>
void SinglyLinkedList<T>::clearList() {
    head_ = NULL;
}

/**
 *
*/
template <class T>
Node<T>* SinglyLinkedList<T>::getHead() {
    return head_;
}

/**
 *
*/
template <class T>
void SinglyLinkedList<T>::printTraverse() {
    Node<T>* iter = head_;
    int count = 1;
    std::cout << "======= Printing out Singly Linked List: =======" << std::endl;
    while (iter != NULL){
        if (iter->getNextNode() == NULL) {
			std::cout << " " << iter->getValue() << " -> NULL" << std::endl;
        }
        else {
            std::cout << " " << iter->getValue() << " ->";
        }
        
        ++count;
        iter = iter->getNextNode();
    }
    std::cout << "=================================================" << std::endl;
}

template <class T>
void SinglyLinkedList<T>::removeDuplicateValues(bool useBuffer) {
    if (!useBuffer) {
        removeDuplicateValuesNoBuffer_();
        return;
    }
    std::unordered_map<T, bool> encounteredMap;

    Node<T>* iter = head_;   //iterator that will run through list
    Node<T>* lagger = NULL;  //follows iterator one step behind

    while (iter != NULL) {
        T val = iter->getValue();

        // already encountered this value!
        if (encounteredMap.find(val) != encounteredMap.end()) {
            //lagger points to the same node while iter will increment (removed node fixes lagger this loop)
            removeNodeInList_(lagger, iter);
        }
        else {
            encounteredMap.insert(std::make_pair(val, true));
            lagger = iter;
        }
        iter = iter->getNextNode();
    }
}

template <class T>
Node<T>* SinglyLinkedList<T>::returnKthToLast(unsigned k) {
    unsigned numNodes = 0;
    Node<T>* iter = head_;

    while (iter != NULL) {
        ++numNodes;
        iter = iter->getNextNode();
    }

    int ithNode = numNodes - k;

    if (ithNode < 0) {
        return NULL;
    }
    iter = head_;
    while (ithNode > 0) {
        iter = iter->getNextNode();
        --ithNode;
    }
    return iter;
}

template <class T>
void SinglyLinkedList<T>::partitionList(T value) {
    SinglyLinkedList<T> greaterThanList;  //temporary list that hold values greater than value

    if (head_ == NULL || head_->getNextNode() == NULL) {
        return;  //can't do anything with a single or no-noded list
    }

    Node<T>* prev = head_;
    Node<T>* curr = prev->getNextNode();

    while (curr != NULL) {
        if (curr->getValue() >= value) {
            Node<T>* temp = curr;
            curr = curr->getNextNode();
            removeNodeInList_(prev, temp);
            greaterThanList.pushFront(temp);
        }
        else {
            prev = curr;
            curr = curr->getNextNode();
        }
    }

    if (head_->getValue() >= value) {
        Node<T>* tempHead = head_;
        head_ = head_->getNextNode();
        greaterThanList.pushFront(tempHead);
    }

    prev->setNextNode(greaterThanList.getHead());
}

template <class T>
bool SinglyLinkedList<T>::isPalindrome() {
    Node<T>* iter = head_;
    int count = 0;
    bool isEven = false;

    while (iter != NULL) {
        ++count;
        iter = iter->getNextNode();
    }

    if (count % 2 == 0) {
        isEven = true;
    }

    count /= 2;
    iter = head_;
    std::stack<T> firstHalfVal;
    while (iter != NULL) {
        if (count > 0) {
            firstHalfVal.push(iter->getValue());
            --count;
        }
        else if (count == 0 && !isEven) {
            --count;
        }
        else {
            if (firstHalfVal.top() == iter->getValue()) {
                firstHalfVal.pop();
            }
            else {
                return false;
            }
        }
        iter = iter->getNextNode();
    }

    return true;
}
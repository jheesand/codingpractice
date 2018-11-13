#include <unordered_map>
template <class T>
void SinglyLinkedList<T>::removeNodeInList_(Node<T>* prevNodePtr, Node<T>* nodePtr) {
    prevNodePtr->setNextNode(nodePtr->getNextNode());
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

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() : head_(NULL){
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clearList();
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
void SinglyLinkedList<T>::printTraverse() {
    Node<T>* iter = head_;
    int count = 1;
    std::cout << "======= Printing out Singly Linked List: =======" << std::endl;
    while (iter != NULL){
        std::cout << "Node #" << count << " value: " << iter->getValue() << std::endl;
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


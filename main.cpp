#include <iostream>
#include "./datastructures/lists/singlylinkedlist.h"
#include <string>

int main(void) {
    std::cout << "Hello world!" << std::endl;

    Node<std::string> node("hilo");
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(2);
    Node<int> node5(1);
    Node<int> node6(2);
    Node<int> node7(9);
    Node<int> node8(4);
    Node<int> node9(3);

    SinglyLinkedList<int> LL;
    LL.pushBack(&node1);
    LL.pushBack(&node2);
    LL.pushBack(&node3);
    LL.pushBack(&node4);
    LL.pushBack(&node5);
    LL.pushBack(&node6);
    LL.pushBack(&node7);
    LL.pushBack(&node8);
    LL.pushBack(&node9);

    LL.printTraverse();
    LL.removeDuplicateValues(false);
    LL.printTraverse();

    // std::cout << node.getValue() << std::endl;
    return 0;
}
#include <iostream>
#include "./datastructures/lists/singlylinkedlist.h"
#include <string>
#include <vector>

void insertTokenIntoSpace(std::string const& token, std::string& str, int endInd) {
	for (int i = token.size() - 1; i >= 0; --i) {
		str[endInd] = token[i];
		--endInd;
	}
}

void URLify(std::string& str, int strLen) {
	//let's iterate backwards:
	int k = str.size() - 1;
	for (int j = strLen - 1; j >= 0; --j) {
		char c = str[j];
		if (c == ' ') {
			insertTokenIntoSpace("%20", str, k);
			k -= 3;
			continue;
		}
		str[k] = c;
		--k;
	}
}

int main(void) {
    // std::cout << "Hello world!" << std::endl;
	//               0123456789  12
	std::string str("Hi my friend Jo      ");
	int strLen = 15;
	URLify(str, strLen);
    // Node<std::string> node("hilo");
    // Node<int> node1(1);
    // Node<int> node2(2);
    // Node<int> node3(3);
    // Node<int> node4(2);
    // Node<int> node5(1);
    // Node<int> node6(2);
    // Node<int> node7(9);
    // Node<int> node8(4);
    // Node<int> node9(3);

    // SinglyLinkedList<int> LL;
    // LL.pushBack(&node1);
    // LL.pushBack(&node2);
    // LL.pushBack(&node3);
    // LL.pushBack(&node4);
    // LL.pushBack(&node5);
    // LL.pushBack(&node6);
    // LL.pushBack(&node7);
    // LL.pushBack(&node8);
    // LL.pushBack(&node9);

    // LL.printTraverse();
    // LL.removeDuplicateValues(false);
    // LL.printTraverse();

    // std::cout << node.getValue() << std::endl;
    return 0;
}
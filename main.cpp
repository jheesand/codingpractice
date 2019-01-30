// #include "./datastructures/lists/singlylinkedlist.h"
// #include "./datastructures/arrays/stringsmasher.h"
// #include "./datastructures/arrays/stringhelper.h"
// #include "./tests/ch1.h"
// #include "./tests/ch2.h"
// #include "./datastructures/node.h"
// #include "./datastructures/lists/singlylinkedlist.h"
// #include "./datastructures/arrays/threestacks.h"
#include "./datastructures/trees/bst.h"
#include <vector>


int main(void) {
    std::cout << "Hello World" << std::endl;
    std::vector<int> sortedArr{0, 1, 2, 3, 4, 5};
    BST<int> BinSTree(sortedArr);
    BinSTree.printBreadthTree();
    std::cout << "Hello World Again" << std::endl;
    return 0;
}
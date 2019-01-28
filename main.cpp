// #include "./datastructures/lists/singlylinkedlist.h"
// #include "./datastructures/arrays/stringsmasher.h"
// #include "./datastructures/arrays/stringhelper.h"
// #include "./tests/ch1.h"
// #include "./tests/ch2.h"
// #include "./datastructures/node.h"
// #include "./datastructures/lists/singlylinkedlist.h"
#include "./datastructures/arrays/threestacks.h"



int main(void) {
    // std::cout << "Hello world!" << std::endl;
    MultiStacks<int, 3, 30> stack;
    for (unsigned i = 0; i < 30; ++i) {
        if (i < 20) {
            stack.push(0, rand() % 40 + 1);
        }
        else {
            stack.push(2, rand() % 100 + 1);
        }
    }

    int min1 = stack.getMin(0);
    int min3 = stack.getMin(2);

    return 0;
}
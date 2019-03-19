#include <iostream>
#include "./datastructures/trees/serialize.h"
int main(void) {
    Node* root = new Node("root", new Node("left", new Node("left.left", new Node("left.left.left")), new Node("left.right")), new Node("right"));
    std::string serialized = serialize(root);
    Node* rootClone = deserialize(serialized);
    return 0;
}
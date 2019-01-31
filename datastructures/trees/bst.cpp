
template <typename T>
Tree::BNode<T>* BST<T>::createMidNodeRecursive_(std::vector<T> const& sortedArr, unsigned leftIndex, unsigned endIndex) {
    if (leftIndex == endIndex) {
        return 0;
    }

    unsigned midIndex  = (leftIndex + endIndex) / 2;
    Tree::BNode<T>* mid = new Tree::BNode<T>(sortedArr[midIndex]);
    Tree::BNode<T>* left = createMidNodeRecursive_(sortedArr, leftIndex, midIndex);
    Tree::BNode<T>* right = createMidNodeRecursive_(sortedArr, midIndex + 1, endIndex);
    mid->setLeftNode(left);
    mid->setRightNode(right);

    return mid;
}

template <typename T>
BST<T>::BST(std::vector<T> const& sortedArr) {
    root_ = createMidNodeRecursive_(sortedArr, 0, sortedArr.size());
}

template <typename T>
void BST<T>::deleteTree_(Tree::BNode<T>* root) {
    if (root == 0) {
        return;
    }

    deleteTree_(root->getLeftNode());
    deleteTree_(root->getRightNode());
    delete root;
    root = 0;
}

template <typename T>
void BST<T>::printBreadthTree() {
    std::queue<Tree::BNode<T>* > nodeContainer;
    nodeContainer.push(root_);
    nodeContainer.push(0);  //delimiter null
    unsigned int level = 0;
    std::cout << "Printing tree: "<< std::endl;
    while (!nodeContainer.empty() && nodeContainer.front() != 0) {
        Tree::BNode<T>* node = nodeContainer.front();
        nodeContainer.pop();

        std::pair<Tree::BNode<T>*, Tree::BNode<T>* > children = node->getChildren();
        if (children.first) {
            nodeContainer.push(children.first);
        }

        if (children.second) {
            nodeContainer.push(children.second);
        }

        std::cout << node->getValue();
        if (nodeContainer.front() == 0) {
            std::cout << std::endl << "Level " << level << std::endl;
            nodeContainer.pop();
            nodeContainer.push(0);
            ++level;
        }
        else {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

template <typename T>
bool BST<T>::checkMinMax_(Tree::BNode<T>* root, T min, T max) {
    if (root == 0) {
        return true;
    }

    T myValue = root->getValue();
    // next two checks prevents further recursion
    if (root->isLeafNode()) {
        return myValue <= max && myValue >= min;
    }
    if (myValue > max || myValue < min) {
        return false;
    }

    return checkMinMax_(root->getLeftNode(), min, myValue) &&
           checkMinMax_(root->getRightNode(), myValue, max);
}

template <typename T>
bool BST<T>::validate() {
    return checkMinMax_(root_, -1000, 1000);
}

template <typename T>
int BST<T>::checkHeight_(Tree::BNode<T>* root) {
    if (root == 0) {
        return 0;
    }

    int leftHeight = checkHeight_(root->getLeftNode());
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight_(root->getRightNode());
    if (rightHeight == -1) {
        return -1;
    }

    unsigned heightDiff = abs(leftHeight - rightHeight);
    if (heightDiff > 1) {
        return -1;
    }

	int maxVal = leftHeight;
	if (leftHeight < rightHeight) {
		maxVal = rightHeight;
	}
    return maxVal + 1;  //+1 curr height
}

template <typename T>
bool BST<T>::isBalanced() {
    return checkHeight_(root_) != -1;
}
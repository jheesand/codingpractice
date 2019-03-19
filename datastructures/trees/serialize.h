// very simple serializing and deserializing tree:
#include <string>
#include <stack>

class Node {
public:
    Node(std::string const& v, Node* l = 0, Node* r = 0) : value(v), left(l), right(r) {}
    std::string value;
    Node* left;
    Node* right;
};

void serialRec(Node* root, std::string& str, int depth) {
    if (root == 0) return;
    int d = depth;
    while (d) {
        str += '	';
        --d;
    }
    str += root->value;
    serialRec(root->left,str,depth+1);
    serialRec(root->right,str,depth+1);
}

std::string serialize(Node* root) {
    std::string serial;
    serialRec(root, serial, 0);
    return serial;
}

int numPrefixTabs(std::string const& str, int startInd) {
    int num = 0;

    while (str[startInd] == '	') {
        ++num;
        ++startInd;
    }

    return num;
}

int getLastCharInd(std::string const& str, int startInd) {
    int i = startInd;
    for (; i < str.size(); ++i) {
        if (str[i] == '	') {
            break;
        }
    }

    return i - 1;
}

void resetTree(std::stack<Node*>& tree, int prevTabs, int currTabs) {
    int resetCount = prevTabs - currTabs + 1;
    while (resetCount) {
        tree.pop();
        --resetCount;
    }
}

Node* deserialize(std::string const& str) {
    int prevTabs = 0;
    int startInd = 0;
    std::stack<Node*> tree;

    while (startInd < str.size()) {
        int currTabs = numPrefixTabs(str, startInd);
        int startValInd = currTabs + startInd;
        int endInd = getLastCharInd(str, startValInd);
        Node* n = new Node(str.substr(startValInd, endInd - startValInd + 1));
        Node* p = 0;
        if (!tree.empty()) {
            if (prevTabs < currTabs) {
                p = tree.top();
                p->left = n;
            } else {
                if (prevTabs > currTabs) {
                    resetTree(tree, prevTabs, currTabs);
                } else if (prevTabs == currTabs) {
                    tree.pop();
                }
                p = tree.top();
                p->right = n;
            }
        }

        tree.push(n);
        startInd = endInd + 1;
        prevTabs = currTabs;
    }

    Node* root = 0;

    while (!tree.empty()) {
        root = tree.top();
        tree.pop();
    }

    return root;
}
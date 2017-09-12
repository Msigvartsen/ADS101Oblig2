#include <iostream>
#include "treenode.h"

int main()
{

    TreeNode<int>* intNode = new TreeNode<int>(4);
    intNode->insert(2);
    intNode->insert(3);
    intNode->insert(1);
    intNode->insert(6);
    intNode->insert(5);
    intNode->insert(8);
    intNode->insert(7);
    intNode->insert(9);

    intNode->inOrderTraversal();
    int count{0};

    intNode->remove(4);
    intNode->nodeCount(count);
    std::cout << "NODE COUNTER:: << " << count << "\n";
    intNode->inOrderTraversal();
    return 0;
}

#include <iostream>
#include "treenode.h"

int main()
{
    TreeNode<char>* node = new TreeNode<char>('c');
    node->insert('b');
    node->insert('a');
    node->inOrderTraversal();
    return 0;
}

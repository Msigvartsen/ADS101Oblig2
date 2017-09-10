#include <iostream>
#include "treenode.h"

int main()
{
//    TreeNode<char>* node = new TreeNode<char>('c');
//    node->insert('b');
//    node->insert('a');

//    node->insert('d');
//    node->insert('e');
//    node->insert('x');
//    node->inOrderTraversal();
//    node->remove('e');

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
    intNode->remove(3);
    intNode->inOrderTraversal();
    return 0;
}

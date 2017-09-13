#include <iostream>
#include "treenode.h"

int main()
{

    TreeNode<char>* charNode = new TreeNode<char>('g');
    char charArray[9]{'e','f','c','d','a','i','h','k','j'};
    std::cout << "Inserting chars to binary tree from array:\n";
    for(int i{0}; i < 9; i++)
    {
        std::cout << charArray[i] << " ";
        charNode->insert(charArray[i]);
    }
    std::cout << "\nInOrder Traversal print:\n";

    charNode->inOrderTraversal();
    std::cout << "\nPreOrder Traversal print:\n";
    charNode->preOrderTraversal();
    std::cout << "\npostOrder Traversal print:\n";
    charNode->postOrderTraversal();
    std::cout << "\n";


    TreeNode<int>* intNode = new TreeNode<int>(6);
    intNode->insert(4);
    intNode->insert(5);
    intNode->insert(2);
    intNode->insert(3);
    intNode->insert(1);
    intNode->insert(8);
    intNode->insert(7);
    intNode->insert(10);
    intNode->insert(9);

    intNode->inOrderTraversal();


    return 0;
}

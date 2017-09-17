#include <iostream>
#include "treenode.h"

int main()
{
    std::cout << "----- char binary tree -----\n\n";
    ADS101::TreeNode<char>* charNode = new ADS101::TreeNode<char>('g');
    char charArray[9]{'e','f','c','d','a','i','h','k','j'};
    std::cout << "Root of tree: " << charNode->getData() << "\n\n";
    std::cout << "Inserting chars to binary tree from array:\n";
    for(int i{0}; i < 9; i++)
    {
        std::cout << charArray[i] << " ";
        charNode->insert(charArray[i]);
    }

    int numberOfFullNodes{0};
    charNode->fullNodeCount(numberOfFullNodes);
    std::cout << "Nodes with two children: " << numberOfFullNodes << "\n";

    std::cout << "\n\nInOrder Traversal print:\n";
    charNode->inOrderTraversal();

    std::cout << "\n\nPreOrder Traversal print:\n";
    charNode->preOrderTraversal();

    std::cout << "\n\npostOrder Traversal print:\n";
    charNode->postOrderTraversal();

    int numberOfNodes{0};
    charNode->nodeCount(numberOfNodes);
    std::cout << "\n\nNumber of nodes in BinaryTree:" << numberOfNodes;

    int numberOfLeaves{0};
    charNode->leafCount(numberOfLeaves);
    std::cout << "\nLeaf count: " << numberOfLeaves << "\n\n";

    std::cout << "Removing node \'c\'\n";
    charNode->removeNode('c');
    std::cout << "InOrder Traversal print:\n";
    charNode->inOrderTraversal();

    std::cout << "\n\nRemoving node \'h\'\n";
    charNode->removeNode('h');
    std::cout << "InOrder Traversal print:\n";
    charNode->inOrderTraversal();

    numberOfNodes = 0;
    charNode->nodeCount(numberOfNodes);
    std::cout << "\n\nNumber of nodes in BinaryTree:" << numberOfNodes << "\n\n";

    numberOfLeaves = 0;
    charNode->leafCount(numberOfLeaves);
    std::cout << "\n\nLeaf count: " << numberOfLeaves;


    std::cout << "\nRemoving all nodes except root..\n";
    charNode->clear(charNode->getData());
    std::cout << "InOrder Traversal print:\n";
    charNode->inOrderTraversal();
    std::cout << "\n";


    std::cout << "----- int binary tree -----\n\n";
    ADS101::TreeNode<int>* intNode = new ADS101::TreeNode<int>(6);
    int intArray[9]{4,5,2,3,1,8,7,10,9};
    std::cout << "Root of tree: " << intNode->getData() << "\n";
    std::cout << "\nInserting int to binary tree from array:\n";
    for(int i{0}; i < 9; i++)
    {
        std::cout << intArray[i] << " ";
        intNode->insert(intArray[i]);
    }


    std::cout << "\n\nInOrder Traversal print:\n";
    intNode->inOrderTraversal();

    std::cout << "\n\nPreOrder Traversal print:\n";
    intNode->preOrderTraversal();

    std::cout << "\n\npostOrder Traversal print:\n";
    intNode->postOrderTraversal();

    numberOfNodes = 0;
    intNode->nodeCount(numberOfNodes);
    std::cout << "\n\nNumber of nodes in BinaryTree:" << numberOfNodes << "\n\n";

    numberOfLeaves = 0;
    intNode->leafCount(numberOfLeaves);
    std::cout << "Leaf count: " << numberOfLeaves << "\n\n";

    std::cout << "Removing node \'4\'\n";
    intNode->removeNode(4);
    std::cout << "InOrder Traversal print:\n";
    intNode->inOrderTraversal();

    std::cout << "\n\nRemoving node \'6\'\n";
    intNode->removeNode(6);
    std::cout << "InOrder Traversal print:\n";
    intNode->inOrderTraversal();

    std::cout << "\n\nRemoving node \'9\'\n";
    intNode->removeNode(9);
    std::cout << "InOrder Traversal print:\n";
    intNode->inOrderTraversal();

    numberOfLeaves = 0;
    intNode->leafCount(numberOfLeaves);
    std::cout << "\n\nLeaf count: " << numberOfLeaves;

    numberOfNodes = 0;
    intNode->nodeCount(numberOfNodes);
    std::cout << "\n\nNumber of nodes in BinaryTree:" << numberOfNodes << "\n\n";

    numberOfFullNodes = 0;
    intNode->fullNodeCount(numberOfFullNodes);
    std::cout << "Nodes with two children: " << numberOfFullNodes << "\n";

    std::cout << "Removing all nodes except root: \n";
    intNode->clear(intNode->getData());
    std::cout << "InOrder Traversal print..\n";
    intNode->inOrderTraversal();
    std::cout << "\nRoot of Tree: " << intNode->getData() << "\n";



    return 0;
}

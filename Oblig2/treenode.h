#ifndef TREENODE_H
#define TREENODE_H

namespace ADS101
{

template<class T>
class TreeNode
{
private:
    T m_data;
    TreeNode<T>* m_leftChild;
    TreeNode<T>* m_rightChild;
    TreeNode<T>* m_parent;
    static TreeNode<T>* foundNodeptr;
public:
    TreeNode();
    TreeNode(T data, TreeNode *parent = nullptr, TreeNode* leftChild = nullptr, TreeNode* rightChild = nullptr);
    TreeNode<T>* getLeftChild() const;
    TreeNode<T>* getRightChild() const;
    T getData() const;
    void setLeftChild(TreeNode *leftChild);
    void setRightChild(TreeNode* rightChild);
    void print();
    void insert(T data);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void remove(T data);
    void removeNode(T data);
    TreeNode<T>* findData(T data, bool &foundNode);
    void nodeCount(int &count);
    void treeDepth(int &leftDepth, int &rightDepth);
    TreeNode<T> *minValue(bool rightSub, bool &checkPath);
    TreeNode<T>* minVal();


};

}

using namespace ADS101;
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>::TreeNode()
{

}
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>::TreeNode(T data,TreeNode* parent,TreeNode* leftChild, TreeNode* rightChild) :
    m_data{data},
    m_leftChild{leftChild},
    m_rightChild{rightChild},
    m_parent{parent}
{

}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::print()
{
    std::cout << m_data << " ";
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::insert(T data)
{
    if(data < m_data)
    {
        if(m_leftChild)
        {
            m_leftChild->insert(data);
        }
        else
        {
            m_leftChild = new TreeNode<T>(data);
            m_leftChild->m_parent = this;
        }

    }
    else if(data > m_data)
    {
        if(m_rightChild)
        {
            m_rightChild->insert(data);
        }
        else
        {
            m_rightChild = new TreeNode<T>(data);
            m_rightChild->m_parent = this;
        }
    }


}
template<class T>
TreeNode<T>* TreeNode<T>::foundNodeptr;
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::remove(T data)
{

    //    findData(data);
    //    TreeNode<T>* current = foundNodePtr;
    //    TreeNode<T>* parent = current->m_parent;

    //    std::cout << "current data : " << current->getData();

    //    if(!current->getLeftChild() && !current->getRightChild())
    //    {
    //        std::cout << "\nNo Children\n";
    //        if(parent->getLeftChild()->getData() == current->getData())
    //        {
    //            parent->setLeftChild(nullptr);
    //            current = nullptr;
    //            delete current;
    //        }
    //        else
    //        {
    //            parent->setRightChild(nullptr);
    //            current = nullptr;
    //            delete current;
    //        }
    //        return;
    //    }
    //    if(current->getLeftChild() || current->getRightChild())
    //    {
    //        TreeNode<T>* tempNode;
    //        bool checkPath{false};
    //        //Left SubTree
    //        if(current->getData() < m_data)
    //        {

    //            tempNode = current->minValue(false,checkPath);
    //            std::cout << "Copy value ::" << tempNode->getData() << "\n";
    //            current->m_data = tempNode->getData();

    //            if(checkPath)
    //            {
    //                std::cout << "checkpath true\n";
    //                tempNode->m_parent->setRightChild(nullptr);
    //            }
    //            else
    //            {
    //                std::cout << "Copy value ::" << tempNode->getData() << "\n";
    //                tempNode->m_parent->setLeftChild(nullptr);
    //            }
    //        }
    //        //Right SubTree
    //        if(current->getData() >= m_data)
    //        {
    //            tempNode = current->minValue(true,checkPath);
    //            std::cout << "Copy value <" << tempNode->getData() << "\n";
    //            current->m_data = tempNode->getData();

    //            if(checkPath)
    //            {
    //                std::cout << "check path:: " << checkPath << "\n";
    //                tempNode->m_parent->setLeftChild(nullptr);
    //            }
    //            else
    //            {
    //                tempNode->m_parent->setRightChild(nullptr);
    //            }

    //        }
    //        delete tempNode;
    //        tempNode = nullptr;
    //    }
}

template<class T>
void TreeNode<T>::removeNode(T data)
{
    bool foundNode = false;
    findData(data,foundNode);
    TreeNode<T>* current = foundNodeptr;
    TreeNode<T>* parent = current->m_parent;
    std::cout << "Current Remove node: " << current->getData() << "\n";


    //Delete Leaf node
    if(!current->getRightChild() && !current->getLeftChild())
    {
        std::cout << "Deleting leaf node\n";
        if(current->getData() == parent->getLeftChild()->getData())
        {
            parent->setLeftChild(nullptr);
            delete current;
            current = nullptr;
        }
        else
        {
            parent->setRightChild(nullptr);
            delete current;
            current = nullptr;
        }
        return;
    }

    //Delete node with children
    if(current->getLeftChild() || current->getRightChild())
    {
        TreeNode<T>* tempNode = current->minVal();
        std::cout << "Deleting node with children\n";
        std::cout << "Tempnode with child:: " << tempNode->getData();
        //Sett current data = temp data, hvis right child sett den til parent, fjern left child / right parent
        current->m_data = tempNode->getData();

        if(!tempNode->getRightChild() && !tempNode->getLeftChild())
        {

           if(tempNode->m_parent->getRightChild() && tempNode->m_parent->getRightChild()->getData() == tempNode->getData())
           {
               tempNode->m_parent->setRightChild(nullptr);
           }
           else
           {
               tempNode->m_parent->setLeftChild(nullptr);
           }
           return;
        }

        if(!tempNode->getRightChild())
        {

            if(tempNode->m_parent->getRightChild()->getData() == tempNode->getData())
            {
                tempNode->m_parent->setRightChild(nullptr);
            }
            else
            {
                tempNode->m_parent->setLeftChild(nullptr);
            }
            delete tempNode;
            tempNode = nullptr;
        }
        else
        {
            if(tempNode->m_parent->getRightChild()->getData() == tempNode->getData())
            {
                tempNode->m_parent->setRightChild(tempNode->getRightChild());
            }
        }


        return;
    }
}

template<class T>
TreeNode<T>* TreeNode<T>::findData(T data, bool &foundNode)
{
    std::cout << "bool " << foundNode << "\n";
    if(m_data == data)
    {
        foundNode = true;
        foundNodeptr = this;
    }
    if(m_leftChild && !foundNode)
    {
        m_leftChild->findData(data,foundNode);
    }

    if(m_rightChild && !foundNode)
    {
        m_rightChild->findData(data,foundNode);
    }

}

template<class T>
void TreeNode<T>::treeDepth(int &leftDepth, int &rightDepth)
{
    if(m_leftChild)
    {
        leftDepth++;
        m_leftChild->treeDepth(leftDepth,rightDepth);

    }

    if(m_rightChild)
    {
        rightDepth++;
        m_rightChild->treeDepth(leftDepth,rightDepth);

    }

}

template<class T>
void TreeNode<T>::nodeCount(int &count)
{
    count++;
    if(m_leftChild)
    {
        m_leftChild->nodeCount(count);
    }

    if(m_rightChild)
    {
        m_rightChild->nodeCount(count);
    }
}

template<class T>
TreeNode<T>* TreeNode<T>::minValue(bool rightSub,bool &checkPath)
{

    TreeNode<T>*  tmpNode = this;
    int counter{0};
    if(m_rightChild && rightSub)
    {
        tmpNode = m_rightChild;

        while(true)
        {

            if(tmpNode->getLeftChild() == nullptr)
            {
                if(!counter)
                {
                    checkPath = false;
                }
                else
                {
                    checkPath = true;
                }
                return tmpNode;
            }
            else
            {
                tmpNode = tmpNode->getLeftChild();
            }
            counter++;
        }

        return tmpNode;
    }

    if(m_leftChild && !rightSub)
    {
        tmpNode = m_leftChild;

        while(true)
        {

            if(tmpNode->getRightChild() == nullptr)
            {
                if(!counter)
                {
                    checkPath = false;
                }
                else
                {
                    checkPath = true;
                }
                return tmpNode;
            }
            else
            {
                tmpNode = tmpNode->getRightChild();
            }
            counter++;
        }

        return tmpNode;
    }

    return tmpNode;



}

template<class T>
TreeNode<T>* TreeNode<T>::minVal()
{
    TreeNode<T>*  tmpNode = this;
    if(m_rightChild)
    {
        tmpNode = m_rightChild;
        while(true)
        {
            if(tmpNode->getLeftChild() == nullptr)
            {
                return tmpNode;
            }
            else
            {
                tmpNode = tmpNode->getLeftChild();
            }
        }

        return tmpNode;
    }
    else if(tmpNode->getLeftChild())
    {
        tmpNode = getLeftChild();
        return tmpNode;
    }
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::inOrderTraversal()
{
    if(m_leftChild)
    {
        m_leftChild->inOrderTraversal();
    }
    print();
    if(m_rightChild)
    {
        m_rightChild->inOrderTraversal();
    }
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::preOrderTraversal()
{
    print();
    if(m_leftChild)
    {
        m_leftChild->preOrderTraversal();
    }

    if(m_rightChild)
    {
        m_rightChild->preOrderTraversal();
    }

}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::postOrderTraversal()
{

    if(m_leftChild)
    {
        m_leftChild->postOrderTraversal();
    }

    if(m_rightChild)
    {
        m_rightChild->postOrderTraversal();
    }
    print();
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::setLeftChild(TreeNode* leftChild)
{
    m_leftChild = leftChild;
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::setRightChild(TreeNode *rightChild)
{
    m_rightChild = rightChild;
}


//--------------GETTERS------------------------------------------------------------------------------
template<class T>
T TreeNode<T>::getData() const
{
    return m_data;
}
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>* TreeNode<T>::getLeftChild() const
{
    if(m_leftChild)
    {
        return m_leftChild;
    }
    else
    {
        return nullptr;
    }

}
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>* TreeNode<T>::getRightChild() const
{
    if(m_rightChild)
    {
        return m_rightChild;
    }
    else
    {
        return nullptr;
    }

}
//--------------------------------------------------------------------------------------------------



#endif // TREENODE_H

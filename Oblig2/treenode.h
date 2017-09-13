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
    TreeNode<T>* getParent() const;
    T getData() const;
    void setLeftChild(TreeNode *leftChild);
    void setRightChild(TreeNode* rightChild);
    void setParent(TreeNode* parent);
    void print();
    void insert(T data);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void removeNode(T data);
    void findData(T data, bool &foundNode);
    void nodeCount(int &count);
    void treeDepth(int &leftDepth, int &rightDepth);
    TreeNode<T>* minValue();

};




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
{}
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
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>* TreeNode<T>::foundNodeptr;
//--------------------------------------------------------------------------------------------------

template<class T>
void TreeNode<T>::removeNode(T data)
{
    bool foundNode = false;
    findData(data,foundNode);
    TreeNode<T>* current = foundNodeptr;
    TreeNode<T>* parent = current->getParent();

    //Delete Leaf node
    if(!current->getRightChild() && !current->getLeftChild())
    {
        if(parent->getLeftChild() && current->getData() == parent->getLeftChild()->getData())
        {
            parent->setLeftChild(nullptr);
            current->setParent(nullptr);
            delete current;
            current = nullptr;
        }

        else
        {
            parent->setRightChild(nullptr);
            current->setParent(nullptr);
            delete current;
            current = nullptr;
        }
        return;
    }

    //Delete node with children
    else if(current->getLeftChild() || current->getRightChild())
    {
        //Find node with minValue from current subtree, set current data to minValue data, then delete node with minValue.
        TreeNode<T>* tempNode = current->minValue();
        TreeNode<T>* tempParent = tempNode->getParent();
        current->m_data = tempNode->getData();

        //If minValue node doesnt have children, set parent to nullptr to corresponding node, and delete.
        if(!tempNode->getRightChild() && !tempNode->getLeftChild())
        {

            if(tempParent->getRightChild() && tempParent->getRightChild()->getData() == tempNode->getData())
            {
                tempParent->setRightChild(nullptr);
            }
            else
            {
                tempParent->setLeftChild(nullptr);
            }
            delete tempNode;
            tempNode = nullptr;
        }
        else if(tempNode->getRightChild())
        {
            /*If tempNode has a right child,
            reassign pointer from tempNode parent to tempNode right child,
            and right child's parent to be tempNode's parent. Then delete node*/
            tempParent->setRightChild(tempNode->getRightChild());
            tempNode->getRightChild()->setParent(tempParent);

            if(tempNode->getLeftChild())
            {
                tempParent->setLeftChild(tempNode->getLeftChild());
                tempNode->getLeftChild()->setParent(tempParent);
            }

            delete tempNode;
            tempNode = nullptr;
        }

    }
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::findData(T data, bool &foundNode)
{
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
//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>* TreeNode<T>::minValue()
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
    else
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

template<class T>
void TreeNode<T>::setParent(TreeNode *parent)
{
    m_parent = parent;
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

template<class T>
TreeNode<T> *TreeNode<T>::getParent() const
{
    if(m_parent)
    {
        return m_parent;
    }
    else
    {
        return nullptr;
    }
}

}
//--------------------------------------------------------------------------------------------------



#endif // TREENODE_H

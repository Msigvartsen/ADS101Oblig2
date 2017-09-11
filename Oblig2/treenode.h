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
    static bool foundNode;
    static TreeNode<T>* foundNodePtr;
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
    void findData(T data);
    TreeNode<T> *minValue(bool rightSub, bool &checkPath);


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
    foundNode = false;
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::print()
{
    std::cout << m_data << "|";
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
bool TreeNode<T>::foundNode;
template<class T>
TreeNode<T>* TreeNode<T>::foundNodePtr;
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::remove(T data)
{

    findData(data);
    TreeNode<T>* current = foundNodePtr;
    TreeNode<T>* parent = current->m_parent;

    std::cout << "current data : " << current->getData();

    if(!current->getLeftChild() && !current->getRightChild())
    {
        std::cout << "\nNo Children\n";
        if(parent->getLeftChild()->getData() == current->getData())
        {
            parent->setLeftChild(nullptr);
            current = nullptr;
            delete current;
        }
        else
        {
            parent->setRightChild(nullptr);
            current = nullptr;
            delete current;
        }
        return;
    }
    if(current->getLeftChild() || current->getRightChild())
    {
        TreeNode<T>* tempNode;
        bool checkPath{false};
        if(current->getData() < m_data)
        {
            std::cout << "Copy value :::" << tempNode->getData() << "\n";
            tempNode = current->minValue(false,checkPath);
            current->m_data = tempNode->getData();
            std::cout << "Copy value :::" << tempNode->getData() << "\n";
            if(checkPath)
            {
                tempNode->m_parent->setRightChild(nullptr);
            }
            else
            {
                std::cout << "Copy value :::" << tempNode->getData() << "\n";
                tempNode->m_parent->setLeftChild(nullptr);
            }
        }
        if(current->getData() >= m_data)
        {
            tempNode = current->minValue(true,checkPath);
            std::cout << "Copy value <" << tempNode->getData() << "\n";
            current->m_data = tempNode->getData();

            if(checkPath)
            {
                tempNode->m_parent->setLeftChild(nullptr);
            }
            else
            {
                tempNode->m_parent->setRightChild(nullptr);
            }

        }
        delete tempNode;
        tempNode = nullptr;
    }
}

template<class T>
void TreeNode<T>::findData(T data)
{

    std::cout << "data: "<< data << "\nm_Data: "<< m_data << "\n";

    if(!foundNode)
    {
        if(m_data == data)
        {
            foundNode = true;
            foundNodePtr = this;
        }
        if(m_leftChild && !foundNode)
        {
            m_leftChild->findData(data);
        }

        if(m_rightChild && !foundNode)
        {
            m_rightChild->findData(data);
        }
    }




}

template<class T>
TreeNode<T>* TreeNode<T>::minValue(bool rightSub,bool &checkPath)
{

    TreeNode<T>*  tmpNode;
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

}
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>* TreeNode<T>::getRightChild() const
{
    if(m_rightChild)
    {
        return m_rightChild;
    }

}
//--------------------------------------------------------------------------------------------------



#endif // TREENODE_H

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
    TreeNode<T> *findData(T data);
    T minValue(T data);


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
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::remove(T data)
{
    TreeNode<T>* current = findData(data);
    TreeNode<T>* parent = current->m_parent;
    if(parent)
    {
        std::cout <<"parent data:" << parent->getData() << "\n";
    }
    if(current)
    {
        std::cout << "tmpNode data: " << current->getData() << "\n";
    }

    if(current->getLeftChild() == nullptr && current->getRightChild() == nullptr)
    {
        if(parent->getLeftChild())
        {
            if(parent->getLeftChild()->getData() == current->getData())
            {
                parent->setLeftChild(nullptr);
            }
        }
        if(parent->getRightChild())
        {
            if(parent->getRightChild()->getData() == current->getData())
            {
                parent->setRightChild(nullptr);

            }
            delete current;
            current = nullptr;
            return;
        }
    }

    if(current->getLeftChild()|| current->getRightChild())
    {
        if(current->getData() < m_data)
        {
            //current->gerLeft()->findLowestNumber();
            //One down left, rest right.
            //Replace current_data with found data.
            //delete found node

        }
        if(current->getData() > m_data)
        {
            T tempData = minValue(data);
            current->remove(tempData);
            current->m_data = tempData;


        }
    }

}

template<class T>
TreeNode<T>* TreeNode<T>::findData(T data)
{
    TreeNode<T>* left = m_leftChild;
    TreeNode<T>* right = m_rightChild;
    std::cout << "data: "<< data << "\nm_Data: "<< m_data << "\n";

    while(true)
    {
        std::cout << "Left_m_data == " << left->m_data << "\n";
        std::cout << "Right_m_data == " << right->m_data << "\n";
        if(data == left->m_data)
        {
            std::cout << "return\n";
            return left;
        }
        if(data == m_data)
        {
            return this;
        }
        if(data == right->m_data)
        {
            return right;
        }

        else
        {

            if(left->getLeftChild())
            {
                std::cout << "jump into left child\n";
                left = left->getLeftChild();

            }

            else if(right->getRightChild())
            {
                std::cout << "jump into right child\n";
                right = right->getRightChild();
            }
        }
    }
}

template<class T>
T TreeNode<T>::minValue(T data)
{
    TreeNode<T>*  tmpNode;
    if(m_rightChild)
    {
        tmpNode = m_rightChild;

        while(true)
        {
            if(tmpNode->getLeftChild() == nullptr)
            {
                return tmpNode->getData();
            }
            else
            {
                tmpNode = tmpNode->getLeftChild();
            }
        }

        return tmpNode->getData();
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

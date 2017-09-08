#ifndef TREENODE_H
#define TREENODE_H

namespace ADS101
{

template<class T>
class TreeNode
{
private:
    T m_data;
    TreeNode* m_leftChild;
    TreeNode* m_rightChild;
public:
    TreeNode();
    TreeNode(T data,TreeNode* leftChild = nullptr, TreeNode* rightChild = nullptr);
    TreeNode* getLeftChild() const;
    TreeNode* getRightChild() const;
    T getData() const;
    void setLeftChild(T data);
    void setRightChild(T data);
    void print();
    void insert(T data);
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void remove(T data);


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
TreeNode<T>::TreeNode(T data,TreeNode* leftChild, TreeNode* rightChild) :
    m_data{data},
    m_leftChild{leftChild},
    m_rightChild{rightChild}
{

}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::print()
{
    std::cout << m_data;
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
        }
    }


}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::remove(T data)
{

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
        m_leftChild->inOrderTraversal();
    }

    if(m_rightChild)
    {
        m_rightChild->inOrderTraversal();
    }

}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::postOrderTraversal()
{

    if(m_leftChild)
    {
        m_leftChild->inOrderTraversal();
    }

    if(m_rightChild)
    {
        m_rightChild->inOrderTraversal();
    }
    print();
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::setLeftChild(T data)
{
    m_leftChild = new TreeNode<T>(data);
}
//--------------------------------------------------------------------------------------------------
template<class T>
void TreeNode<T>::setRightChild(T data)
{
    m_rightChild = new TreeNode<T>(data);
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
    return m_leftChild;
}
//--------------------------------------------------------------------------------------------------
template<class T>
TreeNode<T>* TreeNode<T>::getRightChild() const
{
    return m_rightChild;
}
//--------------------------------------------------------------------------------------------------



#endif // TREENODE_H

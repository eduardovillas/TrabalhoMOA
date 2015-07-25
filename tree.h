#ifndef MOA_TREE_H
#define MOA_TREE_H

#include "nodetree.h"
#include "moa_global.h"

template <typename NodeType>
class Tree
{
public:
    Tree();
    ~Tree();

    bool isEmpty();
    bool append(NodeType &value);

private:
    NodeTree<NodeType> *m_root;


};

template<typename NodeType>
Tree<NodeType>::Tree()
{
    m_root = 0;
}

template<typename NodeType>
Tree<NodeType>::~Tree()
{

}

template<typename NodeType>
bool Tree<NodeType>::isEmpty()
{
    return m_root == 0;
}

template<typename NodeType>
bool Tree<NodeType>::append(NodeType &value)
{
    if (isEmpty()) {
        m_root = new NodeTree<NodeType>();
        if (m_root == 0)
            return false;
    }

    m_root->data = new NodeType(value);

    return true;
}

#endif // MOA_TREE_H

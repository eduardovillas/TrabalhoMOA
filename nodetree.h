#ifndef MOA_NODETREE
#define MOA_NODETREE

#include "moa_global.h"

template <typename NodeType>
class NodeTree {

public:
    NodeTree(NodeType *data);
    ~NodeTree();
    NodeTree<NodeType> *parent();
    void setParent(NodeTree<NodeType> *parent);

    const NodeType *constData() const ;
    NodeType *data();

    NodeTree<NodeType> **children();
    bool appendChildren(NodeTree<NodeType> *node);

private:
    NodeTree<NodeType> *m_parent;
    NodeType *m_data;
    NodeTree<NodeType> *m_children[SIZE_SIDE_BOARD];

};

#endif // MOA_NODETREE

template<typename NodeType>
NodeTree<NodeType>::NodeTree(NodeType *data)
{
    m_parent = 0;
    m_data = data;
    for (int i = 0 ; i < SIZE_SIDE_BOARD; ++i) {
        m_children[i] = 0;
    }

}

template<typename NodeType>
NodeTree<NodeType>::~NodeTree()
{   /* c++ memory management power */

    for (int i = 0; i < SIZE_SIDE_BOARD; ++i) {
        delete m_children[i];
    }
    delete m_data;
}

template<typename NodeType>
NodeTree<NodeType> *NodeTree<NodeType>::parent()
{
    return m_parent;
}

template<typename NodeType>
void NodeTree<NodeType>::setParent(NodeTree<NodeType> *parent)
{
    m_parent = parent;
}

template<typename NodeType>
const NodeType *NodeTree<NodeType>::constData() const
{
    return m_data;
}

template<typename NodeType>
NodeType *NodeTree<NodeType>::data()
{
    return m_data;
}

template<typename NodeType>
NodeTree<NodeType> **NodeTree<NodeType>::children()
{
    return m_children;
}

template<typename NodeType>
bool NodeTree<NodeType>::appendChildren(NodeTree<NodeType> *node)
{
    for (int i = 0; i < SIZE_SIDE_BOARD; ++i) {
        if (m_children[i] == 0){
            m_children[i] = node;
            node->m_parent = this;
            return true;
        }
    }

    return false;
}


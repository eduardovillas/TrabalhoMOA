#ifndef MOA_NODETREE
#define MOA_NODETREE

#include "moa_global.h"

template <typename NodeType>
class NodeTree {

private:
    NodeTree<NodeType> *m_parent;
    NodeType *m_data;
    NodeTree<NodeType> *m_children[SIZE_SIDE_BOARD];

};


#endif // MOA_NODETREE


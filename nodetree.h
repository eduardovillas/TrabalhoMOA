#ifndef MOA_NODETREE
#define MOA_NODETREE

#include "moa_global.h"

template<typename NodeType>
class Tree;

template <typename NodeType>
class NodeTree {

    NodeType *data;
    NodeTree<NodeType> *children[SIZE_SIDE_BOARD];

    friend class Tree<NodeType>;

};


#endif // MOA_NODETREE


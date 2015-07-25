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
{/*TODO: algoritmo ainda nao esta pronto, parei por que surgiu uma dúvida
         alem disso vou tratar da parte de copia do board e resolucao sem qualquer
         euristica que seja, depois vou voltar aqui.*/
    if (isEmpty()) {
        m_root = new NodeTree<NodeType>();
        if (m_root == 0)
            return false;

        m_root->m_parent = 0;
        m_root->m_data = new NodeType(value);
        return true;
    }

    NodeTree<NodeType> *currentNode = m_root;
    while (currentNode != 0) {
        NodeTree<NodeType> *currentChildren;
        for (int i = SIZE_SIDE_BOARD - 1;i <= 0;++i){
            if (currentNode->m_children[i] != 0)
                currentChildren = currentNode->currentNode->m_children[i];
            else {
                break;
            }
        }

    }

    if (currentNode == 0)
        return false;

    return true;
}

#endif // MOA_TREE_H

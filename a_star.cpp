#include "a_star.h"
#include <iostream>

A_Star::A_Star(NodeTree<Board> *initialState)
{
    m_initialState = initialState;

    //m_opendedStates.insert(std::make_pair(value,initialState));
    m_opendedStates[initialState->data()->getKey()] = initialState;
}

bool A_Star::search()
{

    // isso é a f(n) da quantidade de movimentos com a quantidade de pecas fora do lugar

    while (!m_opendedStates.empty()) {

        NodeTree<Board> *smallerNode = getSmallerNodeInOpened();
        Board *b = smallerNode->data();
        m_opendedStates.erase(b->getKey());
        m_closedStates[b->getKey()] = smallerNode;

        if (b->winGame()) {
            m_movements = b->getTries();
            return true;
        }

        generateSuccessors(smallerNode);


    }

    return false;
}

NodeTree<Board> *A_Star::getSmallerNodeInOpened()
{
    std::unordered_map<std::string, NodeTree<Board> * >::iterator it;
    it = m_opendedStates.begin();
    NodeTree<Board> *smaller = it->second;

    while (it != m_opendedStates.end()) { /*TODO: testar isso em um programa separado para ver se realmente funciona*/
        NodeTree<Board> *current = it->second;
        Board *smallerBoard = smaller->data();
        Board *currentBoard = current->data();

        if (smallerBoard->winGame())
            return smaller;

        if (currentBoard->winGame())
            return current;

        if (*smallerBoard > *currentBoard)
            smaller = current;

        ++it;
    }

    return smaller;
}

void A_Star::generateSuccessors(NodeTree<Board> *node)
{
    enum BoardDirections directionToParent = NONE;
    if (node->parent() != 0) {
        Board *currentBoard = node->data();
        Board *parentBoard = node->parent()->data();

        Cell *emptyCellCurrent = currentBoard->getEmptyCell();
        Cell *emptyCellParent = parentBoard->getEmptyCell();

        /*parei aqui*/

    }


}


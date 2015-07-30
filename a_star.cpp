#include "a_star.h"
#include <iostream>

A_Star::A_Star(NodeTree<Board> *initialState)
{
    m_initialState = initialState;

    //m_opendedStates.insert(std::make_pair(value,initialState));
    m_opendedStates[initialState->data()->getKey()] = initialState;
}

void debugChildreen(NodeTree<Board > *children[SIZE_SIDE_BOARD])
{
    std::cout << children;
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

        if (!appendIfNecessary(0))
            delete children[0];
        else
            smallerNode->appendChildren(children[0]);

        if (!appendIfNecessary(1))
            delete children[1];
        else
            smallerNode->appendChildren(children[1]);

        if (!appendIfNecessary(2))
            delete children[2];
        else
            smallerNode->appendChildren(children[2]);

        if (!appendIfNecessary(3))
            delete children[3];
        else
            smallerNode->appendChildren(children[3]);

    }

    return false;
}

NodeTree<Board> *A_Star::getSmallerNodeInOpened()
{
    std::unordered_map<std::string, NodeTree<Board> * >::iterator it;
    it = m_opendedStates.begin();
    NodeTree<Board> *smaller = it->second;

    ++it;
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

    enum BoardDirections directionToParent = NONE;//getDirectionToParent(node);
    children[0] = 0;
    children[1] = 0;
    children[2] = 0;
    children[3] = 0;

    Board *currentBoard = node->data();

    if (directionToParent != UP && currentBoard->canUp()) {
        NodeTree<Board> *upChildren = 0;
        Board *upBoard = new Board(*currentBoard);
        upChildren = new NodeTree<Board>(upBoard);
        upBoard->up();
        children[0] = upChildren;
    }

    if (directionToParent != DOWN && currentBoard->canDown()) {
        NodeTree<Board> *downChildren;
        Board *downBoard = new Board(*currentBoard);
        downChildren = new NodeTree<Board>(downBoard);
        downBoard->down();
        children[1] = downChildren;
    }

    if (directionToParent != LEFT && currentBoard->canleft()) {
        NodeTree<Board> *leftChildren;
        Board *leftBoard = new Board(*currentBoard);
        leftChildren = new NodeTree<Board>(leftBoard);
        leftBoard->left();
        children[2] = leftChildren;
    }

    if (directionToParent != RIGHT && currentBoard->canright()) {
        NodeTree<Board> *rightChildren;
        Board *rightBoard = new Board(*currentBoard);
        rightChildren = new NodeTree<Board>(rightBoard);
        rightBoard->right();
        children[3] = rightChildren;
    }

}

BoardDirections A_Star::getDirectionToParent(NodeTree<Board> *node)
{
    enum BoardDirections directionToParent = NONE;
    if (node->parent() != 0) {
        Board *currentBoard = node->data();
        Board *parentBoard = node->parent()->data();

        Cell *emptyCellCurrent = currentBoard->getEmptyCell();
        Cell *emptyCellParent = parentBoard->getEmptyCell();

        char currentRow = emptyCellCurrent->getRow();
        char parentRow = emptyCellParent->getRow();

        char currentCol = emptyCellCurrent->getCol();
        char parentCol = emptyCellCurrent->getCol();

        if (currentRow == parentRow) {
            if (currentCol < parentCol)
                directionToParent = RIGHT;
            else
                directionToParent = LEFT;
        } else if (currentCol == parentCol) {
            if (currentRow < parentCol)
                directionToParent = DOWN;
            else
                directionToParent = UP;
        }

    }

    return directionToParent;
}

bool A_Star::appendIfNecessary(int i)
{
    NodeTree<Board> *child = children[i];

    if (child == 0) {
        return false;
    }

    Board *board = child->data();

    std::unordered_map<std::string, NodeTree<Board> * >::const_iterator itOpeneds = m_opendedStates.find(board->getKey());
    std::unordered_map<std::string, NodeTree<Board> * >::const_iterator itCloseds = m_closedStates.find(board->getKey());

    if (itCloseds != m_closedStates.end() || itOpeneds != m_opendedStates.end())
        return false;

    m_opendedStates[board->getKey()] = child;
    return true;
}
int A_Star::getMovements() const
{
    return m_movements;
}

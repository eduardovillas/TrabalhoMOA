#include "a_star.h"
#include <iostream>

A_Star::A_Star(NodeTree<Board> *initialState)
{
    m_initialState = initialState;

    m_opendedStates[initialState->data()->getKey()] = initialState;
    m_priorityQueue.push(initialState);
}

void debugChildreen(NodeTree<Board > *children[SIZE_SIDE_BOARD])
{
    std::cout << children;
}

bool A_Star::search()
{

    while (!m_opendedStates.empty()) {

        NodeTree<Board> *smallerNode = getSmallerNodeInOpened();

        Board *b = smallerNode->data();
        m_opendedStates.erase(b->getKey());
        m_closedStates[b->getKey()] = smallerNode;

        if (b->winGame()) {
            m_movements = b->getTries();
            return true;
        }

        NodeTree<Board> *children[SIZE_SIDE_BOARD];

        generateSuccessors(smallerNode, children);

        for (int i = 0; i < SIZE_SIDE_BOARD; ++i) {
            if (!appendIfNecessary(children[i])) {
                delete children[i];
            } else {
                smallerNode->appendChildren(children[i]);
            }

        }

    }

    return false;
}

NodeTree<Board> *A_Star::getSmallerNodeInOpened()
{
    NodeTree<Board> *smaller = m_priorityQueue.top();
    m_priorityQueue.pop();

    return smaller;
}

void A_Star::generateSuccessors(NodeTree<Board> *node, NodeTree<Board> *children[SIZE_SIDE_BOARD])
{

    enum BoardDirections directionToParent = getDirectionToParent(node);
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
        char parentCol = emptyCellParent->getCol();

        if (currentRow == parentRow) {
            if (currentCol < parentCol)
                directionToParent = RIGHT;
            else
                directionToParent = LEFT;
        } else if (currentCol == parentCol) {
            if (currentRow < parentRow)
                directionToParent = DOWN;
            else
                directionToParent = UP;
        }

    }

    return directionToParent;
}

bool A_Star::appendIfNecessary(NodeTree<Board> *child)
{

    if (child == 0) {
        return false;
    }

    Board *board = child->data();

    std::unordered_map<std::string, NodeTree<Board> * >::const_iterator itOpeneds = m_opendedStates.find(board->getKey());
    std::unordered_map<std::string, NodeTree<Board> * >::const_iterator itCloseds = m_closedStates.find(board->getKey());

    if ((itCloseds == m_closedStates.end() && itOpeneds == m_opendedStates.end()) ||
            (itCloseds != m_closedStates.end() || itOpeneds != m_opendedStates.end())) {

        NodeTree<Board> *n;
        Board *b = 0;

        if (itCloseds != m_closedStates.end()) {
            n = itCloseds->second;
            b = n->data();
        } else if (itOpeneds != m_opendedStates.end()) {
            n = itOpeneds->second;
            b = n->data();
        }

        if (!b || board->getTries() < b->getTries()) {

            m_closedStates.erase(board->getKey());
            m_opendedStates[board->getKey()] = child;
            m_priorityQueue.push(child);

            return true;
        }

    }

    return false;
}
int A_Star::getMovements() const
{
    return m_movements;
}

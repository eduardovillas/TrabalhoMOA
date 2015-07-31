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

    long long int len = 0;
    while (!m_opendedStates.empty()) {

        NodeTree<Board> *smallerNode = getSmallerNodeInOpened();

        Board *b = smallerNode->data();
        m_opendedStates.erase(b->getKey());
        m_closedStates[b->getKey()] = smallerNode;
        ++len;
        if (b->winGame()) {
            m_movements = b->getTries();
            std::cout << "\n tamanho da arvore " << len << "\n";
            return true;
        }

        generateSuccessors(smallerNode);

        if (!appendIfNecessary(0))
            delete m_children[0];
        else
            smallerNode->appendChildren(m_children[0]);

        if (!appendIfNecessary(1))
            delete m_children[1];
        else
            smallerNode->appendChildren(m_children[1]);

        if (!appendIfNecessary(2))
            delete m_children[2];
        else
            smallerNode->appendChildren(m_children[2]);

        if (!appendIfNecessary(3))
            delete m_children[3];
        else
            smallerNode->appendChildren(m_children[3]);

    }

    return false;
}

NodeTree<Board> *A_Star::getSmallerNodeInOpened()
{
    NodeTree<Board> *smaller = m_priorityQueue.top();
    m_priorityQueue.pop();

    return smaller;
}

void A_Star::generateSuccessors(NodeTree<Board> *node)
{

    enum BoardDirections directionToParent = NONE;//getDirectionToParent(node);
    m_children[0] = 0;
    m_children[1] = 0;
    m_children[2] = 0;
    m_children[3] = 0;

    Board *currentBoard = node->data();

    if (directionToParent != UP && currentBoard->canUp()) {
        NodeTree<Board> *upChildren = 0;
        Board *upBoard = new Board(*currentBoard);
        upChildren = new NodeTree<Board>(upBoard);
        upBoard->up();
        m_children[0] = upChildren;
    }

    if (directionToParent != DOWN && currentBoard->canDown()) {
        NodeTree<Board> *downChildren;
        Board *downBoard = new Board(*currentBoard);
        downChildren = new NodeTree<Board>(downBoard);
        downBoard->down();
        m_children[1] = downChildren;
    }

    if (directionToParent != LEFT && currentBoard->canleft()) {
        NodeTree<Board> *leftChildren;
        Board *leftBoard = new Board(*currentBoard);
        leftChildren = new NodeTree<Board>(leftBoard);
        leftBoard->left();
        m_children[2] = leftChildren;
    }

    if (directionToParent != RIGHT && currentBoard->canright()) {
        NodeTree<Board> *rightChildren;
        Board *rightBoard = new Board(*currentBoard);
        rightChildren = new NodeTree<Board>(rightBoard);
        rightBoard->right();
        m_children[3] = rightChildren;
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
    NodeTree<Board> *child = m_children[i];

    if (child == 0) {
        return false;
    }

    Board *board = child->data();

    std::unordered_map<std::string, NodeTree<Board> * >::const_iterator itOpeneds = m_opendedStates.find(board->getKey());
    std::unordered_map<std::string, NodeTree<Board> * >::const_iterator itCloseds = m_closedStates.find(board->getKey());

    if (itCloseds != m_closedStates.end() || itOpeneds != m_opendedStates.end())
        return false;

    m_opendedStates[board->getKey()] = child;
    m_priorityQueue.push(child);

    return true;
}
int A_Star::getMovements() const
{
    return m_movements;
}

#ifndef A_STAR_H
#define A_STAR_H

#include "moa_global.h"
#include "board.h"
#include "nodetree.h"
#include <unordered_map>
#include <stack>

class A_Star
{
public:
    A_Star(NodeTree<Board> *initialState);

    bool search();
    void getSolutionPath(std::stack<std::string> path);

    int getMovements() const;

private:
    NodeTree<Board> *getSmallerNodeInOpened();
    void generateSuccessors(NodeTree<Board> *node);
    enum BoardDirections getDirectionToParent(NodeTree<Board> *node);
    bool appendIfNecessary(int i);

    std::unordered_map<std::string, NodeTree<Board> * > m_opendedStates;
    std::unordered_map<std::string, NodeTree<Board> * > m_closedStates;
    NodeTree<Board> *m_initialState;
    NodeTree<Board> *m_finalState;
    NodeTree<Board> *children[SIZE_SIDE_BOARD];
    int m_movements;

};



#endif // A_STAR_H

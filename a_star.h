#ifndef A_STAR_H
#define A_STAR_H

#include "moa_global.h"
#include "board.h"
#include "nodetree.h"
#include <unordered_map>
#include <stack>
#include <queue>

namespace std {
template <>
struct greater<NodeTree<Board> * > {
bool operator()(const NodeTree<Board> * leftNodeBoard, const NodeTree<Board> * rightNodeBoard) const
{
    const Board *leftBoard = leftNodeBoard->constData();
    const Board *rightBoard = rightNodeBoard->constData();

    return *leftBoard > *rightBoard;
}
};

}
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
    NodeTree<Board> *m_children[SIZE_SIDE_BOARD];
    std::priority_queue< NodeTree<Board> *, std::vector<NodeTree<Board> * >, std::greater< NodeTree<Board> * > > m_priorityQueue;
    int m_movements;

};



#endif // A_STAR_H

#include "puzzle_solver.h"
#include "heap.h"

using namespace std;

// Constructor (makes a copy of the Board and stores it in b_)
//  Also takes a PuzzleHeuristic which will score boards
PuzzleSolver::PuzzleSolver(const Board &b, PuzzleHeuristic* ph) :
_b(new Board(b)), _expansions(0), _ph(ph)
{}

PuzzleSolver::~PuzzleSolver()
{}



// Run the A* search and builds the solution and tracks
// the number of expansions
void PuzzleSolver::run()
{
  if (_b->solved())
    return;

  // Create an open and closed list and insert the starting board state into both of them
  PuzzleMoveSet closedList;
  Heap<PuzzleMove*, PuzzleMoveScoreComp> openList(2, PuzzleMoveScoreComp());
  PuzzleMove* start = new PuzzleMove(_b);
  closedList.insert(start);
  openList.push(start);
  // Examine all elements in the priority queue open list
  while (!openList.empty())
  {
    PuzzleMove* oldTop = openList.top();
    openList.pop();
    // Once the solution is found, backtrace and remember the necessary moves
    if (oldTop->b->solved())
    {
      while (oldTop->prev)
      {
        _solution.push_front(oldTop->tileMove);
        oldTop = oldTop->prev;
      }
      break;
    }
    // Generate successors
    else
    {
      map<int, Board*> successors = oldTop->b->potentialMoves();
      for (map<int, Board*>::iterator it = successors.begin(); it != successors.end(); ++it)
      {
        PuzzleMove* newMove = new PuzzleMove(it->first, it->second, oldTop);
        newMove->h = _ph->compute(*newMove->b);
        if (closedList.find(newMove) == closedList.end())
        {
          closedList.insert(newMove);
          openList.push(newMove);
          ++_expansions;
        }
        else
          delete newMove;
      }
    }
  }

  // Clean up dynamically allocated PuzzleMoves
  for (PuzzleMoveSet::iterator it = closedList.begin(); it != closedList.end(); ++it)
    delete *it;
}



deque<int> PuzzleSolver::getSolution()
{
  return _solution;
}

int PuzzleSolver::getNumExpansions()
{
  return _expansions;
}
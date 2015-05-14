#include "puzzle_heur.h"
#include <cmath>

int PuzzleManhattanHeuristic::compute(const Board& b)
{
  int totalDist = 0;

  for (int i = 0; i < b.size(); ++i)
  {
    if (b[i] != i && b[i] != 0)
    {
      int subDist = std::abs(i/b.dim()-b[i]/b.dim());
      subDist += std::abs(i%b.dim()-b[i]%b.dim());
      totalDist += subDist;
    }
  }
  
  return totalDist;
}

int PuzzleOutOfPlaceHeuristic::compute(const Board& b)
{
  int numOutOfPlace = 0;

  for (int i = 0; i < b.size(); ++i)
  {
    if (b[i] != i && b[i] != 0)
      ++numOutOfPlace;
  }

  return numOutOfPlace;
}

int PuzzleBFSHeuristic::compute(const Board& b)
{
  return 0;
}
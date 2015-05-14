#include <iostream>
#include <cstdlib>
#include <deque>
#include <sstream>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 5){
    cerr << "Usage: ./puzzle size initMoves seed heur" << endl;
    return 1;
  }

  int size;
  stringstream ss(argv[1]);
  if (!(ss >> size))
  {
    cerr << "Provide a board size length in integer form" << endl;
    return 1;
  }
  if (size < 2)
  {
    cerr << "A board must have size length 2 or greater" << endl;
    return 1;
  }

  int initMoves;
  ss.clear();
  ss.str(argv[2]);
  if (!(ss >> initMoves))
  {
    cerr << "Provide the number of initial moves in integer form" << endl;
    return 1;
  }
  if (initMoves < 0)
  {
    cerr << "The number of initial moves cannot be negative" << endl;
    return 1;
  }

  int seed;
  ss.clear();
  ss.str(argv[3]);
  if (!(ss >> seed))
  {
    cerr << "Provide the seed in integer form" << endl;
    return 1;
  }

  int heur;
  ss.clear();
  ss.str(argv[4]);
  if (!(ss >> heur))
  {
    cerr << "Select a heuristic by value:" << endl
         << "0 for BFS, 1 for tiles out place, 2 for Manhattan distance" << endl;
    return 1;
  }
  if (heur < 0 || heur > 2)
  {
    cerr << "Valid heuristic choices:" << endl
         << "0 for BFS, 1 for tiles out place, 2 for Manhattan distance" << endl;
    return 1;
  }


  Board gameBoard(size, initMoves, seed);
  PuzzleHeuristic* ph;
  if (heur == 0)
    ph = new PuzzleBFSHeuristic();
  else if (heur == 1)
    ph = new PuzzleOutOfPlaceHeuristic();
  else
    ph = new PuzzleManhattanHeuristic();


  while (!gameBoard.solved())
  {
    cout << gameBoard << endl
         << "Enter tile number to move or -1 for a cheat: ";

    int option;
    cin >> option;

    if (option == 0)
    {
      delete ph;
      return 0;
    }
    else if (option == -1)
    {
      PuzzleSolver solutionSearcher(gameBoard, ph);
      solutionSearcher.run();

      deque<int> solution = solutionSearcher.getSolution();
      int expansions = solutionSearcher.getNumExpansions();

      cout << "Try this sequence:" << endl;
      for (deque<int>::iterator it = solution.begin(); it != solution.end(); ++it)
        cout << *it << " ";
      cout << "\n(Expansions = " << expansions << ")\n" << endl;
    }
    else if (option > 0 && option < (size*size))
      gameBoard.move(option);
    else
    {
      cerr << "Invalid input" << endl
           << "Press -1 for a cheat, 0 to quit, or a tile number adjacent to the blank space to move it" << endl;
    }
  }
  
  cout << gameBoard << endl;
  delete ph;

  return 0;
}

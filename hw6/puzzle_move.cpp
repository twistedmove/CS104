#include "puzzle_move.h"

// Constructor for starting Board (i.e. initial move)
PuzzleMove::PuzzleMove(Board* board) :
tileMove(-1), b(board), g(0), h(-1), prev(NULL)
{}

// Constructor for subsequent search boards 
// (i.e. those returned by Board::potentialMoves() )
PuzzleMove::PuzzleMove(int tile, Board* board, PuzzleMove *parent) :
tileMove(tile), b(board), g(parent->g+1), h(-1), prev(parent)
{}

PuzzleMove::~PuzzleMove()
{
  delete b;
}
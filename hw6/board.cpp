#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include "board.h"

using namespace std;

Board::Board(int dim, int numInitMoves, int seed )
{
  _size = dim*dim;
  _tiles = new int[_size];
  srand(seed);
  for(int i=0; i < _size; i++){
    _tiles[i] = i;
  }
  int blankLoc = 0;
  while(numInitMoves > 0){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < _size){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      _tiles[blankLoc] = _tiles[randNeighbor];
      _tiles[randNeighbor] = 0;
      blankLoc = randNeighbor;
      numInitMoves--;
    }
  }
}

Board::Board(const Board& other)
{
  _size = other._size;
  _tiles = new int[_size];
  for (int i = 0; i < _size; ++i)
    _tiles[i] = other._tiles[i];
}

Board::~Board()
{
  delete [] _tiles;
}





void Board::move(int tile)
{
  int side_dim = dim();
  int tr, tc, br, bc;

  // find tile row and column
  int i=-1;
  while(_tiles[++i] != tile);

  tr = i / side_dim; 
  tc = i % side_dim;

  // find blank row and column
  int j=-1;
  while(_tiles[++j] != 0);

  br = j / side_dim;
  bc = j % side_dim;

  if( abs(static_cast<double>(tr-br)) + abs(static_cast<double>(tc-bc)) != 1){
    cout << "Invalid move of tile " << tile << " at ";
    cout << tr << "," << tc << " and blank spot at ";
    cout << br << "," << bc << endl;
    return;
  }
  // Swap tile and blank spot
  _tiles[j] = tile;
  _tiles[i] = 0;
}

// Generate new boards representing all the potential moves of tiles into 
// the current blank tile location. The returned map should have
// the key as the tile moved and the value as a new Board object with the
// configuration reflecting the move of that tile into the blank spot
map<int, Board*> Board::potentialMoves() const
{
  map<int, Board*> potentialBoards;

  int sideLen = dim();
  // find blank row and column
  int blankIndx = -1;
  while(_tiles[++blankIndx] != 0);

  int br = blankIndx / sideLen;
  int bc = blankIndx % sideLen;

  // Generate moved tile above blank tile if possible
  if (br > 0)
  {
    Board* nBoard = new Board(*this);
    nBoard->_tiles[blankIndx] = nBoard->_tiles[blankIndx - sideLen];
    nBoard->_tiles[blankIndx - sideLen] = 0;
    potentialBoards.insert(make_pair(nBoard->_tiles[blankIndx], nBoard));
  }
  // Generate moved tile right of blank tile if possible
  if (bc < sideLen-1)
  {
    Board* nBoard = new Board(*this);
    nBoard->_tiles[blankIndx] = nBoard->_tiles[blankIndx + 1];
    nBoard->_tiles[blankIndx + 1] = 0;
    potentialBoards.insert(make_pair(nBoard->_tiles[blankIndx], nBoard));
  }
  // Generate moved tile below blank tile if possible
  if (br < sideLen-1)
  {
    Board* nBoard = new Board(*this);
    nBoard->_tiles[blankIndx] = nBoard->_tiles[blankIndx + sideLen];
    nBoard->_tiles[blankIndx + sideLen] = 0;
    potentialBoards.insert(make_pair(nBoard->_tiles[blankIndx], nBoard));
  }
  // Generate moved tile left of blank tile if possible
  if (bc > 0)
  {
    Board* nBoard = new Board(*this);
    nBoard->_tiles[blankIndx] = nBoard->_tiles[blankIndx - 1];
    nBoard->_tiles[blankIndx - 1] = 0;
    potentialBoards.insert(make_pair(nBoard->_tiles[blankIndx], nBoard));
  }
  
  return potentialBoards;
}

// Returns true if the board is solved, false otherwise
bool Board::solved() const
{
  for (int i = 0; i < _size; ++i)
  {
    if (_tiles[i] != i)
      return false;
  }

  return true;
}





// Prints the board in the desired 2D format (utilizes printRowBanner())
ostream& operator<<(ostream &os, const Board &b)
{
  int sideLen = b.dim();
  if (sideLen == 0)
    return os;

  b.printRowBanner(os);
  for (int i = 0; i < sideLen; ++i)
  {
    for (int j = 0; j < sideLen; ++j)
    {
      if (b._tiles[i*sideLen+j] == 0)
        os << "|  ";
      else if (b._tiles[i*sideLen+j] < 10)
        os << "| " << b._tiles[i*sideLen+j];
      else
        os << '|' << b._tiles[i*sideLen+j];
    }
    os << '|' << endl;
    b.printRowBanner(os);
  }
  return os;
}

// Checks if this board is less-than another.  We define less than
// as a "string-style" comparison of the tile array (i.e. Starting by comparing
// the 0-th tile in this Board and the other.
// If this board's tile is less than the other board's tile value, return true
// If they are equal, continue with the next tile location and repeat
bool Board::operator<(const Board& rhs) const
{
  for(int i = 0; i < _size; ++i)
  {
    if (_tiles[i] < rhs._tiles[i])
      return true;
    if (_tiles[i] > rhs._tiles[i])
      return false;
  }
  return false;
}





const int& Board::operator[](int loc) const 
{ 
  return _tiles[loc]; 
}

int Board::size() const 
{ 
  return _size; 
}

int Board::dim() const
{
  return static_cast<int>(sqrt(_size));
}

void Board::printRowBanner(ostream& os) const
{
  int side_dim = dim();
  if(side_dim == 0) return;
  os << '+';
  for(int i=0; i < side_dim; i++){
    os << "--+";
  }
  os << endl;
}
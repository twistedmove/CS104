#include "rbbst.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Rectangle
{
  int ID;
  int length;
  int height;

  Rectangle(int id, int l, int h) : ID(id), length(l), height(h)
  {}
  void rotate()
  {
    int temp = length;
    length = height;
    height = temp;
  }
};


void processFile(ifstream &, RedBlackTree<int, Rectangle*> &,
                 RedBlackTree<int, pair<int, int> > &, bool** &, int &, int &);

bool solve(RedBlackTree<int, Rectangle*>::iterator, RedBlackTree<int, Rectangle*> &, 
           RedBlackTree<int, pair<int, int> > &, bool** &, const int &, const int &);

bool isValid(Rectangle*, bool** &, int, int);

void insert(Rectangle*, bool** &, int, int, RedBlackTree<int, pair<int, int> > &);

void remove(Rectangle*, bool** &, int, int);



int main(int argc, char const *argv[])
{
  if (argc < 3)
  {
    cerr << "Usage: ./rectangles <input file> <output file>" << endl;
    return 1;
  }

  ifstream iFile(argv[1]);
  if (iFile.fail())
  {
    cerr << "Unable to open input file: " << argv[1] << endl;
    return 1;
  }
  ofstream oFile(argv[2]);
  if (oFile.fail())
  {
    cerr << "Unable to open output file: " << argv[2] << endl;
    return 1;
  }
  RedBlackTree<int, Rectangle*> tileMap;
  RedBlackTree<int, pair<int, int> > solutionMap;
  bool** grid;
  int gridL, gridH;

  processFile(iFile, tileMap, solutionMap, grid, gridL, gridH);

  if (solve(tileMap.begin(), tileMap, solutionMap, grid, gridL, gridH))
  {
    for (RedBlackTree<int, pair<int, int> >::iterator it = solutionMap.begin(); it != solutionMap.end(); ++it)
    {
      oFile << it->first << " " << it->second.first << " " << it->second.second << " " << 
            tileMap.find(it->first)->second->length << " " << tileMap.find(it->first)->second->height << endl;
    }
  }
  else
    oFile << "no solution found" << endl;
  oFile.close();

  // Clean up dynamic memory
  for (RedBlackTree<int, Rectangle*>::iterator it = tileMap.begin(); it != tileMap.end(); ++it)
    delete it->second;
  for (int i = 0; i < gridH; ++i)
    delete [] grid[i];
  delete [] grid;

  return 0;
}


void processFile(ifstream &file, RedBlackTree<int, Rectangle*> &tileMap, 
                 RedBlackTree<int, pair<int, int> > &solutionMap, bool** &grid, int &length, int &height)
{
  string line;
  int numTiles;
  stringstream ss;

  getline(file, line);
  ss.str(line);
  ss >> length >> height >> numTiles;
  grid = new bool*[height];
  for (int i = 0; i < height; ++i)
  {
    grid[i] = new bool[length];
    for (int j = 0; j < length; ++j)
      grid[i][j] = false;
  }

  int data1, data2, data3;
  for (int i = 0; i < numTiles; ++i)
  {
    ss.clear();
    ss.str("");
    getline(file, line);
    ss.str(line);

    ss >> data1 >> data2 >> data3;
    tileMap.insert(make_pair(data1, new Rectangle(data1, data2, data3)));
    solutionMap.insert(make_pair(data1, make_pair(-1,-1)));
  }

  file.close();
}

bool solve(RedBlackTree<int, Rectangle*>::iterator it, RedBlackTree<int, Rectangle*> &tileMap, 
           RedBlackTree<int, pair<int, int> > &solutionMap, bool** &grid, const int &gLength, const int &gHeight)
{
  if (it == tileMap.end())
    return true;

  for (int i = 0; i < gHeight - it->second->height + 1; ++i)
  {
    for (int j = 0; j < gLength - it->second->length + 1; ++j)
      if (isValid(it->second, grid, i, j))
      {
        insert(it->second, grid, i, j, solutionMap);
        RedBlackTree<int, Rectangle*>::iterator sendIt = it;
        if (solve(++sendIt, tileMap, solutionMap, grid, gLength, gHeight))
          return true;
        else
          remove(it->second, grid, i, j);
      }
  }

  // Try rotating the rectangle if it's not square
  if (it->second->length != it->second->height)
  {
    it->second->rotate();

    for (int i = 0; i < gHeight - it->second->height + 1; ++i)
    {
      for (int j = 0; j < gLength - it->second->length + 1; ++j)
        if (isValid(it->second, grid, i, j))
        {
          insert(it->second, grid, i, j, solutionMap);
          RedBlackTree<int, Rectangle*>::iterator sendIt = it;
          if (solve(++sendIt, tileMap, solutionMap, grid, gLength, gHeight))
            return true;
          else
            remove(it->second, grid, i, j);
        }
    }
  }

  return false;
}

bool isValid(Rectangle* rect, bool** &grid, int row, int col)
{
  for (int i = row; i < row + rect->height; ++i)
  {
    for (int j = col; j < col + rect->length; ++j)
    {
      if (grid[i][j])
        return false;
    }
  }

  return true;
}

void insert(Rectangle* rect, bool** &grid, int row, int col, RedBlackTree<int, pair<int, int> > &solutionMap)
{
  for (int i = row; i < row + rect->height; ++i)
  {
    for (int j = col; j < col + rect->length; ++j)
      grid[i][j] = true;
  }

  solutionMap.find(rect->ID)->second = make_pair(col, row);
}

void remove(Rectangle* rect, bool** &grid, int row, int col)
{
  for (int i = row; i < row + rect->height; ++i)
  {
    for (int j = col; j < col + rect->length; ++j)
      grid[i][j] = false;
  }
}
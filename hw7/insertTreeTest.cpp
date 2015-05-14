#include "rbbst.h"

using namespace std;

int main()
{
  RedBlackTree<int, char> alphaTestTree;

  cout << "Testing insert on tree where keys are 1-26 for chars a-z and 27-52 for chars A-Z" << endl

       << "Inserting 30, D" << endl;
  alphaTestTree.insert(make_pair(30, 'D'));
  cout << "Expected tree:" << endl
       << "[ (30, D) ]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 20, t" << endl;
  alphaTestTree.insert(make_pair(20, 't'));
  cout << "Expected tree:" << endl
       << "[[ (20, t) ] (30, D) ]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 40, N" << endl;
  alphaTestTree.insert(make_pair(40, 'N'));
  cout << "Expected tree:" << endl
       << "[[ (20, T) ] (30, D) [ (40, N) ]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 10, j (recolor and root recolor)" << endl;
  alphaTestTree.insert(make_pair(10, 'j'));
  cout << "Expected tree:" << endl
       << "[[[ (10, j) ] (20, T) ] (30, D) [ (40, N) ]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 5, N (single right rotate)" << endl;
  alphaTestTree.insert(make_pair(5, 'e'));
  cout << "Expected tree:" << endl
       << "[[[ (5, e) ] (10, j) [ (20, T) ]] (30, D) [ (40, N) ]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 45, S" << endl;
  alphaTestTree.insert(make_pair(45, 'S'));
  cout << "Expected tree:" << endl
       << "[[[ (5, e) ] (10, j) [ (20, T) ]] (30, D) [ (40, N) [ (45, S) ]]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 42, P (right rotate and left rotate)" << endl;
  alphaTestTree.insert(make_pair(42, 'P'));
  cout << "Expected tree:" << endl
       << "[[[ (5, e) ] (10, j) [ (20, T) ]] (30, D) [[ (40, N) ] (42, P) [ (45, S) ]]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 26, z (recolor)" << endl;
  alphaTestTree.insert(make_pair(26, 'z'));
  cout << "Expected tree:" << endl
       << "[[[ (5, e) ] (10, j) [ (20, T) [ (26, z) ]]] (30, D) [[ (40, N) ] (42, P) [ (45, S) ]]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 28, B (single left rotate)" << endl;
  alphaTestTree.insert(make_pair(28, 'B'));
  cout << "Expected tree:" << endl
       << "[[[ (5, e) ] (10, j) [[ (20, T) ] (26, z) [ (28, B) ]]] (30, D) [[ (40, N) ] (42, P) [ (45, S) ]]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 1, a" << endl;
  alphaTestTree.insert(make_pair(1, 'a'));
  cout << "Expected tree:" << endl
       << "[[[[ (1, a) ] (5, e) ] (10, j) [[ (20, T) ] (26, z) [ (28, B) ]]] (30, D) [[ (40, N) ] (42, P) [ (45, S) ]]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  cout << "Inserting 2, b (left rotate and right rotate)" << endl;
  alphaTestTree.insert(make_pair(2, 'b'));
  cout << "Expected tree:" << endl
       << "[[[[ (1, a) ] (2, b) [ (5, e) ]] (10, j) [[ (20, T) ] (26, z) [ (28, B) ]]] (30, D) [[ (40, N) ] (42, P) [ (45, S) ]]]" << endl
       << "Actual tree:" << endl;
  alphaTestTree.print();

  return 0;
}
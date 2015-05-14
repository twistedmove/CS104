#include "rbbst.h"

using namespace std;

int main()
{
  RedBlackTree<int, char> alphaTestTree;
  alphaTestTree.insert(make_pair(30, 'D'));
  alphaTestTree.insert(make_pair(20, 't'));
  alphaTestTree.insert(make_pair(40, 'N'));
  alphaTestTree.insert(make_pair(10, 'j'));
  alphaTestTree.insert(make_pair(5, 'e'));
  alphaTestTree.insert(make_pair(45, 'S'));
  alphaTestTree.insert(make_pair(42, 'P'));
  alphaTestTree.insert(make_pair(26, 'z'));
  alphaTestTree.insert(make_pair(28, 'B'));
  alphaTestTree.insert(make_pair(1, 'a'));
  alphaTestTree.insert(make_pair(2, 'b'));

  cout << "Testing iterator on tree where keys are 1-26 for chars a-z and 27-52 for chars A-Z" << endl;
  alphaTestTree.print();

  cout << "Creating iterator to tree.begin()" << endl;
  RedBlackTree<int, char>::iterator it = alphaTestTree.begin();
  cout << "By * dereference begin key is: " << (*it).first << endl
       << "By -> dereference begin value is: " << it->second << endl;

  cout << "Iterating through all values" << endl;
  while (it != alphaTestTree.end())
  {
    cout << it->second << " ";
    ++it;
  }

  cout << "\nAttempting to find key 10 (should work)" << endl;
  if (alphaTestTree.find(10) == alphaTestTree.end())
    cout << "Unsuccessful" << endl;
  else
    cout << "Successful" << endl;

  cout << "Attempting to find key 11 (should not work)" << endl;
  if (alphaTestTree.find(11) == alphaTestTree.end())
    cout << "Unsuccessful" << endl;
  else
    cout << "Successful" << endl;  

    cout << "Attempting to increment iterator past end" << endl;
    ++it;

  return 0;
}
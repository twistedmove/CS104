#include "../msort.h"
#include <string>
#include <iostream>

using namespace std;

struct lessIntComp
{
  bool operator()(const int& lhs, const int& rhs)
  {
    return lhs <= rhs;
  }
};
struct greatIntComp
{
  bool operator()(const int& lhs, const int& rhs)
  {
    return lhs >= rhs;
  }
};
struct evenIntComp
{
  bool operator()(const int& lhs, const int& rhs)
  {
    return lhs % 2 == 0;
  }
};

struct alphStrComp
{
  bool operator()(const string& lhs, const string& rhs)
  {
    return lhs <= rhs;
  }
};
struct sizeStrComp
{
  bool operator()(const string& lhs, const string& rhs)
  {
    return lhs.size() <= rhs.size();
  }
};
struct rStrComp
{
  bool operator()(const string& lhs, const string& rhs)
  {
    for (int i = 0; i < (int)lhs.size(); ++i)
    {
      if (lhs[i] == 'r')
        return true;
    }
    return false;
  }
};
int main()
{
  lessIntComp iComp1;
  greatIntComp iComp2;
  evenIntComp iComp3;
  vector<int> intVec;
  intVec.push_back(4);
  intVec.push_back(10);
  intVec.push_back(-2);
  intVec.push_back(38);
  intVec.push_back(0);
  intVec.push_back(4);
  intVec.push_back(7);
  intVec.push_back(-6);

  alphStrComp sComp1;
  sizeStrComp sComp2;
  rStrComp sComp3;
  vector<string> stringVec;
  stringVec.push_back("car");
  stringVec.push_back("sideways");
  stringVec.push_back("spaceship");
  stringVec.push_back("lazy");
  stringVec.push_back("fox");
  stringVec.push_back("t-rex");


  cout << "Vector of ints is initially:" << endl;
  for (vector<int>::iterator i = intVec.begin(); i != intVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting in ascending order it is:" << endl;
  mergeSort(intVec, iComp1);
  for (vector<int>::iterator i = intVec.begin(); i != intVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting so even numbers come before odds it is:" << endl;
  mergeSort(intVec, iComp3);
  for (vector<int>::iterator i = intVec.begin(); i != intVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting in descending order it is:" << endl;
  mergeSort(intVec, iComp2);
  for (vector<int>::iterator i = intVec.begin(); i != intVec.end(); ++i)
    cout << *i << " ";
  cout << endl;


  cout << "\nVector of strings is initially:" << endl;
  for (vector<string>::iterator i = stringVec.begin(); i != stringVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting alphabetically it is:" << endl;
  mergeSort(stringVec, sComp1);
  for (vector<string>::iterator i = stringVec.begin(); i != stringVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting by size it is:" << endl;
  mergeSort(stringVec, sComp2);
  for (vector<string>::iterator i = stringVec.begin(); i != stringVec.end(); ++i)
    cout << *i << " ";

  cout << "\nAfter sorting so words with r's come before others it is:" << endl;
  mergeSort(stringVec, sComp3);
  for (vector<string>::iterator i = stringVec.begin(); i != stringVec.end(); ++i)
    cout << *i << " ";
  cout << endl;

  return 0;
}
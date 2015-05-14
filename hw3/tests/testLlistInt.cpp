#include "../llistint.h"
#include <iostream>

using namespace std;

int main()
{
  cout << "Testing function push_back()" << endl;
	LListInt tPushBack;
  cout << "Test list size is initially: " << tPushBack.size() << endl;

  cout << "Pushing back 5" << endl;
  tPushBack.push_back(5);
  cout << "Test list size is now: " << tPushBack.size() << endl
       << "Item at index 0 is: " << tPushBack.get(0) << endl;

  cout << "Pushing back 10 and 15" << endl;
  tPushBack.push_back(10);
  tPushBack.push_back(15);
  cout << "Test list size is now: " << tPushBack.size() << endl
       << "Item at index 0 is: " << tPushBack.get(0) << endl
       << "Item at index 1 is: " << tPushBack.get(1) << endl
       << "Item at index 2 is: " << tPushBack.get(2) << endl;


  cout << "\nTesting copy constructor" << endl
       << "Calling copy constructor with constructor parameter as pushback list" << endl;
  LListInt tCopy1(tPushBack);
  cout << "New list size is: " << tCopy1.size() << endl
       << "Item at index 0 is: " << tCopy1.get(0) << endl
       << "Item at index 1 is: " << tCopy1.get(1) << endl
       << "Item at index 2 is: " << tCopy1.get(2) << endl;

  cout << "Clearing copy list 1" << endl;
  tCopy1.clear();
  cout << "Copy list 1 list empty is: " << boolalpha << tCopy1.empty() << endl;

  cout << "Calling copy constructor with constructor parameter as copy list 1" << endl;
  LListInt tCopy2(tCopy1);
  cout << "New list size is: " << tCopy2.size() << endl;

  cout << "Calling copy constructor with assignment as pushback list" << endl;
  LListInt tCopy3 = tPushBack;
  cout << "New list size is: " << tCopy3.size() << endl
       << "Item at index 0 is: " << tCopy3.get(0) << endl
       << "Item at index 1 is: " << tCopy3.get(1) << endl
       << "Item at index 2 is: " << tCopy3.get(2) << endl;

  cout << "Clearing copy list 3" << endl;
  tCopy3.clear();
  cout << "Copy list 3 list empty is: " << tCopy3.empty() << endl;

  cout << "Calling copy constructor with assignment as copy list 3" << endl;
  LListInt tCopy4 = tCopy3;
  cout << "New list size is: " << tCopy4.size() << endl;


  cout << "\nTesting assignment" << endl
       << "Making a list of 20, 30" << endl;
  LListInt tAssign;
  tAssign.push_back(20);
  tAssign.push_back(30);
  cout << "New list size is: " << tAssign.size() << endl
       << "Item at index 0 is: " << tAssign.get(0) << endl
       << "Item at index 1 is: " << tAssign.get(1) << endl;

  cout << "Setting new list equal to itself" << endl;
  tAssign = tAssign;
  cout << "New list size is: " << tAssign.size() << endl
       << "Item at index 0 is: " << tAssign.get(0) << endl
       << "Item at index 1 is: " << tAssign.get(1) << endl;

  cout << "Setting new list equal to pushback list" << endl;
  tAssign = tPushBack;
  cout << "New list size is: " << tAssign.size() << endl
       << "Item at index 0 is: " << tAssign.get(0) << endl
       << "Item at index 1 is: " << tAssign.get(1) << endl
       << "Item at index 2 is: " << tAssign.get(2) << endl;

  cout << "Setting new list equal to the cleared copy list 3" << endl;
  tAssign = tCopy3;
  cout << "New list empty is: " << tAssign.empty() << endl;

	return 0;
}
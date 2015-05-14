#include "../llistdbl.h"
#include <iostream>

using namespace std;

int main()
{
	LListDbl* list = new LListDbl();

	cout << "Attempting to remove from index 0 of empty list" << endl;
	list->remove(0);

	cout << "Attempting to remove from index > size_ of empty list" << endl;
	list->remove(20);

	cout << "Inserting 20 at index 0" << endl;
	list->insert(0,20);
	if(list->get(0) == 20)
		cout << "Insertion successful" << endl;

	cout << "Inserting 10 at index 0 (head)" << endl;
	list->insert(0,10);
	cout << "List size is now " << list->size() << endl;

	cout << "Inserting 30 at index 2 (tail)" << endl;
	list->insert(2,30);
	cout << "List size is now " << list->size() << endl;

	cout << "Inserting 5 at index 1 (middle)" << endl;
	list->insert(1,5);
	cout << "Size expected: 4 \t actual: " << list->size()
			 << "\n Expected index 0 value: 10 \t actual: " << list->get(0)
			 << "\n Expected index 2 value: 20 \t actual: " << list->get(2) << endl;

  cout << "Attempting to insert at index > size_" << endl;
  list->insert(20,1);
  cout << "Size expected: 4 \t actual: " << list->size() << endl;

  cout << "Attempting to insert at negative index" << endl;
  list->insert(-20,1);
  cout << "Size expected: 4 \t actual: " << list->size() << endl;

  cout << "Attempting to remove at negative index" << endl;
  list->remove(-20);

  cout << "Attempting to remove from index = size_" << endl;
  list->remove(4);

  cout << "Removing 5 at index 1 (middle)" << endl;
	list->remove(1);
	cout << "Size expected: 3 \t actual: " << list->size()
			 << "\n Expected index 0 value: 10 \t actual: " << list->get(0)
			 << "\n Expected index 1 value: 20 \t actual: " << list->get(1) << endl;

	cout << "Removing 30 at index 2 (tail)" << endl;
	list->remove(2);
	cout << "List size is now " << list->size() << endl;

	cout << "Removing 10 at index 0 (head)" << endl;
	list->remove(0);
	cout << "List size is now " << list->size() 
			 << " and the item value is " << list->get(0) << endl;

	cout << "All tests finished" << endl;
}
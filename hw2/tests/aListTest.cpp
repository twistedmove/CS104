#include "../alistint.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Attempting to create a negatively sized array list" << endl;
	AListInt toDefault(-5);

	cout << "Creating array list of capacity 1" << endl;
	AListInt small(1);
	cout << "Array size is " << small.size()
			 << "\nArray empty is " << boolalpha << small.empty() << endl;

	cout << "Attempting to remove from index 0 of empty list" << endl;
	small.remove(0);

	cout << "Attempting to remove from index > _size of empty list" << endl;
	small.remove(20);

	cout << "Inserting 1 at index 0" << endl;
	small.insert(0,1);
	if(small.get(0) == 1)
		cout << "Insertion successful" << endl;

	cout << "Inserting 2 at index 1 (max size)" << endl;
	small.insert(1,2);
	cout << "Array size is now " << small.size() << endl;

	cout << "Inserting 3 at index 2 (max size)" << endl;
	small.insert(2,3);
	cout << "Array size is now " << small.size() << endl;

	cout << "Inserting 1.5 at index 1 (middle)" << endl;
	small.insert(1,1.5);
	cout << "Size expected: 4 \t actual: " << small.size()
			 << "\n Expected index 0 value: 1 \t actual: " << small.get(0)
			 << "\n Expected index 2 value: 2 \t actual: " << small.get(1) << endl;

	cout << "Attempting to insert at index > _size" << endl;
  small.insert(20,1);
  cout << "Size expected: 4 \t actual: " << small.size() << endl;

  cout << "Attempting to insert at negative index" << endl;
  small.insert(-20,1);
  cout << "Size expected: 4 \t actual: " << small.size() << endl;

  cout << "Attempting to remove from negative index" << endl;
  small.remove(-20);

  cout << "Attempting to remove from index = _size" << endl;
  small.remove(4);

  cout << "Removing 1.5 at index 1 (middle)" << endl;
  small.remove(1);
  cout << "Size expected: 3 \t actual: " << small.size()
			 << "\n Expected index 0 value: 1 \t actual: " << small.get(0)
			 << "\n Expected index 1 value: 2 \t actual: " << small.get(1) << endl;

	cout << "Rewriting 2 as 10 at index 1 (middle)" << endl;
  small.set(1,10);
  if(small.get(1) == 10)
  	cout << "Success" << endl;

  cout << "Attempting to rewrite invalid index" << endl;
  small.set(10,10);

	cout << "Removing 3 at index 2 (tail)" << endl;
	small.remove(2);
	cout << "Array size is now " << small.size() << endl;

	cout << "Removing 1 at index 0 (head)" << endl;
	small.remove(0);
	cout << "Array size is now " << small.size() 
			 << " and the item value is " << small.get(0)
			 << "\nArray empty is " << small.empty() << endl;

	cout << "Attempting to get invalid index" << endl;
	small.get(10);

	cout << "All tests finished" << endl;
}
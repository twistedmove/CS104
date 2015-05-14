#include "../setint.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Testing functions size(), empty(), and insert()" << endl;
  SetInt tester;
  cout << "Test set size is initially: " << tester.size() << endl
       << "Test set empty is: " << boolalpha << tester.empty() << endl;

  cout << "Inserting 5" << endl;
  tester.insert(5);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Inserting 10 and 15" << endl;
  tester.insert(10);
  tester.insert(15);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Attempting to insert 5 again (should fail)" << endl;
  tester.insert(5);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Attempting to insert 15 again (should fail)" << endl;
  tester.insert(15);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;


  cout << "\nTesting function remove()" << endl
       << "Attempting to remove -5" << endl;
  tester.remove(-5);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Attempting to remove 100" << endl;
  tester.remove(100);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Removing 10" << endl;
  tester.remove(10);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Removing 5 and 15" << endl;
  tester.remove(5);
  tester.remove(15);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;

  cout << "Attempting to remove from empty set" << endl;
  tester.remove(5);
  cout << "Test set size is: " << tester.size() << endl
       << "Test set empty is: " << tester.empty() << endl;


  cout << "\nTesting function exists()" << endl
       << "Empty set contains 5: " << tester.exists(5) << endl;

  cout << "Filling new set with 3, 9, 6" << endl;
  SetInt tester2;
  tester2.insert(3);
  tester2.insert(9);
  tester2.insert(6);
  cout << "New set contains 6: " << tester2.exists(6) << endl
       << "New set contains 0: " << tester2.exists(0) << endl
       << "New set contains 3: " << tester2.exists(3) << endl;


  cout << "\nTesting functions first() and next()" << endl
       << "Empty set .first() gives NULL?" << endl;
  if (tester.first() == NULL)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  cout << "3,9,6 set .first() dereferenced gives: " << *tester2.first() << endl;

  cout << "Calling .next() on 3,9,6 set until NULL" << endl;
  int count = 1;
  while(tester2.next() != NULL)
  {
    cout << ".next() call #" << count << endl;
    count++;
  }

  cout << "Inserting 1 into 3,9,6 set" << endl;
  tester2.insert(1);
  cout << "Calling .first() on 3,9,6,1 set" << endl;
  tester2.first();
  cout << ".next() dereferenced gives: " << *tester2.next() << endl;


  cout << "\nTesting set union and intersection" << endl
       << "Creating a receiver set, another empty set, set 6,7,10, and set 11,12,13" << endl;
  SetInt receiver, tester3, tester4, tester5;
  tester4.insert(6);
  tester4.insert(7);
  tester4.insert(10);
  tester5.insert(11);
  tester5.insert(12);
  tester5.insert(13);

  cout << "Calling empty set.setUnion(empty set)" << endl;
  receiver = tester.setUnion(tester3);
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set empty is: " << receiver.empty() << endl;

  cout << "Calling empty set.setUnion(set 11,12,13)" << endl;
  receiver = tester.setUnion(tester5);
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set is: " << *receiver.first() << " ";
  for (int i = 0; i < 2; i++)
    cout << *receiver.next() << " ";
  cout << endl;

  cout << "Calling set 6,7,10.setUnion(set 3,9,6,1)" << endl;
  receiver = tester4.setUnion(tester2);
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set is: " << *receiver.first() << " ";
  for (int i = 0; i < 5; i++)
    cout << *receiver.next() << " ";
  cout << endl;

  cout << "Calling set 6,7,10 | set 11,12,13" << endl;
  receiver = tester4 | tester5;
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set is: " << *receiver.first() << " ";
  for (int i = 0; i < 5; i++)
    cout << *receiver.next() << " ";
  cout << endl;

  cout << "Calling empty set.setIntersection(empty set)" << endl;
  receiver = tester3.setIntersection(tester);
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set empty is: " << receiver.empty() << endl;

  cout << "Calling set 11,12,13.setIntersection(empty set)" << endl;
  receiver = tester5.setIntersection(tester);
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set empty is: " << receiver.empty() << endl;

  cout << "Calling set 6,7,10.setIntersection(set 3,9,6,1)" << endl;
  receiver = tester4.setIntersection(tester2);
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set is: " << *receiver.first() << endl;

  cout << "Calling set 6,7,10 & set 6,7,10" << endl;
  receiver = tester4 | tester4;
  cout << "Receiver set size is: " << receiver.size() << endl
       << "Receiver set is: " << *receiver.first() << " ";
  for (int i = 0; i < 2; i++)
    cout << *receiver.next() << " ";
  cout << endl;

	return 0;
}
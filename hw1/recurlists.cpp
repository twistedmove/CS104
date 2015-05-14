#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Item
{
  Item(int v, Item* n)
  {
    val = v;
    next = n;
  }

  int val;
  Item* next;
};

// Returns head pointer to new linked list copied
//  from two given linked lists
Item* concatenate(Item* head1, Item* head2);
void deleteList(Item* &head);
double findAverage(Item* head);
void findAvgHelp(Item* &head, double &sum, int &counts);
// Makes a singly linked list from one line of ints
//  separated by spaces from a txt file
void makeList(Item* &head, ifstream &ifile);
void printList(ostream &ofile, Item* &head);
// Copies a source linked list to the end of the head
//  linked list
void recurCopy(Item* &head, Item* &tail, Item* &source);
void removeEvens(Item* &head);
void removeEvensHelp(Item* &head, Item* &prev);

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    cerr << "Usage: ./recurlists <input filename> <output filename>" << endl;
    return 1;
  }

  ifstream ifile(argv[1]);
  if(ifile.fail())
  {
    cerr << "Error: Could not open file " << argv[1] << endl;
    return 1;
  }
  ofstream ofile(argv[2]);
  if(ofile.fail())
  {
    cerr << "Error: Could not open file " << argv[2] << endl;
    return 1;
  }

  Item* head1 = NULL;
  makeList(head1, ifile);
  Item* head2 = NULL;
  makeList(head2, ifile);
  ifile.close();

  Item* head3 = concatenate(head1, head2);
  printList(ofile, head3);

  removeEvens(head3);
  printList(ofile, head3);

  double avg = findAverage(head3);
  printList(ofile, head3);
  ofile << avg;
  ofile.close();

  deleteList(head1);
  deleteList(head2);
  deleteList(head3);

  return 0;
}



Item* concatenate(Item* head1, Item* head2)
{
  Item* head3 = NULL;
  Item* tail = NULL;
  recurCopy(head3, tail, head1);
  recurCopy(head3, tail, head2);
  return head3;
}

void deleteList(Item* &head)
{
  if(head == NULL)
    return;
  else
  {
    Item* temp = head;
    head = head->next;
    delete temp;
    deleteList(head);
  }
}

double findAverage(Item* head)
{
  double sum = 0;
  int counts = 0;
  findAvgHelp(head, sum, counts);

  if(counts == 0)
    return 0;
  else
    return sum/counts;
}

void findAvgHelp(Item* &head, double &sum, int &counts)
{
  if(head == NULL)
    return;
  else
  {
    sum += head->val;
    counts++;
    findAvgHelp(head->next, sum, counts);
  }
}

void makeList(Item* &head, ifstream &ifile)
{
  Item* tail = NULL;
  string list;
  getline(ifile, list);
  istringstream iss(list);
  int num;
  while(iss >> num)
  {
    if(head == NULL)
    {
      head = new Item(num, NULL);
      tail = head;
    }
    else
    {
      tail->next = new Item(num, NULL);
      tail = tail->next;
    }
  }
}

void printList(ostream &ofile, Item* &head)
{
  if(head == NULL)
    ofile << endl;
  else {
    ofile << head->val << " ";
    printList(ofile, head->next);    
  }
}

void recurCopy(Item* &head, Item* &tail, Item* &source)
{
  if(source == NULL)
    return;
  if(head == NULL)
  {
    head = new Item(source->val, NULL);
    tail = head;
    recurCopy(head, tail, source->next);
  }
  else
  {
    tail->next = new Item(source->val, NULL);
    tail = tail->next;
    recurCopy(head, tail, source->next);
  }
}

void removeEvens(Item* &head)
{
  Item* prev = head;
  removeEvensHelp(head, prev);
}

void removeEvensHelp(Item* &head, Item* &prev)
{
  if(head == NULL)
    return;
  if(head->val % 2 == 0)
  {
    // Special case required when deleting first list
    //  item because there is no previous
    if(prev == head)
    {
      Item* temp = head;
      head = head->next;
      prev = head;
      delete temp;
      removeEvensHelp(head, prev);
    }
    else
    {
      Item* temp = head;
      prev->next = head->next;
      head = head->next;
      delete temp;
      removeEvensHelp(head, prev);
    }
  }
  else
    removeEvensHelp(head->next, prev->next);
}

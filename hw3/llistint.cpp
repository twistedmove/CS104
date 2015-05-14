#include "llistint.h"
#include <cstdlib>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

LListInt::LListInt(const LListInt& other)
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;

  Item* marker = other.head_;
  while(marker)
  {
    push_back(marker->val);
    marker = marker->next;
  }
}

LListInt& LListInt::operator=(const LListInt& other)
{
  if (this == &other)
    return *this;

  if (this->head_)
    clear();

  Item* marker = other.head_;
  while(marker)
  {
    push_back(marker->val);
    marker = marker->next;
  }
  return *this;
}



bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

void LListInt::insert(int loc, const int& val)
{
  if (loc >= 0 && loc <= size_)
  {
    if (loc == 0)
    {
      Item* nHead = new Item;
      nHead->prev = NULL;
      nHead->next = head_;
      nHead->val = val;

      // In case there is only one item in the list
      if (head_ == NULL)
        tail_ = nHead;
      else
        head_->prev = nHead;

      head_ = nHead;
      size_++;
    }
    else if (loc == size_)
    {
      Item* nTail = new Item;
      nTail->prev = tail_;
      nTail->next = NULL;
      nTail->val = val;

      tail_->next = nTail;
      tail_ = nTail;
      size_++;
    }
    else
    {
      Item* before = getNodeAt(loc-1);

      Item* nItem = new Item;
      nItem->prev = before;
      nItem->next = before->next;
      nItem->val = val;

      before->next->prev = nItem;
      before->next = nItem;
      size_++;
    }
  }
}

void LListInt::remove(int loc)
{
  if (loc >= 0 && loc < size_)
  {
    if (loc == 0)
    {
      Item* temp = head_;
      head_ = head_->next;
      // In case there is only one item in the list
      if (head_ == NULL)
      {
        tail_ = NULL;
      }
      delete temp;
      size_--;
    }
    else if (loc == size_-1)
    {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = NULL;
      delete temp;
      size_--;
    }
    else
    {
      Item* toDel = getNodeAt(loc);
      toDel->prev->next = toDel->next;
      toDel->next->prev = toDel->prev;
      delete toDel;
      size_--;
    }
  }
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void LListInt::push_back(const int& val)
{
	Item* nTail = new Item;
  nTail->prev = tail_;
  nTail->next = NULL;
  nTail->val = val;

  if (tail_)
  	tail_->next = nTail;
  else
  	head_ = nTail;

  tail_ = nTail;
  size_++;
}



LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
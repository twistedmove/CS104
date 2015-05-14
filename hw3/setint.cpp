#include "setint.h"
#include <cstddef>

SetInt::SetInt()
{

}

SetInt::~SetInt()
{

}



int SetInt::size() const
{
  return list_.size();
}

bool SetInt::empty() const
{
  return list_.empty();
}

void SetInt::insert(const int& val)
{
  if (!exists(val))
    list_.push_back(val);
}

void SetInt::remove(const int& val)
{
  for (int i = 0; i < list_.size(); i++)
  {
    if (list_.get(i) == val)
    {
      list_.remove(i);
      return;
    }
  }
}

bool SetInt::exists(const int& val) const
{
  for (int i = 0; i < list_.size(); i++)
  {
    if (list_.get(i) == val)
      return true;
  }
  return false;
}

int const* SetInt::first()
{
  if (!list_.empty())
  {
    iterations_ = 1;
    return &list_.get(0);
  }
  else
    return NULL;
}

int const* SetInt::next()
{
  if (iterations_ < list_.size())
  {
    int* iterator = &list_.get(iterations_);
    iterations_++;
    return iterator;
  }
  else
    return NULL;
}

SetInt SetInt::setUnion(const SetInt& other) const
{
  SetInt uSet;
  //Initialize union set to "this" set
  uSet.list_ = list_;
  //Insert everything from "other" set (insert checks for duplicates)
  for (int i = 0; i < other.list_.size(); i++)
    uSet.insert(other.list_.get(i));
  return uSet;
}

SetInt SetInt::setIntersection(const SetInt& other) const
{
  SetInt iSet;
  //Initialize intersection set to "this" set element-by-element
  // only if the element is also in "other"
  for (int i = 0; i < list_.size(); ++i)
  {
  	if (other.exists(list_.get(i)))
  		iSet.list_.push_back(list_.get(i));
  }
  return iSet;
}

SetInt SetInt::operator|(const SetInt& other) const
{
  return setUnion(other);
}

SetInt SetInt::operator&(const SetInt& other) const
{
  return setIntersection(other);
}
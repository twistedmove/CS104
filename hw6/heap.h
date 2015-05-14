#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <vector>

template <typename T, typename Comparator >
class Heap
{
 public:
  /// Constructs an m-ary heap for any m >= 2
  Heap(int m, Comparator c);

  /// Destructor as needed
  ~Heap();

  /// Adds an item
  void push(const T& item);

  /// returns the element at the top of the heap 
  ///  max (if max-heap) or min (if min-heap)
  T const & top() const;

  /// Removes the top element
  void pop();

  /// returns true if the heap is empty
  bool empty() const;

 private:
  /// Add whatever helper functions and data members you need below
  void trickleUp(int loc);
  void trickleDown(int loc);

  int maxChildren_;
  Comparator comp_;
  std::vector<T> nodeList_;
};

// Add implementation of member functions here
template <typename T, typename Comparator>
Heap<T, Comparator>::Heap(int m, Comparator c) : comp_(c)
{
  if (m >= 2)
    maxChildren_ = m;
  // Defaults to binary heap if invalid input is given
  else
    maxChildren_ = 2;
}

template <typename T, typename Comparator>
Heap<T, Comparator>::~Heap()
{}

template <typename T, typename Comparator>
void Heap<T, Comparator>::push(const T& item)
{
  nodeList_.push_back(item);
  trickleUp(nodeList_.size()-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename Comparator>
T const & Heap<T,Comparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::logic_error("can't top an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return nodeList_[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename Comparator>
void Heap<T,Comparator>::pop()
{
  if(empty()){
    throw std::logic_error("can't pop an empty heap");
  }

  // Replace the first with the last node and delete the last node
  nodeList_[0] = nodeList_.back();
  nodeList_.pop_back();
  // Reorder the semiheap
  trickleDown(0);
}

template<typename T, typename Comparator>
bool Heap<T, Comparator>::empty() const
{
  return nodeList_.empty();
}



template<typename T, typename Comparator>
void Heap<T, Comparator>::trickleUp(int loc)
{
  int parent = (loc-1)/maxChildren_;
  while (loc > 0 && comp_(nodeList_[loc], nodeList_[parent]))
  {
    // Swap the nodes
    T temp = nodeList_[loc];
    nodeList_[loc] = nodeList_[parent];
    nodeList_[parent] = temp;
    // Check the parent node
    loc = parent;
    parent = (loc-1)/maxChildren_;
  }
}

template<typename T, typename Comparator>
void Heap<T, Comparator>::trickleDown(int loc)
{
  // If there is at least one child
  while (maxChildren_*loc+1 < nodeList_.size())
  {
    // Examine all children to find the biggest/smallest
    int childToSwap = maxChildren_*loc+1;
    for (int i = 2; i <= maxChildren_; ++i)
    {
      // Stop checking children if you go out of bounds
      if (maxChildren_*loc+i >= nodeList_.size())
        break;
      else
      {
        if (comp_(nodeList_[maxChildren_*loc+i], nodeList_[childToSwap]))
          childToSwap = maxChildren_*loc+i;
      }
    }

    // Compare the node and the biggest/smallest child and continue 
    //  the trickling as appropriate
    if (comp_(nodeList_[childToSwap], nodeList_[loc]))
    {
      // Swap the nodes
      T temp = nodeList_[childToSwap];
      nodeList_[childToSwap] = nodeList_[loc];
      nodeList_[loc] = temp;
      // Check the child node
      loc = childToSwap;
    }
    else
      return;
  }
}
#endif
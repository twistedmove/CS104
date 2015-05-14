#ifndef MSORT_H
#define MSORT_H
#include <vector>

template <class T, class Comparator>
void mergeSort(std::vector<T>& myArray, Comparator comp)
{
  std::vector<T> temp(myArray);
  mergeSortHelp(myArray, temp, comp, 0, myArray.size()-1);
}

template<class T, class Comparator>
void mergeSortHelp(std::vector<T>& myArray, std::vector<T>& temp, Comparator comp, int start, int end)
{
  if (start < end)
  {
    int mid = (start+end)/2;
    mergeSortHelp(myArray, temp, comp, start, mid);
    mergeSortHelp(myArray, temp, comp, mid+1, end);
    merge(myArray, temp, comp, start, mid, end);
  }
}

template<class T, class Comparator>
void merge(std::vector<T>& myArray, std::vector<T>& temp, Comparator comp, int start, int mid, int end)
{
  int it1 = start, it2 = mid+1;
  for (int j = start; j <= end; ++j)
  {
    if (it1 <= mid && (it2 > end || comp(myArray[it1], myArray[it2])))
    {
      temp[j] = myArray[it1];
      ++it1;
    }
    else
    {
      temp[j] = myArray[it2];
      ++it2;
    }
  }

  for (int j = start; j <= end; ++j)
    myArray[j] = temp[j];
}
#endif
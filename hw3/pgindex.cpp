#include "setint.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

//Removes punctuation from the beginning and end of a string uncut, manipulating directly by reference
// can change uncut to empty "" if uncut is all punctuation
void cut(string& uncut);
//Returns the string cut in all lowercase while changing cut to "" directly by reference
// if cut contains any punctuation besides hyphen '-' returns empty ""
// if cut contains hyphen '-' returns everything before the hyphen and cut is changed to everything after
string refine(string& cut);

int main(int argc, char* argv[])
{
	if (argc < 3)
  {
    cerr << "Usage: ./pgindex <input filename> <output filename> <any number of search words>" << endl;
    return 1;
  }

  ifstream ifile(argv[1]);
  if (ifile.fail())
  {
    cerr << "Unable to open file: " << argv[1] << endl;
    return 1;
  }
  ofstream ofile(argv[2]);
  if (ofile.fail())
  {
    cerr << "Unable to open file: " << argv[2] << endl;
    return 1;
  }

  string test;
  int pageNum = 1;
  map<string, SetInt*> words;

  //Fill the map word index
  while (ifile >> test)
  {
    if (test == "<pagebreak>")
      ++pageNum;
    else
    {
      cut(test);
      while (test.size() >= 2)
      {
        string clean = refine(test);
        if (clean.size() >= 2)
        {
          if (words.find(clean) != words.end())
            words[clean]->insert(pageNum);
          else
          {
            SetInt* toAdd = new SetInt;
            toAdd->insert(pageNum);
            words.insert(pair<string, SetInt*>(clean, toAdd));
          }
        }
      }
    }
  }

  //Search for the given words in the index and output the results
  for (int i = 3; i < argc; ++i)
  {
    string lookup = argv[i];
    for (int i = 0; i < (int)lookup.size(); ++i)
      lookup[i] = tolower(lookup[i]);

    if (words.find(lookup) != words.end())
    {
      const int* result = words[lookup]->first();
      ofile << *result;
      do
      {
        result = words[lookup]->next();
        if (result)
          ofile << " " << *result;
      }while (result);
      ofile << endl;
    }
    else
      ofile << "None" << endl;
  }

  ifile.close();
  ofile.close();

  //Delete the dynamic sets stored in the map before the map is destroyed
  map<string, SetInt*>::iterator it;
  for (it = words.begin(); it != words.end(); ++it)
    delete it->second;

	return 0;
}


void cut(string& uncut)
{
  bool allPunct = true;
  //Remove punctuation from beginning of uncut
  for (int i = 0; i < (int)uncut.size(); ++i)
  {
    if (isalnum(uncut[i]))
    {
      uncut = uncut.substr(i, uncut.size()-i);
      i = uncut.size();
      allPunct = false;
    }
  }
  if (!allPunct)
  {
    //Remove punctuation from end of uncut
    for (int i = uncut.size()-1; i >= 0; --i)
    {
      if (isalnum(uncut[i]))
      {
        uncut = uncut.substr(0, i+1);
        i = -1;
      }
    }
  }
  //If no character was alpha-numeric, clear the string
  else
    uncut = "";
}

string refine(string& cut)
{
  string refined;
  for (int i = 0; i < (int)cut.size(); ++i)
  {
    if (cut[i] == '-')
    {
      cut = cut.substr(i+1, cut.size()-i-1);
      return refined;
    }
    else if (ispunct(cut[i]))
    {
      cut = "";
      return cut;
    }
    else
      refined += tolower(cut[i]);
  }
  cut = "";
  return refined;
}
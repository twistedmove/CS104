#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;

std::string convToLower(std::string src) 
{
  std::transform(src.begin(), src.end(), src.begin(), ::tolower);
  return src;
}

/** Complete the code to convert a string containing a rawWord 
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWord) 
{
  set<string> parsedWords;

  string tempWord;
  stringstream ss(rawWord);
  while (ss >> tempWord)
  {
    tempWord = convToLower(tempWord);
    while (tempWord.size() >= 2)
    {
      bool punct = false;
      for (int i = 0; i < (int)tempWord.size(); ++i)
      {
        if (ispunct(tempWord[i]))
        {
          string word = tempWord.substr(0,i);
          if (word.size() >= 2)
            parsedWords.insert(word);

          punct = true;
          tempWord = tempWord.substr(i+1,tempWord.size()-i-1);

          i = tempWord.size();
        }
      }

      if (!punct)
      {
        parsedWords.insert(tempWord);
        tempWord = "";
      }
    }
  }

  return parsedWords;
}

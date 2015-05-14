#include "movie.h"
#include "util.h"
#include <sstream>

using namespace std;

Movie::Movie(string genre, string rating, string name, double price, int qty) : Product("movie", name, price, qty)
{
  genre_ = genre;
  rating_ = rating;
}

Movie::~Movie()
{

}

set<string> Movie::keywords() const
{
  set<string> keyWords = parseStringToWords(name_);
  keyWords.insert(convToLower(genre_));

  return keyWords;
}

string Movie::displayString() const
{
  string display = name_ + "\n" +
                   "Genre: " + genre_ + " Rating: " + rating_ + "\n";

  stringstream num;
  num << price_;
  display = display + num.str() + " ";
  num.str("");
  num << qty_;
  display = display + num.str() + " left.";

  return display;
}

void Movie::dump(ostream& os) const
{
  Product::dump(os);
  os << genre_ << "\n" << rating_ << endl;
}
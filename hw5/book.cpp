#include "book.h"
#include "util.h"
#include <sstream>

using namespace std;

Book::Book(string ISBN, string author, string name, double price, int qty) : Product("book", name, price, qty)
{
  ISBN_ = ISBN;
  author_ = author;
}

Book::~Book()
{

}

set<string> Book::keywords() const
{
  set<string> keyWords = parseStringToWords(name_);
  keyWords.insert(ISBN_);

  set<string> parsedWords = parseStringToWords(author_);
  for (set<string>::iterator it = parsedWords.begin(); it != parsedWords.end(); ++it)
    keyWords.insert(*it);

  return keyWords;
}

string Book::displayString() const
{
  string display = name_ + "\n" +
                   "Author: " + author_ + " ISBN: " + ISBN_ + "\n";

  stringstream num;
  num << price_;
  display = display + num.str() + " ";
  num.str("");
  num << qty_;
  display = display + num.str() + " left.";

  return display;
}

void Book::dump(ostream& os) const
{
  Product::dump(os);
  os << ISBN_ << "\n" << author_ << endl;
}
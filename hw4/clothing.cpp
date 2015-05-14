#include "clothing.h"
#include "util.h"
#include <sstream>

using namespace std;

Clothing::Clothing(string size, string brand, string name, double price, int qty) : Product("clothing", name, price, qty)
{
  size_ = size;
  brand_ = brand;
}

Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const
{
  set<string> keyWords = parseStringToWords(name_);

  set<string> parsedWords = parseStringToWords(brand_);
  for (set<string>::iterator it = parsedWords.begin(); it != parsedWords.end(); ++it)
    keyWords.insert(*it);

  return keyWords;
}

string Clothing::displayString() const
{
  string display = name_ + "\n" +
                   "Brand: " + brand_ + " Size: " + size_ + "\n";

  stringstream num;
  num << price_;
  display = display + num.str() + " ";
  num.str("");
  num << qty_;
  display = display + num.str() + " left.";

  return display;
}

void Clothing::dump(ostream& os) const
{
  Product::dump(os);
  os << size_ << "\n" << brand_ << endl;
}
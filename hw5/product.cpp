#include <sstream>
#include <iomanip>
#include "product.h"

using namespace std;

Product::Product(const std::string category, const std::string name, double price, int qty) : 
  name_(name),
  price_(price),
  qty_(qty),
  category_(category)
{

}

Product::~Product()
{
  // Delete dynamically allocated reviews
  for (set<Review*>::iterator it = reviews_.begin(); it != reviews_.end(); ++it)
    delete *it;
}


double Product::getPrice() const
{
  return price_;
}

std::string Product::getName() const
{
  return name_;
}

void Product::subtractQty(int num)
{
  qty_ -= num;
}

int Product::getQty() const
{
  return qty_;
}

double Product::getAvgReview() const
{
  if (reviews_.empty())
    return 0;
  else
  {
    double sum = 0;
    for (set<Review*>::iterator it = reviews_.begin(); it != reviews_.end(); ++it)
      sum += (*it)->rating;
    return sum/reviews_.size();
  }
}

vector<Review*> Product::getReviews()
{
  vector<Review*> reviews (reviews_.begin(), reviews_.end());
  return reviews;
}


/**
 * default implementation...can be overriden in a future
 * assignment
 */ 
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
  (void)searchTerms;
  return false;
}

void Product::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
}

void Product::dumpReviews(std::ostream& os) const
{
  for (set<Review*>::iterator it = reviews_.begin(); it != reviews_.end(); ++it)
    (*it)->dump(os);
}

void Product::addReview(Review* r)
{
  reviews_.insert(r);
}

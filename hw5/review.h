#ifndef REVIEW_H
#define REVIEW_H
#include <string>
#include <iostream>
#include <sstream>

/**
 * Models a review for the product identified by prodName
 */
struct Review
{
  Review() :  prodName(), rating(), date(), reviewText()
  { }
  Review(std::string& prod, 
	 int& rate, 
	 std::string& d, 
	 std::string& review_text) :
    prodName(prod), 
    rating(rate), 
    date(d), 
    reviewText(review_text)
  { }

  void dump(std::ostream& os)
  {
    os << this->prodName << "\n" << this->rating << " " << this->date << " " << this->reviewText << std::endl;
  }

  std::string displayString()
  {
    std::stringstream ss;
    ss << rating;
    return date+"     Score: "+ss.str()+"\n"+reviewText;
  }
  
  std::string prodName;
  int rating;
  std::string date;
  std::string reviewText;
};

#endif

#include "actual_datastore.h"
#include "util.h"
#include <iostream>

using namespace std;

ActualDataStore::ActualDataStore()
{
  keyLinkUpdated_ = true;
}

ActualDataStore::~ActualDataStore()
{
  //Delete dynamically allocated users
  for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
    delete it->second;
  
  //Delete dynamically allocated products
  for (map<string, Product*>::iterator it = products_.begin(); it != products_.end(); ++it)
    delete it->second;
}



void ActualDataStore::addProduct(Product* p)
{
  products_.insert(make_pair(p->getName(), p));
  keyLinkUpdated_ = false;
}

void ActualDataStore::addUser(User* u)
{
  users_.insert(make_pair(u->getName(), u));
}

void ActualDataStore::addReview(Review* r)
{
  if (products_.find(r->prodName) != products_.end())
    products_[r->prodName]->addReview(r);
}

vector<Product*> ActualDataStore::search(vector<string>& terms, int type)
{
  if (!keyLinkUpdated_)
    updateKeywords();

  set<Product*> matches;

  for (vector<string>::iterator it = terms.begin(); it != terms.end(); ++it)
  {
    if (keyWordLink_.find(*it) != keyWordLink_.end())
    {
      if (type == 0)
      {
        //The first keyword match must be assigned to the set directly,
        //  since any intersection with an empty set is the empty set
        if (matches.size())
          matches = setIntersection(keyWordLink_[*it], matches);
        else
          matches = keyWordLink_[*it];
      }
      else
        matches = setUnion(keyWordLink_[*it], matches);
    }
  }

  vector<Product*> results (matches.begin(), matches.end());
  return results;
}

void ActualDataStore::dump(ostream& ofile)
{
  ofile << "<products>" << endl;
  for (map<string, Product*>::iterator it = products_.begin(); it != products_.end(); ++it)
    it->second->dump(ofile);
  ofile << "</products>" << endl;

  ofile << "<users>" << endl;
  for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
    it->second->dump(ofile);
  ofile << "</users>" << endl;

  ofile << "<reviews>" << endl;
  for (map<string, Product*>::iterator it = products_.begin(); it != products_.end(); ++it)
    it->second->dumpReviews(ofile);
  ofile << "</reviews>";
}



void ActualDataStore::addToCart(string userName, Product* p)
{
  if (users_.find(userName) != users_.end() && products_.find(p->getName()) != products_.end())
  {
    if (userCarts_.find(userName) != userCarts_.end())
      userCarts_[userName].push_back(p);
    else
    {
      vector<Product*> cart (1,p);
      userCarts_.insert(make_pair(userName, cart));
    }
  }
}

void ActualDataStore::viewCart(string userName)
{
  if (userCarts_.find(userName) != userCarts_.end())
  {
    int itemCount = 1;
    for (vector<Product*>::iterator item = userCarts_[userName].begin(); item != userCarts_[userName].end(); ++item)
    {
      cout << "Item " << itemCount++ << endl
           << (*item)->displayString() << endl;
    }
  }
}

void ActualDataStore::buyCart(string userName)
{
  if (userCarts_.find(userName) != userCarts_.end())
  {
    for (vector<Product*>::iterator item = userCarts_[userName].begin(); item != userCarts_[userName].end();)
    {
      if ((*item)->getQty() >= 1 && users_[userName]->getBalance() >= (*item)->getPrice())
      {
        (*item)->subtractQty(1);
        users_[userName]->deductAmount((*item)->getPrice());
        userCarts_[userName].erase(item);
      }
      else
        ++item;
    }
  }
}

void ActualDataStore::removeItem(string userName, int index)
{
  if (userCarts_.find(userName) != userCarts_.end())
  {
    if (index >= 0 && index < (int)userCarts_[userName].size())
      userCarts_[userName].erase(userCarts_[userName].begin()+index);
  }
}



set<string> ActualDataStore::getUsersNames()
{
  set<string> names;
  for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
    names.insert(it->first);
  return names;
}

vector<Review*> ActualDataStore::getProductReviews(string pName)
{
  vector<Review*> reviews;

  if (products_.find(pName) != products_.end())
  {
    reviews = products_[pName]->getReviews();
    return reviews;
  }
  else
    return reviews;
}

vector<Product*> ActualDataStore::getUserCart(string userName)
{
  vector<Product*> cart;

  if (userCarts_.find(userName) != userCarts_.end())
  {
    cart = userCarts_[userName];
    return cart;
  }
  else
    return cart;
}



void ActualDataStore::updateKeywords()
{
  for (map<string, Product*>::iterator itPM = products_.begin(); itPM != products_.end(); ++itPM)
  {
    set<string>keyWords = itPM->second->keywords();
    for (set<string>::iterator itSS = keyWords.begin(); itSS != keyWords.end(); ++ itSS)
    {
      if (keyWordLink_.find(*itSS) != keyWordLink_.end())
        keyWordLink_[*itSS].insert(itPM->second);
      else
      {
        set<Product*> keyMatch;
        keyMatch.insert(itPM->second);
        keyWordLink_.insert(make_pair(*itSS, keyMatch));
      }
    }
  }
}
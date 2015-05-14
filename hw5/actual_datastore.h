#ifndef ACTUAL_DATASTORE_H
#define ACTUAL_DATASTORE_H 
#include "datastore.h"
#include <map>

class ActualDataStore : public DataStore
{
public:
  ActualDataStore();
  ~ActualDataStore();

  /**
   * Adds a product to the data store
   */
  void addProduct(Product* p);
 
  /**
   * Adds a user to the data store
   */
  void addUser(User* u);

  /**
   * Adds a review to a product
   */
  void addReview(Review* r);

  /**
   * Performs a search of products whose keywords match the given "terms"
   *  type 0 = AND search (intersection of results for each term) while
   *  type 1 = OR search (union of results for each term)
   */
  std::vector<Product*> search(std::vector<std::string>& terms, int type);

  /**
   * Reproduce the database file from the current Products and User values
   */
  void dump(std::ostream& ofile);


  /**
   * Adds product p to the user userName's cart
   */
  void addToCart(std::string userName, Product* p);

  /**
   * Displays each item in user userName's cart with ascending indices
   */
  void viewCart(std::string userName);

  /**
   * Iterates through user userName's cart
   *  If the item is in stock and the user has enough money:
   *    removes from cart, reduces stock by 1, reduces user's credit
   *  Otherwise does nothing
   */
  void buyCart(std::string userName);

  /**
   * Removes the product at the given index from the vector of products
   *  that makes up the given user's cart
   */
  void removeItem(std::string userName, int index);


  /**
   * Returns a set of all users' names
   */
  std::set<std::string> getUsersNames();

  /**
   * Returns a vector of all reviews of a product
   */
  std::vector<Review*> getProductReviews(std::string);

  /**
   * Returns a vector of all products in a user's cart
   */
  std::vector<Product*> getUserCart(std::string);

protected:
  /**
   * Fills the keyWordLink_ map with keywords from all products in the 
   *  database along with the corresponding set of products that match said
   *  keyword
   */
  void updateKeywords();

private:
  std::map<std::string, User*> users_;
  std::map<std::string, Product*> products_;
  std::map<std::string, std::vector<Product*> > userCarts_;
  std::map<std::string, std::set<Product*> > keyWordLink_;
  bool keyLinkUpdated_;

};
#endif
#ifndef LLISTINT_H
#define LLISTINT_H

class LListInt {
 public:
  struct Item {
    int val;
    Item *prev;
    Item *next;
  };

  /**
   * Default constructor
   */
  LListInt();

  /**
   * Destructor
   */
  ~LListInt();

  /**
   * Copy constructor
   */
  LListInt(const LListInt& other);

  /**
   * Assignment Operator
   */
  LListInt& operator=(const LListInt& other);
  
  /**
   * Returns true if the list is empty, false otherwise
   */
  bool empty() const;

  /**
   * Returns the current number of items in the list 
   */
  int size() const;

  /**
   * Inserts val so it appears at index, pos
   */
  void insert(int pos, const int& val);

  /**
   * Removes the value at index, pos
   */
  void remove(int pos);

  /**
   * Overwrites the old value at index, pos, with val
   */
  void set(int pos, const int& val);

  /**
   * Returns the value at index, pos
   */
  int& get(int pos);

  /**
   * Returns the value at index, pos
   */
  int const & get(int pos) const;

  /**
   * Deletes all items in the list
   */
  void clear();

  /**
   * Adds an item to the back of the list in O(1) time
   */
  void push_back(const int& val);

 private:
  /** 
   * Returns a pointer to the item at index, pos
   *  and NULL otherwise
   */
  Item* getNodeAt(int pos) const;

  /**
   * Data members
   */
  Item* head_;
  Item* tail_;
  int size_;
};

#endif

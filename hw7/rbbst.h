/*
 * rbbst.h
 *
 * Date        Author    Notes
 * =====================================================
 * 2014-04-14  Kempe     Initial version
 * 2015-04-06  Redekopp  Updated formatting and removed
 *                         KeyExistsException
 */

#include <iostream>
#include <exception>
#include <cstdlib>
#include "bst.h"

/* -----------------------------------------------------
 * Red-Black Nodes and Search Tree
 ------------------------------------------------------*/

enum Color {red, black};

template <class KeyType, class ValueType>
class RedBlackNode : public Node<KeyType, ValueType>
{
public:
  RedBlackNode (KeyType k, ValueType v, RedBlackNode<KeyType, ValueType> *p)
    : Node<KeyType, ValueType> (k, v, p)
    { color = red; }
  
  virtual ~RedBlackNode () {}
  
  Color getColor () const
    { return color; }
  
  void setColor (Color c)
    { color = c; }
  
  virtual RedBlackNode<KeyType, ValueType> *getParent () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_parent; }
  
  virtual RedBlackNode<KeyType, ValueType> *getLeft () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_left; }
  
  virtual RedBlackNode<KeyType, ValueType> *getRight () const
    { return (RedBlackNode<KeyType,ValueType>*) this->_right; }
  
 protected:
  Color color;
};

/* -----------------------------------------------------
 * Red-Black Search Tree
 ------------------------------------------------------*/

template <class KeyType, class ValueType>
class RedBlackTree : public BinarySearchTree<KeyType, ValueType>
{
public:
  void insert (const std::pair<const KeyType, ValueType>& new_item)
  {
  	Node<KeyType, ValueType>* curr = this->root;
  	if (curr == NULL)
  	{
  	  this->root = new RedBlackNode<KeyType, ValueType>(new_item.first, new_item.second, NULL);
  	  static_cast<RedBlackNode<KeyType, ValueType>*>(this->root)->setColor(black);
  	}
    else
    {
      // Find the "leaf" node where the new node should belong
      while (true)
      {
        // Overwrite repeat keys
        if (curr->getKey() == new_item.first)
        {
          curr->setValue(new_item.second);
          return;
        }
        else if (curr->getKey() < new_item.first)
        {
          if (curr->getRight())
            curr = curr->getRight();
          else
            break;
        }
        else
        {
          if (curr->getLeft())
            curr = curr->getLeft();
          else
            break;
        }
      }
      RedBlackNode<KeyType, ValueType>* newNode = new RedBlackNode<KeyType, ValueType>(new_item.first, new_item.second, static_cast<RedBlackNode<KeyType, ValueType>*>(curr));
      // Insert new node
      if (curr->getKey() < new_item.first)
        curr->setRight(newNode);
      else
        curr->setLeft(newNode);

      // Fix tree if the new node has a red parent
      if (static_cast<RedBlackNode<KeyType, ValueType>*>(curr)->getColor() == red)
        fixTree(static_cast<RedBlackNode<KeyType, ValueType>*>(curr));
    }
  }
  /* This one is yours to implement.
     It should insert the (key, value) pair to the tree, 
     making sure that it remains a valid Red-Black Tree.
     If the key is already in the tree
     (with a possibly different associated value),
     then it should overwrite the value with the new one.
     We strongly recommend defining suitable (private) helper functions. */

protected:
  void fixTree(RedBlackNode<KeyType, ValueType>* n)
  {
    // Root recolor base case
    if (n == this->root)
    {
      n->setColor(black);
      return;
    }

    RedBlackNode<KeyType, ValueType>* uncle;
    if (n->getParent()->getLeft() != n)
      uncle = n->getParent()->getLeft();
    else
      uncle = n->getParent()->getRight();

    // Dual red recolor
    if (uncle && uncle->getColor() == red)
    {
      uncle->setColor(black);
      n->setColor(black);
      n->getParent()->setColor(red);
      // Check if root was made red
      if (n->getParent() == this->root)
        fixTree(n->getParent());
      // Check if now red parent has red grandparent
      else if (n->getParent()->getParent()->getColor() == red)
        fixTree(n->getParent()->getParent());
    }
    // Red and black rotations
    else
    {
      if (n->getParent()->getLeft() == n)
      {
        // Left red, left red - single rotate
        if (n->getLeft() && n->getLeft()->getColor() == red)
        {
          rotateRight(n->getParent());
          n->setColor(black);
          n->getRight()->setColor(red);
        }
        // Left red, right red - double rotate
        else
        {
          rotateLeft(n);
          rotateRight(n->getParent()->getParent());
          n->getParent()->setColor(black);
          n->getParent()->getRight()->setColor(red);
        }
      }
      else
      {
        // Right red, left red - double rotate
        if (n->getLeft() && n->getLeft()->getColor() == red)
        {
          rotateRight(n);
          rotateLeft(n->getParent()->getParent());
          n->getParent()->setColor(black);
          n->getParent()->getLeft()->setColor(red);
        }
        // Right red, right red - single rotate
        else
        {
          rotateLeft(n->getParent());
          n->setColor(black);
          n->getLeft()->setColor(red);
        }
      }
    }
  }

  void rotateLeft(RedBlackNode<KeyType, ValueType>* p)
  {
    RedBlackNode<KeyType, ValueType>* oldLeft = p->getRight()->getLeft();
    RedBlackNode<KeyType, ValueType>* grandparent = p->getParent();
    // Grandparent/new top link
    if (grandparent)
    {
      if (grandparent->getLeft() == p)
        grandparent->setLeft(p->getRight());
      else
        grandparent->setRight(p->getRight());
    }
    p->getRight()->setParent(grandparent);
    // Parent/new top link
    p->getRight()->setLeft(p);
    p->setParent(p->getRight());
    // Old left link
    p->setRight(oldLeft);
    if (oldLeft)
      oldLeft->setParent(p);
    // Root repair
    if (p == this->root)
      this->root = p->getParent();
  }

  void rotateRight(RedBlackNode<KeyType, ValueType>* p)
  {
    RedBlackNode<KeyType, ValueType>* oldRight = p->getLeft()->getRight();
    RedBlackNode<KeyType, ValueType>* grandparent = p->getParent();
    // Grandparent/new top link
    if (grandparent)
    {
      if (grandparent->getLeft() == p)
        grandparent->setLeft(p->getLeft());
      else
        grandparent->setRight(p->getLeft());
    }
    p->getLeft()->setParent(grandparent);
    // Parent/new top link
    p->getLeft()->setRight(p);
    p->setParent(p->getLeft());
    // Old right link
    p->setLeft(oldRight);
    if (oldRight)
      oldRight->setParent(p);
    // Root repair
    if (p == this->root)
      this->root = p->getParent();
  }
};


#include <iostream>
#include <sstream>
#include <string>

#include "avl.h"
using namespace std;

//Public Methods
//Destructor
AVLTree::~AVLTree()
{
  makeEmpty(root);
}

//Implement Insert
void AVLTree::Insert (int32_t val)
{
  insert(val, root);
}

//Implement Delete
// choose smallest node on the right subtree when deleting a node with two children
void AVLTree::Delete (int32_t val)
{
  remove(val, root);
}

//Implement Access
bool AVLTree::Access (int32_t val)
{
  return Access(val, root);
}

//Implement Printing
string AVLTree::PrintPreOrder () const//Ask for Help
{
  string output;
  output = preorderHelper(root);
  
  return output;
}

string AVLTree::PrintInOrder () const//Ask for Help
{
  string output = inOrderHelper(root);

  return output;
}

//Private Members
//Help destructor
void AVLTree::makeEmpty(AvlNode * & t)
{
  if(t != NULL)
    {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
  t = NULL;
}

//Return height of node
int AVLTree::height(AvlNode *t) const
{
  if(t == NULL)
    {
      return -1;
    }
  return t->height;
}

//Access Helper
bool AVLTree::Access(int32_t val, AvlNode * & t)
{
  if(t == NULL)
    {
      return false;
    }
  else if(val == t->elem)
    {
      return true;
    }
  else if(val < t->elem)
    {
      return Access(val, t->left);
    }
  else
    {
      return Access(val, t->right);
    }
}

//Insert Helper
void AVLTree::insert(int32_t val, AvlNode * & t)
{
  if(t == NULL)
    {
      t = new AvlNode(val, NULL, NULL);
    }
  else if(val < t->elem)
    {
      insert(val, t->left);
    }
  else if(val > t-> elem)
    {
      insert(val, t->right);
    }

  balance(t);
}

//Rebalance Tree
void AVLTree::balance( AvlNode * & t)
{
  if(t == NULL)
    {
      return;
    }

  if(height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
    {
      if(height(t->left->left) >= height(t->left->right))
	{
	  rotateWithLeftChild(t);
	}
      else
	{
	  doubleWithLeftChild(t);
	}
    }
  else if(height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
    {
      if(height(t->right->right) >= height(t->right->left))
	{
	  rotateWithRightChild(t);
	}
      else
	{
	  doubleWithRightChild(t);
	}
    }

  t->height = max(height(t->left), height(t->right)) + 1;
}

//Single rotation Left Child
void AVLTree::rotateWithLeftChild(AvlNode * & k2)
{
  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right)) + 1;
  k1->height = max(height(k1->left), k2->height) + 1;
  k2 = k1;
}

//Single rotation Right Child
void AVLTree::rotateWithRightChild(AvlNode * & k2)
{
  AvlNode *k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  k2->height = max(height(k2->right), height(k2->left)) + 1;
  k1->height = max(height(k1->right), k2->height) + 1;
  k2 = k1;
}

//Left-Right double rotation
void AVLTree::doubleWithLeftChild(AvlNode * & k3)
{
  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}

//Right-Left double rotation
void AVLTree::doubleWithRightChild(AvlNode * & k3)
{
  rotateWithLeftChild(k3->right);
  rotateWithRightChild(k3);
}

//Delete Helper function
// choose smallest node on the right subtree when deleting a node with two children
void AVLTree::remove(int32_t val, AvlNode * & t)
{
  if(t == NULL)
    {
      return;
    }

  if(val < t->elem)//Element to delete is in left child
    {
      remove(val, t->left);
    }
  else if(val > t->elem)//Element to delete is in right child
    {
      remove(val, t->right);
    }
  else if(t->left != NULL && t->right != NULL)//Two children, smallest node on right subtree
    {
      t->elem = findMin(t->right)->elem;
      remove(t->elem, t->right);
    }
  else
    {
      AvlNode *oldNode = t;
      if(t->left != NULL)
	{
	  t = t->left;
	}
      else
	{
	  t = t->right;
	}
      delete oldNode;
    }

  balance(t);
}

//Find Min Value helper
AvlNode* AVLTree::findMin(AvlNode *t) const
{
  if(t != NULL)
    {
      while(t->left != NULL)
	{
	  t = t->left;
	}
    }
  return t;
}

//Output Helpers
//Pre-Order
string AVLTree::preorderHelper(AvlNode * t) const//FIXIT?
{
  string o = "";
  if(t != NULL)
    {
      if(t != root)
	{
	  o += " ";
	}
      o += to_string(t->elem);
      if(t->left != NULL)
	{
	  o += preorderHelper(t->left);
	}
      if(t->right != NULL)
	{
	  o += preorderHelper(t->right);
	}
    }
  return o;
}

//In-Order
string AVLTree::inOrderHelper(AvlNode * t) const//FIXIT!
{
  string o = "";
  if(t != NULL)
    {
      o += inOrderHelper(t->left);
      if(t != findMin(root))
	{
	  o += " ";
	}
      o += to_string(t->elem);
      o += inOrderHelper(t->right);
    }
  return o;
}

AvlNode* AVLTree::getRoot()
{
  return root;
}

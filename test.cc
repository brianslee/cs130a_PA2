#include <iostream>
#include <time.h>
#include <set>
#include <stdlib.h>
#include "avl.h"
#include "bst.h"

using namespace std;
/*
 *@author Brian Lee
 *@version CMPSC 130A F16
 */

int main()
{
  AVLTree atree;
  BinarySearchTree bst;
  clock_t runtime = clock();

  int N;

  cout << "Number of tests: ";
  cin >> N;
  cout << endl;

  cout << "begin test series 1" << endl;

  runtime = clock();
  cout << "Initial runtime: " << (float)runtime/CLOCKS_PER_SEC << endl;

  //begin test series 1
  for(int32_t i = 1; i <= N; ++i)
    {
      atree.Insert(i);
    }

  runtime = clock();
  cout << "AVL Insert " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i <= N; ++i)
    {
      bst.Insert(i);
    }

  runtime = clock();
  cout << "BST Insert " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i<= N; ++i)
    {
      atree.Access(i);
    }

  runtime = clock();
  cout << "AVL Access " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i <= N; ++i)
    {
      bst.Access(i);
    }

  runtime = clock();
  cout << "BST Access " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i <= N; ++i)
    {
      atree.Delete(i);
    }

  runtime = clock();
  cout << "AVL Delete " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i <= N; ++i)
    {
      bst.Delete(i);
    }

  runtime = clock();
  cout << "BST Delete " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  //begin test series 2
  cout << "begin test series 2" << endl;
  runtime = clock();
  cout << "Test series 2 initial runtime: " << (float)runtime/CLOCKS_PER_SEC << endl;
  for(int32_t i = 1; i <= N; ++i)
    {
      atree.Insert(i);
    }

  runtime = clock();
  cout << "AVL Insert " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i <= N; ++i)
    {
      bst.Insert(i);
    }

  runtime = clock();
  cout << "BST Insert " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i<= N; ++i)
    {
      atree.Access(i);
    }

  runtime = clock();
  cout << "AVL Access " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = 1; i <= N; ++i)
    {
      bst.Access(i);
    }

  runtime = clock();
  cout << "BST Access " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = N; i >= 1; --i)
    {
      atree.Delete(i);
    }

  runtime = clock();
  cout << "AVL Reverse Delete " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int32_t i = N; i >= 1; --i)
    {
      bst.Delete(i);
    }

  runtime = clock();
  cout << "BST Reverse Delete " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  //begin test series 3
  cout << "Begin Test Series 3" << endl;
  srand(time(NULL));
  int randNum = rand() % (N + 1);
  set<int32_t> randSet;
  while (randSet.size() < N)
    {
      randSet.insert(randNum);
      randNum = rand() % (N + 1);
    }
  set<int32_t>::iterator randIt = randSet.begin();

  runtime = clock();
  cout << "Test Series 3 initial runtime: " << (float)runtime/CLOCKS_PER_SEC << endl;
  for(int i = 0; i < N; ++i)
    {
      atree.Insert(*randIt + i);
    }

  runtime = clock();
  cout << "AVL Random Insert " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int i = 0; i < N; ++i)
    {
      bst.Insert(*randIt + i);
    }

  runtime = clock();
  cout << "BST Random Insert " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int i = 0; i < N; ++i)
    {
      atree.Access(*randIt + i);
    }

  runtime = clock();
  cout << "AVL Random Access " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int i = 0; i < N; ++i)
    {
      bst.Access(*randIt + i);
    }

  runtime = clock();
  cout << "BST Random Access " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int i = 0; i < N; ++i)
    {
      atree.Delete(*randIt + i);
    }

  runtime = clock();
  cout << "AVL Random Delete " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;

  for(int i = 0; i < N; ++i)
    {
      bst.Delete(*randIt + i);
    }

  runtime = clock();
  cout << "BST Random Delete " << N << ": " << (float)runtime/CLOCKS_PER_SEC << endl;
  
  return 0;
}

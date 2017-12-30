#include <iostream>
#include <string>
using namespace std;
class node
{
public:
  node *left;
  int data;
  node *right;
};
node *newNode(int x)
{
  node *temp;
  temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
bool areIdentical(node *T1, node *T2)
{
  if(T1 == NULL && T2 == NULL)
    return true;
  if(T1 == NULL || T2 == NULL)
    return false;
  return (T1->data == T2->data && areIdentical(T1->left, T2->left) && areIdentical(T1->right, T2->right));
}
bool isSubtree(node *T, node *S)
{
  if(S == NULL)
    return true;
  if(T == NULL)
    return false;
  if(areIdentical(T, S))
    return true;
  return (isSubtree(T->left, S) || isSubtree(T->right, S));
}
int main()
{
  node *T;
  T = new node;
  T = newNode(26);
  T->right = newNode(3);
  T->right->right = newNode(3);
  T->left = newNode(10);
  T->left->left = newNode(4);
  T->left->left->right = newNode(30);
  T->left->right = newNode(6);

  node *S;
  S = new node;
  S = newNode(10);
  S->right = newNode(6);
  S->left = newNode(4);
  S->left->right = newNode(30);

  if (isSubtree(T, S))
    cout<<"Tree 2 is subtree of Tree 1"<<endl;
  else
    cout<<"Tree 2 is not a subtree of Tree 1"<<endl;
  return 0;
}

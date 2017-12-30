#include <iostream>
#include <climits>
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
bool isBST(node *root, int min, int max)
{
  if(root == NULL)
    return true;
  if(root->data < min || root->data > max)
    return false;
  return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}
int main()
{
  node *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  if(isBST(root, INT_MIN, INT_MAX))
    cout<<"is BST"<<endl;
  else
    cout<<"not a BST"<<endl;
  return 0;
}

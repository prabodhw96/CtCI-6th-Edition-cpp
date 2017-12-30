#include <iostream>
#include <cmath>
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
int getHeight(node *root)
{
  if(root == NULL)
    return -1;
  return max(getHeight(root->left), getHeight(root->right))+1;
}
bool isBalanced(node *root)
{
  if(root == NULL)
    return true;
  int heightDiff = getHeight(root->left) - getHeight(root->right);
  if(abs(heightDiff) > 1)
    return false;
  else
    return isBalanced(root->left) && isBalanced(root->right);
}
int main()
{
  int height = 0;
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
  if(isBalanced(root))
    cout<<"Tree is balanced"<<endl;
  else
    cout<<"Tree is not balanced"<<endl;
  return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
class node
{
public:
  node *left;
  int data;
  node *right;
};
node* newNode(int x)
{
  node *temp;
  temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
int height(node *root)
{
  if(root == NULL)
    return 0;
  else
  {
    int l_height = height(root->left);
    int r_height = height(root->right);
    return max(l_height, r_height)+1;
  }
}
void printGivenLevel(node *root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    cout<<root->data<<" ";
  else if(level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
void printLevelOrder(node *root)
{
  int h = height(root);
  for(int i=1; i<=h; i++)
  {
    cout<<"Level "<<i<<": ";
    printGivenLevel(root, i);
    cout<<endl;
  }
}
int main()
{
  node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  cout<<"Level order traversal of binary tree: "<<endl;
  printLevelOrder(root);
  return 0;
}

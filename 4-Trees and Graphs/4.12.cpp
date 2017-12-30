#include <iostream>
#include <vector>
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
int path_sum = 0;
void pathWithSumUtil(node *root, vector<int> &path, int sum)
{
  if(!root)
    return;
  path.push_back(root->data);
  pathWithSumUtil(root->left, path, sum);
  pathWithSumUtil(root->right, path, sum);
  int f = 0;
  for(int i=path.size()-1; i>=0; i--)
  {
    f += path[i];
    if(f == sum)
      path_sum++;
  }
  path.pop_back();
}
void pathWithSum(node *root, int sum)
{
  vector<int> path;
  pathWithSumUtil(root, path, sum);
}
int main()
{
  node *root;
  root = new node;
  root = newNode(1);
  root->left = newNode(3);
  root->left->left = newNode(2);
  root->left->right = newNode(1);
  root->left->right->left = newNode(1);
  root->right = newNode(-1);
  root->right->left = newNode(4);
  root->right->left->left = newNode(1);
  root->right->left->right = newNode(2);
  root->right->right = newNode(5);
  root->right->right->right = newNode(2);

  int sum = 5;
  pathWithSum(root, sum);
  cout<<"No. of paths with sum "<<sum<<" is "<<path_sum<<endl;
  return 0;
}

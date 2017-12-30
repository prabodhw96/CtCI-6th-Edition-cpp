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
node *newNode(int x)
{
  node *temp;
  temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
bool findPath(node *root, vector<int> &path, int k)
{
  if(root == NULL)
    return false;
  path.push_back(root->data);
  if(root->data == k)
    return true;
  if((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
    return true;
  path.pop_back();
  return false;
}
int findLCA(node *root, int n1, int n2)
{
  vector<int> path1, path2;
  int i;
  if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
    return -1;
  for(i=0; i<path1.size() && i<path2.size(); i++)
    if(path1[i] != path2[i])
      break;
  return path1[i-1];
}
int main()
{
  node *root;
  root = new node;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  cout<<"LCA(4, 5) = "<<findLCA(root, 4, 5)<<endl;
  cout<<"LCA(4, 6) = "<<findLCA(root, 4, 6)<<endl;
  cout<<"LCA(3, 4) = "<<findLCA(root, 3, 4)<<endl;
  cout<<"LCA(2, 4) = "<<findLCA(root, 2, 4)<<endl;
  return 0;
}

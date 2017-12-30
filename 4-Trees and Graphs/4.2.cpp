#include<iostream>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;
};
node *newNode(int x);
node *createMinBST(int arr[], int start, int end)
{
  if(start>end)
    return NULL;
  int mid = (start+end)/2;
  node *root = newNode(arr[mid]);
  root->left =  createMinBST(arr, start, mid-1);
  root->right = createMinBST(arr, mid+1, end);
  return root;
}
node *newNode(int x)
{
  node *temp;
  temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
void preorder(node *temp)
{
  if(temp == NULL)
    return;
  cout<<temp->data<<" ";
  preorder(temp->left);
  preorder(temp->right);
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  node *root = createMinBST(arr, 0, n-1);
  cout<<"Preorder traversal of constructed BST"<<endl;
  preorder(root);
  return 0;
}

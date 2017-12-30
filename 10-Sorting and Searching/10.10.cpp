#include <iostream>
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
node *insert(node *root, int x)
{
  if(root == NULL)
    return newNode(x);
  else
  {
    node *temp;
    temp = new node;
    if(x <= root->data)
    {
      temp = insert(root->left, x);
      root->left = temp;
    }
    else
    {
      temp = insert(root->right, x);
      root->right = temp;
    }
    return root;
  }
}
/*void preorder(node *temp)
{
  if(temp == NULL)
    return;
  cout<<temp->data<<" ";
  preorder(temp->left);
  preorder(temp->right);
}*/
node *search(node *root, int num)
{
  if(num < root->data)
  {
    if(root->left == NULL)
      return NULL;
    else search(root->left, num);
  }
  else if(num > root->data)
  {
    if(root->right == NULL)
      return NULL;
    else search(root->right, num);
  }
  else
    return root;
}
int size(node *root)
{
  if(root == NULL)
    return 0;
  else return size(root->left)+size(root->right)+1;
}
int RankOfNumber(node *root, int n)
{
  node *temp = new node;
  temp = search(root, n);
  if(temp->left == NULL)
    return 0;
  else return size(temp->left);
}
int main()
{
  node *root;
  root = new node;
  root = NULL;
  root = insert(root, 20);
  root = insert(root, 15);
  root = insert(root, 25);
  root = insert(root, 10);
  root = insert(root, 23);
  root = insert(root, 5);
  root = insert(root, 13);
  root = insert(root, 24);
  cout<<"Rank of "<<20<<": "<<RankOfNumber(root, 20)<<endl;
  cout<<"Rank of "<<15<<": "<<RankOfNumber(root, 15)<<endl;
  cout<<"Rank of "<<25<<": "<<RankOfNumber(root, 25)<<endl;
  cout<<"Rank of "<<10<<": "<<RankOfNumber(root, 10)<<endl;
  cout<<"Rank of "<<23<<": "<<RankOfNumber(root, 23)<<endl;
  cout<<"Rank of "<<5<<" : "<<RankOfNumber(root, 5)<<endl;
  cout<<"Rank of "<<13<<": "<<RankOfNumber(root, 13)<<endl;
  cout<<"Rank of "<<24<<": "<<RankOfNumber(root, 24)<<endl;
  return 0;
}

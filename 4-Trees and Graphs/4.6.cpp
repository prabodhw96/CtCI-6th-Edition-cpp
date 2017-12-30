#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;
  node *parent;
};
node *newNode(int x)
{
  node *temp;
  temp = new node;
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  temp->parent = NULL;
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
      temp->parent = root;
    }
    else
    {
      temp = insert(root->right, x);
      root->right = temp;
      temp->parent = root;
    }
    return root;
  }
}
node *mostLeft(node *root)
{
	while(root->left != NULL)
		root = root->left;
	return root;
}
node *findSuccessor(node *root)
{
	if(root->right != NULL)
		return mostLeft(root->right);
	node* child = root;
	node* ancestor = root->parent;
	while(ancestor != NULL && ancestor->right == child)
  {
		child = ancestor;
		ancestor = child->parent;
	}
	return ancestor;
}
int main()
{
  node *root, *temp, *succ;
  root = new node; root = NULL;
  temp = new node; temp = NULL;
  succ = new node; succ = NULL;
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);
  root = insert(root, 14);
  temp = root->left->right->right;
  succ = findSuccessor(temp);
  if(succ != NULL)
    cout<<"Inorder successor of "<<temp->data<<" is "<<succ->data<<endl;
  else
    cout<<"Inorder successor does not exist"<<endl;
  return 0;
}

#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *left;
  node *right;
};
void BST2DLL(node *root, node **head)
{
  if (root == NULL) return;
  static node* prev = NULL;
  BST2DLL(root->left, head);
  if (prev == NULL)
    *head = root;
  else
  {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  BST2DLL(root->right, head);
}
node* newNode(int data)
{
  node* new_node = new node;
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return (new_node);
}
void printList(node *temp)
{
  while (temp!=NULL)
  {
    cout << temp->data << " ";
    temp = temp->right;
  }
}int main()
{
  node *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  root->right->right = newNode(6);
  root->left->left->left = newNode(0);
  node *head = NULL;
  BST2DLL(root, &head);
  printList(head);
  return 0;
}

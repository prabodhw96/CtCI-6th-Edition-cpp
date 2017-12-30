#include <iostream>
using namespace std;
class node
{
public:
  node(char);
  char c;
  node *next;
};
node::node(char x)
{
  c = x;
  next = NULL;
}
void printList(node *head)
{
  while(head)
  {
    cout<<head->c<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}
void deleteNode(node *Node)
{
  if(Node == NULL || Node->next == NULL)
    return;
  node *nextNode = Node->next;
  Node->c = nextNode->c;
  Node->next = nextNode->next;
  delete(nextNode);
}
int main()
{
  node *head = new node('a');
  head->next = new node('b');
  head->next->next = new node('c');
  head->next->next->next = new node('d');
  cout<<"List before deletion"<<endl;
  printList(head);
  cout<<"Deleting node containing data as 'c'"<<endl;
  deleteNode(head->next->next);
  printList(head);
}

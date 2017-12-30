#include <iostream>
using namespace std;
class node
{
public:
  int num;
  node *next;
  node(int x)
  {
    num = x;
    next = NULL;
  }
};
void printList(node *head)
{
  while(head)
  {
    cout<<head->num<<"->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}
void findBeginning(node *head)
{
  node *slow = head;
  node *fast = head;
  while(fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
      break;
  }
  if(fast == NULL || fast->next == NULL)
    return;
  slow = head;
  while(slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }
  cout<<fast->num;
}
int main()
{
  node *head;
  head = new node(1);
  head->next = new node(2);
  head->next->next = new node(3);
  head->next->next->next = new node(4);
  head->next->next->next->next = new node(5);
  cout<<"Current List: "<<endl;
  printList(head);
  cout<<"Creating loop, connecting 5 to 2"<<endl;
  head->next->next->next->next->next = head->next;
  findBeginning(head);
  return 0;
}

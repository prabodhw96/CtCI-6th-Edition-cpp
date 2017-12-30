#include <iostream>
using namespace std;
class node
{
public:
  node(int);
  int num;
  node *next;
};
node::node(int x)
{
  num = x;
  next = NULL;
}
void printList(node *head)
{
  node *temp;
  temp = head;
  while(temp != NULL)
  {
    cout<<temp->num;
    temp = temp->next;
  }
}
node* SumLists(node *first, node *second, int carry)
{
  if(first == NULL && second == NULL && carry == 0)
    return NULL;
  int value = carry;
  if(first) value += first->num;
  if(second) value += second->num;
  node *res = new node(value%10);
  res->next = SumLists(first?first->next:NULL, second?second->next:NULL, value>9?1:0);
  return res;
}
int main()
{
  node *first;
  first = new node(7); first->next = new node(1); first->next->next = new node(6); //i.e. 617
  node *second;
  second = new node(5); second->next = new node(9); second->next->next = new node(2); //i.e. 295
  node *result = SumLists(first, second, 0);
  printList(result);  //i.e. 912
  return 0;
}

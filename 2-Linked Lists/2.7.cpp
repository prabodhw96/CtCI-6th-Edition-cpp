#include <iostream>
#include <cmath>
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
void printList(node* head)
{
  while(head)
  {
    cout<<head->num<<"-->";
    head = head->next;
  }
  cout<<"NULL"<<endl;
}
int listLen( node* head )
{
  int count = 0;
  while(head)
  {
    head = head->next;
    count++;
  }
  return count;
}
node* intersectionPoint(node* head1, node* head2)
{
  int len1 = listLen(head1);
  int len2 = listLen(head2);
  node* ptr1 = (len1 > len2) ? head1 : head2;
  node* ptr2 = (len1 > len2) ? head2 : head1;
  int i = 0;
  while (i<abs(len1-len2) && ptr1)
  {
    ptr1 = ptr1->next;
    ++i;
  }
  while(ptr1 && ptr2)
  {
    if(ptr1 == ptr2)
      return ptr1;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return NULL;
}
int main()
{
  node *list1 = new node(3);
  list1->next = new node(6);
  list1->next->next = new node(9);
  list1->next->next->next = new node(12);
  list1->next->next->next->next = new node(15);
  list1->next->next->next->next->next = new node(18);

  node *list2 = new node(7);
  list2->next = new node(10);
  list2->next->next = list1->next->next->next;

  printList(list1);
  printList(list2);

  node *intersectingNode = intersectionPoint(list1 , list2);
  if(intersectingNode)
    cout<<"Intersecting Node of lists is :"<<intersectingNode->num<<endl;
  else
    cout<<"Lists do not intersect"<<endl;
  return 0;
}

#include <iostream>
using namespace std;
class node
{
public:
  int num;
  node *next;
};
node *temp, *temp1;
class LinkedList
{
  node *head;
public:
  LinkedList();
  void AddValues();
  void RemoveDups();
  void Display();
  void KthToLast(int n);
  void Partition(int x);
};
LinkedList::LinkedList()
{
  head = NULL;
}
void LinkedList::AddValues()
{
  if(head == NULL)
  {
    temp = new node;
    cout<<"Enter value: ";
    cin>>temp->num;
    temp->next = NULL;
    head = temp;
  }
  else
  {
    temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    temp1 = new node;
    cout<<"Enter value: ";
    cin>>temp1->num;
    temp1->next = NULL;
    temp->next = temp1;
  }
}
void LinkedList::Display()
{
  temp = head;
  while(temp != NULL)
  {
    cout<<temp->num<<" ";
    temp = temp->next;
  }
}
void LinkedList::RemoveDups()
{
  node *current = head;
  while(current != NULL)
  {
    node *runner = current;
    while(runner->next != NULL)
    {
      if(runner->next->num == current->num)
        runner->next = runner->next->next;
      else
        runner = runner->next;
    }
    current = current->next;
  }
}
void LinkedList::KthToLast(int n)
{
  node *main_ptr = head;
  node *ref_ptr = head;
  int count = 0;
  if(head != NULL)
  {
    while(count < n)
    {
      if(ref_ptr == NULL)
      {
        cout<<n<<" is greater than no. of nodes in the list"<<endl;
        return;
      }
      ref_ptr = ref_ptr->next;
      count++;
    }
    while(ref_ptr != NULL)
    {
      main_ptr = main_ptr->next;
      ref_ptr = ref_ptr->next;
    }
    cout<<"Node no. "<<n<<" from last is "<<main_ptr->num<<endl;
  }
}
void LinkedList::Partition(int x)
{
  node *beforeStart = NULL;
  node *beforeEnd = NULL;
  node *afterStart = NULL;
  node *afterEnd = NULL;
  temp = head;
  while(temp != NULL)
  {
    node *next1 = temp->next;
    temp->next = NULL;
    if(temp->num < x)
    {
      if(beforeStart == NULL)
      {
        beforeStart = temp;
        beforeEnd = beforeStart;
      }
      else
      {
        beforeEnd->next = temp;
        beforeEnd = temp;
      }
    }
    else
    {
      if(afterStart == NULL)
      {
        afterStart = temp;
        afterEnd = afterStart;
      }
      else
      {
        afterEnd->next = temp;
        afterEnd = temp;
      }
    }
    temp = next1;
  }
  if(beforeStart == NULL)
    head = afterStart;
  beforeEnd->next = afterStart;
  head = beforeStart;
}
int main()
{
  LinkedList LL;
  for(int i=0; i<5; i++)
    LL.AddValues();
  LL.Display();
  cout<<endl;
  LL.RemoveDups();
  LL.Display();
  cout<<endl;
  int n;
  cout<<"Enter position from last node: ";
  cin>>n;
  LL.KthToLast(n);
  cout<<"Enter a no. to partition around: ";
  int x;
  cin>>x;
  LL.Partition(x);
  LL.Display();
  return 0;
}

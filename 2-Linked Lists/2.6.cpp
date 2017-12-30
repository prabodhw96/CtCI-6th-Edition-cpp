#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
  char c;
  node *next;
};
node *temp, *temp1;
class LinkedList
{
public:
  node *head;
  LinkedList();
  void push(char);
  void printList();
  bool isPalindrome();
};
LinkedList::LinkedList()
{
  head = NULL;
}
void LinkedList::push(char x)
{
  if(head == NULL)
  {
    temp = new node;
    temp->c = x;
    temp->next = NULL;
    head = temp;
  }
  else
  {
    temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    temp1 = new node;
    temp1->c = x;
    temp1->next = NULL;
    temp->next = temp1;
  }
}
void LinkedList::printList()
{
  temp = head;
  while(temp != NULL)
  {
    cout<<temp->c;
    temp = temp->next;
  }
}
bool LinkedList::isPalindrome()
{
  stack<char> st;
  temp = head;
  while(temp != NULL)
  {
    st.push(temp->c);
    temp = temp->next;
  }
  LinkedList LL;
  while(!st.empty())
  {
    char x = st.top();
    LL.push(x);
    st.pop();
  }
  temp1 = LL.head;
  while(temp1 != NULL)
  {
    if(temp1->c != head->c)
      return false;
    temp1 = temp1->next;
    head = head->next;
  }
  return true;
}
int main()
{
  LinkedList LL1, LL2;
  LL1.push('r');
  LL1.push('a');
  LL1.push('d');
  LL1.push('a');
  LL1.push('r');
  if(LL1.isPalindrome()) cout<<"List 1 is a Palindrome"<<endl;
  else cout<<"List 1 is not a Palindrome"<<endl;
  LL2.push('a');
  LL2.push('b');
  LL2.push('c');
  LL2.push('d');
  LL2.push('e');
  if(LL2.isPalindrome()) cout<<"List 2 is a Palindrome"<<endl;
  else cout<<"List 2 is not a Palindrome"<<endl;
  return 0;
}

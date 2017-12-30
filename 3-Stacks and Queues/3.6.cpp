#include <iostream>
using namespace std;
class node
{
public:
  string animal;
  node *next;
};
node *temp, *temp1;
class AnimalShelter
{
  node *head;
public:
  AnimalShelter()
  {
    head = NULL;
  }
  void display()
  {
    temp = head;
    while(temp)
    {
      cout<<temp->animal<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
  void enqueue(string Animal)
  {
    if(head == NULL)
    {
      temp = new node;
      temp->animal = Animal;
      temp->next = NULL;
      head = temp;
    }
    else
    {
      temp = head;
      while(temp->next != NULL)
        temp = temp->next;
      temp1 = new node;
      temp1->animal = Animal;
      temp1->next = NULL;
      temp->next = temp1;
    }
  }
  void dequeueAny()
  {
    head = head->next;
  }
  void dequeueDog()
  {
    temp = head;
    while(temp->next->animal[0] != 'D')
      temp = temp->next;
    temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
  }
  void dequeueCat()
  {
    temp = head;
    while(temp->next->animal[0] != 'C')
      temp = temp->next;
    temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
  }
};
int main()
{
  AnimalShelter AS;
  AS.enqueue("Dog 1");
  AS.enqueue("Dog 2");
  AS.enqueue("Cat 1");
  AS.enqueue("Cat 2");
  AS.enqueue("Dog 3");
  AS.enqueue("Cat 3");
  AS.display();
  AS.dequeueAny();
  AS.display();
  AS.dequeueCat();
  AS.display();
  AS.dequeueDog();
  AS.display();
  return 0;
}

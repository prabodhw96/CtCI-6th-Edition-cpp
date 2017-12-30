#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<stack<int>*> vec;
int index = 0;
void init_stacks()
{
  stack<int> *s = new stack<int>;
  vec.push_back(s);
}
void deinit_stacks()
{
  stack<int> *s;
  for(int i=0; i<=index; i++)
  {
    s = vec.at(i);
    delete s;
  }
}
void stack_push(int v)
{
  stack<int> *s = vec.at(index);
  if(s->size() == 5)
  {
    s = new stack<int>;
    vec.push_back(s);
    index++;
  }
  s->push(v);
}
void stack_pop()
{
  stack<int> *s = vec.at(index);
  if(index > 0)
  {
    if(s->size() == 0)
    {
      delete s;
      index--;
      s = vec.at(index);
    }
    s->pop();
  }
  else
  {
    if(s->size() == 0)
    {}
    else
      s->pop();
  }
}
bool stack_top(int &v)
{
  stack<int> *s = vec.at(index);
  if(s->size() == 0 && index == 0)
    return false;
  if(s->size() == 0)
  {
    delete s;
    index--;
    s = vec.at(index);
  }
  v = s->top();
  return true;
}
int main()
{
  init_stacks();
  for(int i=0; i<30; i++)
  {
    stack_push(i);
    cout<<"Pushed "<<i<<" into stack at index "<<index<<endl;
  }
  for(int i=0; i<40; i++)
  {
    int v;
    int b = stack_top(v);
    stack_pop();
    if(b)
      cout<<"Stack index "<<index<<": "<<v<<endl;
    else
      cout<<"Stack is empty"<<endl;
  }
  for(int i=0; i<10; i++)
  {
    stack_push(i);
    cout<<"Pushed "<<i<<" into stack at index "<<index<<endl;
  }
  for(int i=0; i<15; i++)
  {
    int v;
    int b = stack_top(v);
    stack_pop();
    if(b)
      cout<<"Stack index "<<index<<": "<<v<<endl;
    else
      cout<<"Stack is empty"<<endl;
  }
  deinit_stacks();
  return 0;
}

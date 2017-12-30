#include <iostream>
#include <stack>
using namespace std;
class MyQueue
{
  stack<int> stack1, stack_temp;
public:
  void push1(int x)
  {
    stack1.push(x);
  }
  void pop1()
  {
    while(!stack1.empty())
    {
      stack_temp.push(stack1.top());
      stack1.pop();
    }
    stack_temp.pop();
    while(!stack_temp.empty())
    {
      stack1.push(stack_temp.top());
      stack_temp.pop();
    }
  }
  int top1()
  {
    while(!stack1.empty())
    {
      stack_temp.push(stack1.top());
      stack1.pop();
    }
    int t = stack_temp.top();
    while(!stack_temp.empty())
    {
      stack1.push(stack_temp.top());
      stack_temp.pop();
    }
    return t;
  }
  void display()
  {
    while(!stack1.empty())
    {
      stack_temp.push(stack1.top());
      stack1.pop();
    }
    while(!stack_temp.empty())
    {
      cout<<stack_temp.top()<<" ";
      stack1.push(stack_temp.top());
      stack_temp.pop();
    }
    cout<<endl;
  }
};
int main()
{
  MyQueue Q;
  Q.push1(1); Q.push1(2); Q.push1(3); Q.push1(4); Q.push1(5);
  Q.display();
  Q.top1();
  Q.pop1();
  Q.display();
  Q.push1(6);
  Q.display();
  return 0;
}

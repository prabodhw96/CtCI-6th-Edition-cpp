#include <iostream>
#include <stack>
using namespace std;
class StackWithMin
{
  stack<int> st;
  int minval;
public:
  void push1(int);
  void pop1();
  int top1();
  int getMin();
};
void StackWithMin::push1(int x)
{
  if(st.empty())
    minval = 10000000;
  st.push(x);
  if(x < minval)
    minval = x;
}
void StackWithMin::pop1()
{
  st.pop();
}
int StackWithMin::top1()
{
  return st.top();
}
int StackWithMin::getMin()
{
  return minval;
}
int main()
{
  StackWithMin st_m;
  for(int i=0; i<5; i++)
  {
    int t;
    cout<<"Enter value: ";
    cin>>t;
    st_m.push1(t);
  }
  cout<<"Minimum value in stack is "<<st_m.getMin()<<endl;
  return 0;
}

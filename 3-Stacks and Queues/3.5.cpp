#include <iostream>
#include <stack>
using namespace std;
void display(stack<int> st)
{
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}
stack<int> sortStack(stack<int> st)
{
  stack<int> tmpStack;
  while(!st.empty())
  {
    int tmp = st.top();
    st.pop();
    while(!tmpStack.empty() && tmp>tmpStack.top())
    {
      st.push(tmpStack.top());
      tmpStack.pop();
    }
    tmpStack.push(tmp);
  }
  return tmpStack;
}
int main()
{
  stack<int> st;
  st.push(2); st.push(1); st.push(3); st.push(6); st.push(4); st.push(5); st.push(8); st.push(7); st.push(10); st.push(9);
  display(st);
  st = sortStack(st);
  display(st);
  return 0;
}

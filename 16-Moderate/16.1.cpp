
#include <iostream>
using namespace std;
int main()
{
  int a = 9, b = 4;
  cout<<"Before swapping: "<<endl;
  cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
  a = a - b;
  b = a + b;
  a = b - a;
  cout<<"After swapping: "<<endl;
  cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
  return 0;
}

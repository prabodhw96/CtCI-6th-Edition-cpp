#include <iostream>
using namespace std;
int min(int x, int y)
{
  return y^((x^y)&-(x<y));
}
int max(int x, int y)
{
  return x^((x^y)&-(x<y));
}
int main()
{
  int x = 15;
  int y = 6;
  cout<<"Minimum of "<<x<<" and "<<y<<" is "<<min(x,y)<<endl;
  cout<<"Maximum of "<<x<<" and "<<y<<" is "<<max(x,y)<<endl;
  return 0;
}

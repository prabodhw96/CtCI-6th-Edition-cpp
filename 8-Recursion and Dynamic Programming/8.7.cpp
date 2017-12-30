#include <iostream>
#include <cstring>
using namespace std;
void swap(char *x, char *y)
{
  char t;
  t = *x;
  *x = *y;
  *y = t;
}
void permute(char* a, int l, int r)
{
  if(l==r)
    cout<<a<<endl;
  else
  {
    for(int i=l; i<=r; i++)
    {
      swap((a+l), (a+i));
      permute(a, l+1, r);
      swap((a+l), (a+i));
    }
  }
}
int main()
{
  char str[] = "ABC";
  permute(str, 0, strlen(str)-1);
  return 0;
}

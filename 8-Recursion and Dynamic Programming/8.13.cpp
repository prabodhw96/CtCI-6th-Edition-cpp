#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Box
{
public:
  int h, w, d;
};
int compare(const void *a, const void * b)
{
  return((*(Box *)b).d*(*(Box *)b).w ) - ((*(Box *)a).d*(*(Box *)a).w);
}
int maxStackHeight( Box arr[], int n )
{
  Box rot[3*n];
  int index = 0;
  for (int i=0; i<n; i++)
  {
    rot[index] = arr[i];
    index++;
    rot[index].h = arr[i].w;
    rot[index].d = max(arr[i].h, arr[i].d);
    rot[index].w = min(arr[i].h, arr[i].d);
    index++;
    rot[index].h = arr[i].d;
    rot[index].d = max(arr[i].h, arr[i].w);
    rot[index].w = min(arr[i].h, arr[i].w);
    index++;
  }
  n = 3*n;
  qsort(rot, n, sizeof(rot[0]), compare);
  int msh[n];
  for(int i=0; i<n; i++)
    msh[i] = rot[i].h;
    for(int i=1; i<n; i++)
      for(int j=0; j<i; j++)
        if(rot[i].w < rot[j].w && rot[i].d < rot[j].d && msh[i] < msh[j] + rot[i].h)
          msh[i] = msh[j] + rot[i].h;
  int mx = -1;
  for(int i=0; i<n; i++)
    if(mx < msh[i])
      mx = msh[i];
  return mx;
}
int main()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Maximum possible height of the stack is "<<maxStackHeight(arr, n)<<endl;
  return 0;
}

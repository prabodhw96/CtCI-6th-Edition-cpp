#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
  int arr[] = {1, 2, 0, 9, 3, 4, 7, 8, 6, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  int m = 6;
  int subset[m];
  for(int i=0; i<m; i++)
    subset[i] = arr[i];
  srand(time(NULL));
  for(int i=m; i<n; i++)
  {
    int k = rand()%(i+1);
    if(k < m)
      subset[k] = arr[i];
  }
  for(int i=0; i<m; i++)
    cout<<subset[i]<<" ";
  return 0;
}

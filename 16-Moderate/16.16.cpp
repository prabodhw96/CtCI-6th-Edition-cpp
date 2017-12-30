#include <iostream>
using namespace std;
void SubSort(int arr[], int n)
{
  int start, end;
  for(int i=0; i<n-1; i++)
  {
    if(arr[i]>arr[i+1])
    {
      start = i;
      break;
    }
  }
  if(start == n-1)
  {
      cout<<"Complete array is sorted"<<endl;
      return;
  }
  for(int i=n-1; i>=0; i--)
  {
    if(arr[i] < arr[i-1])
    {
      end = i;
      break;
    }
  }
  int min = arr[start], max = arr[start];
  for(int i=start; i<=end; i++)
  {
    if(arr[i] > max)
      max = arr[i];
    if(arr[i] < min)
      min = arr[i];
  }
  for(int i=0; i<start; i++)
  {
    if(arr[i] > min)
    {
      start = i;
      break;
    }
  }
  for(int i=n-1; i>end; i--)
  {
    if(arr[i] < max)
    {
      end = i;
      break;
    }
  }
  cout<<start<<" "<<end<<endl;
}
int main()
{
  int arr[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
  int n = sizeof(arr)/sizeof(arr[0]);
  SubSort(arr, n);
  return 0;
}

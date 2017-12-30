#include <iostream>
using namespace std;
int binarySearch(int arr[], int low, int high)
{
  if(high >= low)
  {
    int mid = (low+high)/2;
    if(mid == arr[mid])
      return mid;
    if(mid > arr[mid])
      return binarySearch(arr, mid+1, high);
    else
      return binarySearch(arr, low, mid-1);
    return -1;
  }
}
int main()
{
  int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Magic index is "<<binarySearch(arr, 0, n-1);
  return 0;
}

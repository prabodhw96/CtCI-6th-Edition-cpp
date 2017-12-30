#include <iostream>
using namespace std;
int search(int arr[], int low, int high, int key)
{
  if(low > high)
    return -1;
  int mid = (low + high)/2;
  if(arr[mid] == key)
    return mid;
  if(arr[low] <= arr[mid])
  {
    if(key >= arr[low] && key <= arr[mid])
      return search(arr, low, mid-1, key);
    return search(arr, mid+1, high, key);
  }
  if(key >= arr[mid] && key <= arr[high])
    return search(arr, mid+1, high, key);
  return search(arr, low, mid-1, key);
}
int main()
{
  int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int key = 6;
  int i = search(arr, 0, n-1, key);
  if(i != -1)
    cout<<"Index: "<<i<<endl;
  else
    cout<<"Key not found"<<endl;
  return 0;
}

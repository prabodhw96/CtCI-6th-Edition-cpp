#include <iostream>
using namespace std;
void findSubArray(char arr[], int n)
{
  int sum = 0, maxSize = -1, startIndex;
  for(int i=0; i<n-1; i++)
  {
    sum = (arr[i] == 'A') ? -1 : 1;
    for(int j=i+1; j<n; j++)
    {
      (arr[j] == 'A') ? sum += -1 : sum += 1;
      if(sum == 0 && maxSize < j-i+1)
      {
        maxSize = j-i+1;
        startIndex = i;
      }
    }
  }
  if(maxSize == -1)
    cout<<"No such sub-array"<<endl;
  else
    cout<<startIndex<<" "<<startIndex+maxSize-1<<endl;
}
int main()
{
  char arr[] = {'A', 'B', 'A', 'A', 'A', 'B', 'B', 'B', 'A', 'B', 'A', 'A', 'B', 'B', 'A', 'A', 'A', 'A', 'A', 'A'};
  int n = sizeof(arr)/sizeof(arr[0]);
  findSubArray(arr, n);
  return 0;
}

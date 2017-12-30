#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
#define ROW 4
#define COL 5
int Kadane(int *arr, int *up, int *down, int n)
{
  int sum=0, maxSum = INT_MIN, i;
  *down = -1;
  int local_up = 0;
  for(i=0; i<n; i++)
  {
    sum += arr[i];
    if(sum < 0)
    {
      sum = 0;
      local_up = i+1;
    }
    else if(sum > maxSum)
    {
      maxSum = sum;
      *up = local_up;
      *down = i;
    }
  }
  if(*down != -1)
    return maxSum;
  maxSum = arr[0];
  *up = *down = 0;
  // Special Case: When all nos. in the array are negative
  for(i=1; i<n; i++)
  {
    if(arr[i] > maxSum)
    {
      maxSum = arr[i];
      *up = *down = i;
    }
  }
  return maxSum;
}
void maxSubmatrix(int mat[][COL])
{
  int maxSum = INT_MIN, maxLeft, maxRight, maxUp, maxDown;
  int left, right, i;
  int temp[ROW], currentSum, up, down;
  for(left=0; left<COL; left++)
  {
    memset(temp, 0, sizeof(temp));
    for(right=left; right<COL; right++)
    {
      for(i=0; i<ROW; i++)
        temp[i] += mat[i][right];
      currentSum = Kadane(temp, &up, &down, ROW);
      if(currentSum > maxSum)
      {
        maxSum = currentSum;
        maxLeft = left;
        maxRight = right;
        maxUp = up;
        maxDown = down;
      }
    }
  }
  cout<<"(top, left) : ("<<maxUp<<", "<<maxLeft<<")"<<endl;
  cout<<"(bottom, right) : ("<<maxDown<<", "<<maxRight<<")"<<endl;
  cout<<"Max sum: "<<maxSum<<endl;
}
int main()
{
  int mat[ROW][COL] = {{2,  1,  -3, -4,  5},
                       {0,  6,   3,  4,  1},
                       {2, -2,  -1,  4, -5},
                       {-3, 3,   1,  0,  3}
                      };
  maxSubmatrix(mat);
  return 0;
}

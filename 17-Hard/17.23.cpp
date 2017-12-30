#include <iostream>
#include <algorithm>
using namespace std;
#define N 6
// Black->X and White->O
int maxSquareMatrix(int mat[][N])
{
  int mx = 1;
  int hor[N][N], ver[N][N];
  hor[0][0] = ver[0][0] = (mat[0][0] == 'X');
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      if(mat[i][j] == 'O')
        ver[i][j] = hor[i][j] = 0;
      else
      {
        hor[i][j] = (j == 0)? 1: hor[i][j-1]+1;
        ver[i][j] = (i == 0)? 1: ver[i-1][j]+1;
      }
    }
  }
  for(int i=N-1; i>=0; i--)
  {
    for(int j=N-1; j>=0; j--)
    {
      int small = min(hor[i][j], ver[i][j]);
      while(small > mx)
      {
        if(ver[i][j-small+1] >= small && hor[i-small+1][j] >= small)
          mx = small;
        small--;
      }
    }
  }
  return mx;
}
int main()
{
  int mat[][N] ={{'X', 'O', 'X', 'X', 'X', 'X'},
                 {'X', 'O', 'X', 'X', 'O', 'X'},
                 {'X', 'X', 'X', 'O', 'O', 'X'},
                 {'O', 'X', 'X', 'X', 'X', 'X'},
                 {'X', 'X', 'X', 'O', 'X', 'O'},
                 {'O', 'O', 'X', 'O', 'O', 'O'}
               };
  cout<<maxSquareMatrix(mat);
  return 0;
}

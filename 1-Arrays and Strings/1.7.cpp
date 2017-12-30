#include <iostream>
using namespace std;
#define R 3
#define C 4
void modifyMatrix(bool mat[R][C])
{
  bool row[R];
  bool col[C];
  int i, j;
  for(i=0; i<R; i++)
    row[i] = 1;
  for (i = 0; i < C; i++)
    col[i] = 1;
  for(i=0; i<R; i++)
  {
    for(j=0; j<C; j++)
    {
      if(mat[i][j] == 0)
      {
        row[i] = 0;
        col[j] = 0;
      }
    }
  }
  for(i=0; i<R; i++)
  {
    for(j=0; j<C; j++)
    {
      if(row[i]==0 || col[j]==0)
        mat[i][j] = 0;
    }
  }
}
void printMatrix(bool mat[R][C])
{
  int i, j;
  for(i=0; i<R; i++)
  {
    for(j=0; j<C; j++)
      cout<<mat[i][j];
    cout<<endl;
  }
}
int main()
{
  int mat[R][C] = {
    {0, 1, 1, 0},
    {1, 1, 0, 1},
    {1, 1, 1, 1},
  };
  cout<<"Input Matrix"<<endl;
  printMatrix(mat);
  modifyMatrix(mat);
  cout<<"Matrix after modification"<<endl;
  printMatrix(mat);
  return 0;
}

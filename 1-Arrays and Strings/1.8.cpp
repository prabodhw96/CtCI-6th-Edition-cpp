#include <iostream>
using namespace std;
#define N 4
void display(int matrix[N][N])
{
  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
      cout<<matrix[i][j]<<"\t";
    cout<<endl;
  }
}
void rotatematrix(int matrix[][N])
{
  for(int i=0; i<N/2; i++)
  {
    int first = i, last = N-1-first;
    for(int j=first; j<last; j++)
    {
      int offset = j - first;
      int top = matrix[first][j]; //save top
      matrix[first][j] = matrix[last-offset][first];  //left -> top
      matrix[last-offset][first] = matrix[last][last-offset]; //bottom -> left
      matrix[last][last-offset] = matrix[j][last];  //right -> bottom
      matrix[j][last] = top;  //top->right
    }
  }
}
int main()
{
  int matrix[N][N] =
  { {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  rotatematrix(matrix);
  display(matrix);
  return 0;
}

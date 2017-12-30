#include <iostream>
#include <vector>
using namespace std;
#define ROW 4
#define COL 4
int computeSize(int land[][COL], int row, int col)
{
  if(row<0 || col<0 || row>=ROW || col>=COL || land[row][col]!=0)
    return 0;
  int size = 1;
  land[row][col] = -1;
  for(int dr=-1; dr<=1; dr++)
    for(int dc=-1; dc<=1; dc++)
      size += computeSize(land, row+dr, col+dc);
  return size;
}
vector<int> computePondSizes(int land[][COL])
{
  vector<int> pondSizes;
  for(int i=0; i<ROW; i++)
  {
    for(int j=0; j<COL; j++)
    {
      if(land[i][j] == 0)
      {
        int size = computeSize(land, i, j);
        pondSizes.push_back(size);
      }
    }
  }
  return pondSizes;
}
int main()
{
  int land[][COL] = {{0, 2, 1, 0},
                     {0, 1, 0, 1},
                     {1, 1, 0, 1},
                     {0, 1, 0, 1}};
  vector<int> pondSize = computePondSizes(land);
  for(int i=0; i<pondSize.size(); i++)
    cout<<pondSize[i]<<" ";
  return 0;
}

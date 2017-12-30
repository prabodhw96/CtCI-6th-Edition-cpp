#include <iostream>
#include <vector>
using namespace std;
#define R 5
#define C 7
class Point
{
public:
  Point(int, int);
  int row, col;
};
Point::Point(int r, int c)
{
  row = r;
  col = c;
}
bool getPath(int mat[R][C], int currRow, int currColumn, vector<Point*> &path)
{
  if(currRow<0 || currColumn<0 || mat[currRow][currColumn] == -1)
    return false;
  bool atOrigin = (currRow==0 && currColumn==0);
  if(atOrigin || getPath(mat, currRow-1, currColumn, path) || getPath(mat, currRow, currColumn-1, path))
  {
    Point *currPos = new Point(currRow, currColumn);
    path.push_back(currPos);
    return true;
  }
  return false;
}
vector<Point*> getPath(int mat[R][C], int rows, int columns)
{
  vector<Point*> path;
  if(rows !=0 || mat != NULL)
    if(getPath(mat, rows-1, columns-1, path))
      return path;
  return path;
}
int main()
{
  int mat[R][C];
  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      mat[i][j] = 1;
  mat[1][3] = -1;
  mat[2][5] = -1;
  mat[3][2] = -1;
  mat[0][1] = -1;
  vector<Point*> path = getPath(mat, 5, 7);
  if(path.size() == 0)
    cout<<"Path does not exist"<<endl;
  else
  {
    for(int i=0; i<path.size(); i++)
      cout<<"["<<path[i]->row<<"]["<<path[i]->col<<"]"<<endl;
  }
  return 0;
}

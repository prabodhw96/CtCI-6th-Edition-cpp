#include <iostream>
#include <cmath>
using namespace std;
int win[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
bool XhasWon(char board[])
{
  for(int i=0; i<8; i++)
    if(board[win[i][0]] == 'X' && board[win[i][1]] == 'X' && board[win[i][2]] == 'X')
      return true;
  return false;
}
bool OhasWon(char board[])
{
  for(int i=0; i<8; i++)
    if(board[win[i][0]] == 'O' && board[win[i][1]] == 'O' && board[win[i][2]] == 'O')
      return true;
  return false;
}
bool isValid(char board[])
{
  int xCount = 0, oCount = 0;
  for(int i=0; i<9; i++)
  {
    if(board[i] == 'X')
      xCount++;
    else
      oCount++;
  }
  return (abs(xCount - oCount) == 1);
}
int main()
{
  char board[] = {'X', 'X', 'O',
                  'O', 'O', 'X',
                  'X', 'O', 'X'};
  if(isValid(board))
  {
    if(XhasWon(board))
      cout<<"X has won"<<endl;
    else if(OhasWon(board))
      cout<<"O has won"<<endl;
    else
      cout<<"It's a tie"<<endl;
  }
  else
    cout<<"Board is not valid"<<endl;
  return 0;
}

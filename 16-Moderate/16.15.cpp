#include <iostream>
#include <algorithm>
using namespace std;
void getHits(string solution, string guess)
{
  int hits = 0, pseudo_hits = 0;
  for(int i=0; i<solution.length(); i++)
  {
    if(solution[i] == guess[i])
    {
      hits++;
      solution[i] = 'X';
      guess[i] = 'X';
    }
  }
  for(int i=0; i<solution.length(); i++)
  {
    if(guess[i] != 'X')
    {
      for(int j=0; j<solution.length(); j++)
      {
        if(guess[i] == solution[j])
        {
          pseudo_hits++;
          guess[i] = 'X';
          solution[j] = 'X';
          break;
        }
      }
    }
  }
  cout<<"Hits = "<<hits<<", Pseudo-hits = "<<pseudo_hits<<endl;
}
int main()
{
  string solution = "RGBY";
  string guess = "GGRR";
  getHits(solution, guess);
  return 0;
}

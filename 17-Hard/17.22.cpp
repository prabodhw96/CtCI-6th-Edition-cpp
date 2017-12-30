#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
void generateLadder(string start, string target, vector<string> &Dict)
{
  queue<string> q;
  q.push(start);
  while(!q.empty())
  {
    string word = q.front();
    q.pop();
    cout<<word<<" -> ";
    for(int i=0; i<word.size(); i++)
    {
      char before = word[i];
      for(char c='a'; c<='z'; c++)
      {
        word[i] = c;
        if(word == target)
        {
          cout<<target;
          return;
        }
        if(find(Dict.begin(), Dict.end(), word) != Dict.end())
        {
          q.push(word);
          Dict.erase(remove(Dict.begin(), Dict.end(), word), Dict.end());
        }
      }
      word[i] = before;
    }
  }
}
int main()
{
  string start = "toon";
  string target = "plea";
  string arr[] = {"poon", "plee", "same", "poie", "plea", "plie", "poin"};
  vector<string> Dict(arr, arr + sizeof(arr)/sizeof(arr[0]));
  generateLadder(start, target, Dict);
  return 0;
}

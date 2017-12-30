#include <iostream>
#include <algorithm>
using namespace std;
string swap(string s, int i, int j)
{
  char t = s[i];
  s[i] = s[j];
  s[j] = t;
  return s;
}
void permute(string s, int start)
{
  int end = s.length();
  if(start == end)
  {
    cout<<s<<endl;
    return;
  }
  permute(s, start+1);
  for(int i=start+1; i<end; i++)
  {
    if(s[start] == s[i])
      continue;
    s = swap(s, start, i);
    permute(s, start+1);
  }
}
int main()
{
  string s = "AABB";
  sort(s.begin(), s.end());
  permute(s,0);
  return 0;
}

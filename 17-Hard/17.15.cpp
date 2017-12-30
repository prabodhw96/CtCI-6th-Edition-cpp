#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
void sort(vector<string> s)
{
  int n = s.size();
  for(int i=1; i<n; i++)
  {
    string temp = s[i];
    int j = i-1;
    while(j>=0 && temp.length() < s[j].length())
    {
      s[j+1] = s[j];
      j--;
    }
    s[j+1] = temp;
  }
}
bool containsKey(map<string, bool> mymap, string str)
{
  if(mymap.find(str) == mymap.end())
    return false;
  else
    return true;
}
bool buildWord(string str, bool isOriginalWord, map<string, bool> mymap)
{
  if(mymap.find(str)->first!="" && !isOriginalWord)
    return mymap[str];
  for(int i=1; i<str.length(); i++)
  {
    string left = str.substr(0, i);
    string right = str.substr(i);
    if(containsKey(mymap, left) && mymap.find(left)->second == true && buildWord(right, false, mymap))
      return true;
  }
  mymap.insert(pair<string, bool>(str, false));
  return false;
}
string longestWord(vector<string> s)
{
  map<string, bool> mymap;
  for(int i=0; i<s.size(); i++)
    mymap.insert(pair<string, bool>(s[i], true));
  sort(s);
  for(int i=0; i<s.size(); i++)
  {
    if(buildWord(s[i], true, mymap))
    {
      cout<<s[i]<<endl;
      return s[i];
    }
  }
  return "";
}
int main()
{

  return 0;
}

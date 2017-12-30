#include <iostream>
using namespace std;
string buildFromPattern(string pattern, string main, string alt)
{
  string sb = "";
  char first = pattern[0];
  for(int i=0; i<pattern.length(); i++)
  {
    if(pattern[i] == first)
      sb += main;
    else
      sb += alt;
  }
  return sb;
}
bool doesMatch(string pattern, string value)
{
  if(pattern.length() == 0)
    return (value.length() == 0);
  int size = value.length();
  for(int i=0; i<size; i++)
  {
    string main = value.substr(0, i);
    for(int j=i; j<=size; j++)
    {
      for(int k=j; k<=size; k++)
      {
        string alt = value.substr(j, k);
        string candidate = buildFromPattern(pattern, main, alt);
        if(candidate == value)
          return true;
      }
    }
  }
  return false;
}
int main()
{
  string value = "catcatgocatgo";
  string pattern = "aabab";
  if(doesMatch(pattern, value))
    cout<<"Pattern matches with value"<<endl;
  else
    cout<<"Pattern does not match with value"<<endl;
  return 0;
}

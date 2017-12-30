#include <iostream>
#include <cmath>
using namespace std;
bool oneEditAway(string first, string second)
{
  if(abs(first.length() - second.length()) > 1)
    return false;
  string s1 = first.length() < second.length() ? first : second;
  string s2 = first.length() < second.length() ? second : first;
  int index1=0, index2=0;
  bool foundDiff = false;
  while(index2 < s2.length() && index1 < s1.length())
  {
    if(s1[index1] != s2[index2])
    {
      if(foundDiff)
        return false;
      foundDiff = true;
      if(s1.length() == s2.length())
        index1++;
    }
    else
      index1++;
    index2++;
  }
  return true;
}
int main()
{
  string first, second;
  cin>>first>>second;
  if(oneEditAway(first, second)) cout<<"One Edit Away";
  return 0;
}

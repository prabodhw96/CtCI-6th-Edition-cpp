#include <iostream>
#include <algorithm>
using namespace std;
bool isUniqueChars(string str)
{
  sort(str.begin(), str.end());
  for(int i=1; i<str.length(); i++)
  {
    if(str[i-1] == str[i])
      return false;
  }
  return true;
}
int main()
{
  string str;
  cin>>str;
  if(isUniqueChars(str)) cout<<"Unique characters";
  else cout<<"Non-unique characters";
  return 0;
}

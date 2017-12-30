#include <iostream>
using namespace std;
string encode(string str)
{
  string s;
  for(int i=0; i<str.length(); i++)
  {
    int runLength = 1;
    while(str[i] == str[i+1])
    {
      runLength++;
      i++;
    }
    s += str[i];
    s += runLength + '0';
  }
  return s;
}
int main()
{
  string str;
  cin>>str;
  cout<<encode(str);
  return 0;
}

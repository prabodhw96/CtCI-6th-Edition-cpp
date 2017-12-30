#include <iostream>
#include <string>
using namespace std;
int main()
{
  string str;
  getline(cin, str);
  for(int i=0; i<str.length(); i++)
  {
    if(str[i] == ' ')
      cout<<"%20";
    else
      cout<<str[i];
  }
  return 0;
}

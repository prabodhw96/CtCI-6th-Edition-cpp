#include <iostream>
#include <string>
using namespace std;
bool isRotation(string s1, string s2)
{
  if(s1.length() == s2.length() && s1.length() > 0)
  {
    string s = s1 + s2;
    if(s.find(s2) != string::npos)
      return true;
  }
  return false;
}
int main()
{
  string s1, s2;
  cin>>s1>>s2;
  if(isRotation(s1, s2)) cout<<"Rotation";
  else cout<<"Not a rotation";
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string str)
{
  vector<string> array;
  int pos=0, found;
  while(found = str.find_first_of(' ', pos) != string::npos)
  {
    array.push_back(str.substr(pos, found - pos));
    pos = found + 1;
  }
  array.push_back(str.substr(pos));
  return array;
}
int main()
{
  string str = "No wonder the sun never set on the British Empire, even God couldn't trust the English in the dark.";
  vector<string> s = split(str);
  for(int i=0; i<s.size(); i++)
    cout<<s[i]<<" ";
  return 0;
}

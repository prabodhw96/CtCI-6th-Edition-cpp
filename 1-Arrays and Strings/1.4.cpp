#include <iostream>
using namespace std;
#define COUNT_OF_CHARS 256
bool PermutationOfPalindrome(string s1, string s2)
{
  string s = s1 + s2;
  int count[COUNT_OF_CHARS] = {0};
  for(int i=0; s[i]; i++)
    count[s[i]]++;
  int odd = 0;
  for(int i=0; i<COUNT_OF_CHARS; i++)
  {
    if(count[i] & 1)
      odd++;
    if(odd > 1)
      return false;
  }
  return true;
}
int main()
{
  string s1, s2;
  cin>>s1>>s2;
  (PermutationOfPalindrome(s1,s2))?cout<<"Yes":cout<<"No";
  return 0;
}

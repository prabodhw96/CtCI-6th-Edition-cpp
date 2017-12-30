#include <iostream>
#include <algorithm>
using namespace std;
bool permutation(string str1, string str2)
{
  bool isPermutation = false;
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  if(str1 == str2)
    isPermutation = true;
  return isPermutation;
}
int main()
{
  string str1, str2;
  cin>>str1>>str2;
  if(permutation(str1, str2)) cout<<"Permutation";
  else cout<<"Not a permutation";
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> smallestK(vector<int> a, int k)
{
  sort(a.begin(), a.end());
  vector<int> smallest;
  for(int i=0; i<k; i++)
    smallest.push_back(a[i]);
  return smallest;
}
int main()
{
  vector<int> a;
  a.push_back(9); a.push_back(5); a.push_back(2); a.push_back(1); a.push_back(4);
  a.push_back(3); a.push_back(7); a.push_back(6); a.push_back(0); a.push_back(8);
  int k = 4;
  vector<int> smallest = smallestK(a, k);
  for(int i=0; i<k; i++)
    cout<<smallest[i]<<" ";
  return 0;
}

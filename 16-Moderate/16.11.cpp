#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> allLengths(int k, int shorter, int longer)
{
  vector<int> lengths;
  for(int nShorter=0; nShorter<=k; nShorter++)
  {
    int nLonger = k - nShorter;
    int length = nShorter*shorter + nLonger*longer;
    lengths.push_back(length);
  }
  return lengths;
}
int main()
{
  int shorter = 7, longer = 15, k = 5;
  vector<int> lengths = allLengths(5, 7, 15);
  sort(lengths.begin(), lengths.end());
  for(int i=0; i<lengths.size(); i++)
    cout<<lengths[i]<<" ";
  return 0;
}

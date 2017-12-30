#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int _lis(vector<pair<int, int> > vec, int n, int *max_ref)
{
  if(n == 1)
    return 1;
  int res, max_ending_here=1;
  for(int i=1; i<n; i++)
  {
    res = _lis(vec, i, max_ref);
    if(vec[i-1].second < vec[n-1].second && res + 1 > max_ending_here)
      max_ending_here = res + 1;
  }
  if(*max_ref < max_ending_here)
    *max_ref = max_ending_here;
  return max_ending_here;
}
int lis(vector<pair<int, int> > vec)
{
  int max = 1;
  _lis(vec, vec.size(), &max);
  return max;
}
int main()
{
  vector<pair<int, int> > vec;
  vec.push_back(make_pair(190, 75));
  vec.push_back(make_pair(90, 56));
  vec.push_back(make_pair(110, 68));
  vec.push_back(make_pair(95, 60));
  vec.push_back(make_pair(95, 68));
  vec.push_back(make_pair(150, 70));
  vec.push_back(make_pair(110, 68));
  sort(vec.begin(), vec.end());
  cout<<lis(vec);
  return 0;
}

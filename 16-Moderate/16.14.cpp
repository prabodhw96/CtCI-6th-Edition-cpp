#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int BestLine(vector< pair<int, int> > points)
{
  int n = points.size();
  if(n < 2)
    return n;
  int maxPoints = 0;
  int currMax, overlapPts, verticalPts;
  map<pair<int, int>, int> slope;
  for(int i=0; i<n; i++)
  {
    currMax = overlapPts = verticalPts = 0;
    for (int j=i+1; j<n; j++)
    {
      if(points[i] == points[j])
        overlapPts++;
      else if(points[i].first == points[j].first)
        verticalPts++;
      else
      {
        int y_diff = points[j].second - points[i].second;
        int x_diff = points[j].first - points[i].first;
        int g = __gcd(x_diff, y_diff);
        y_diff /= g;
        x_diff /= g;
        slope[make_pair(y_diff, x_diff)]++;
        currMax = max(currMax, slope[make_pair(y_diff, x_diff)]);
      }
      currMax = max(currMax, verticalPts);
    }
    maxPoints = max(maxPoints, currMax + overlapPts + 1);
    slope.clear();
  }
  return maxPoints;
}
int main()
{
  const int n = 6;
  int arr[n][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}};
  vector< pair<int, int> > points;
  for(int i=0; i<n; i++)
    points.push_back(make_pair(arr[i][0], arr[i][1]));
  cout<<BestLine(points)<<endl;
  return 0;
}

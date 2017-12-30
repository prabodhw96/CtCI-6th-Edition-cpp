#include <iostream>
#include <vector>
using namespace std;
class Listy
{
  vector<int> array;
public:
  Listy(vector<int> a)
  {
    array = a;
  }
  int elementAt(int index)
  {
    if(index >= array.size())
      return -1;
    return array[index];
  }
};
int binarysearch(Listy list, int value, int low, int high)
{
  int mid;
  while(low <= high)
  {
    mid = (low+high)/2;
    int middle = list.elementAt(mid);
    if(middle > value || middle == -1)
      high = mid - 1;
    else if(middle < value)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
int main()
{
  vector<int> vec;
  vec.push_back(1); vec.push_back(2); vec.push_back(4); vec.push_back(5);
  vec.push_back(6); vec.push_back(7); vec.push_back(9); vec.push_back(10);
  vec.push_back(11); vec.push_back(12); vec.push_back(13); vec.push_back(14);
  vec.push_back(16); vec.push_back(18);
  Listy list(vec);
  cout<<binarysearch(list, 4, 0, 14);
  return 0;
}

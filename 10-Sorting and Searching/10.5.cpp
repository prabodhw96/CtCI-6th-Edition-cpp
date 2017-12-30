#include <iostream>
using namespace std;
bool isEmpty(string s)
{
  return (s=="");
}
int search(string strings[], string str, int first, int last)
{
  if(first > last)
    return -1;
  int mid = (last + first) / 2;
  if(isEmpty(strings[mid]))
  {
    int left = mid - 1;
		int right = mid + 1;
		while(true)
    {
			if(left<first && right>last)
				return -1;
			else if(right<=last && !isEmpty(strings[right]))
      {
				mid = right;
				break;
			}
      else if(left>=first && !isEmpty(strings[left]))
      {
				mid = left;
				break;
			}
			right++;
			left--;
		}
	}
  if(str == strings[mid])
		return mid;
  else if (strings[mid] < str)
		return search(strings, str, mid + 1, last);
	else
	 return search(strings, str, first, mid - 1);
}
int main()
{
  string arr[] =  {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<search(arr, "dad", 0, n-1);
  return 0;
}

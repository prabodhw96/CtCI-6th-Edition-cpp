#include <iostream>
using namespace std;
int breakingPoint = 89;
int countDrops = 0;
bool willBreak(int floor)
{
	countDrops++;
	return floor >= breakingPoint;
}
int findBreakingPoint(int floors)
{
	int interval = 14;
	int previousFloor = 0;
	int egg1 = interval;
  while (!willBreak(egg1) && egg1 <= floors)
  {
	   interval -= 1;
		 previousFloor = egg1;
		 egg1 += interval;
	}
  int egg2 = previousFloor + 1;
	while(egg2 < egg1 && egg2 <= floors && !willBreak(egg2))
	  egg2 += 1;
  return egg2 > floors ? -1 : egg2;
}
int main()
{
  int max = 0;
	for(int i=1; i<=100; i++)
  {
		countDrops = 0;
		breakingPoint = i;
		int bp = findBreakingPoint(100);
		if(bp == breakingPoint)
    {
			cout<<"SUCCESS: "<<i<<" -> "<<bp<<" -> "<<countDrops<<endl;
		}
    else
    {
		  cout<<"ERROR: "<<i<<" -> "<<bp<<" vs "<<breakingPoint<<endl;
			break;
		}
		max = countDrops > max ? countDrops : max;
	}
	cout<<max<<endl;
  return 0;
}

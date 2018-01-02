#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
class Random
{
public:
  bool nextBoolean()
  {
    srand(time(NULL));
    return (0 == rand() % 2);
  }
};
vector<int> runOneFamily()
{
  Random *random = new Random();
	int boys = 0;
	int girls = 0;
	while (girls == 0)
	{
		if(random->nextBoolean())
			girls += 1;
		else
			boys += 1;
	}
	vector<int> genders;
  genders.push_back(girls); genders.push_back(boys);
	return genders;
}
double runNFamilies(int n)
{
	int boys = 0;
	int girls = 0;
	for(int i=0; i<n; i++)
	{
    vector<int> genders = runOneFamily();
		girls += genders[0];
		boys += genders[1];
	}
	return girls / (double)(boys + girls);
}
int main()
{
	double ratio = runNFamilies(10000000);
	cout<<ratio<<endl;
}

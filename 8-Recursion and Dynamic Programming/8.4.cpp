#include <iostream>
#include <cmath>
using namespace std;
void printPowerSet(char *set, int set_size)
{
  unsigned int pow_set_size = pow(2, set_size);
  for(int i=0; i<pow_set_size; i++)
  {
    for(int j=0; j<set_size; j++)
      if(i&(1<<j))
        cout<<set[j];
    cout<<endl;
  }
}
int main()
{
  char set[] = {'a', 'b', 'c'};
  printPowerSet(set, 3);
  return 0;
}

#include <iostream>
using namespace std;
class Person
{
public:
  int birth, death;
};
int maxAliveYear(Person people[], int n, int mn, int mx)
{
  int maxAlive = 0;
  int maxAliveYear = mn;
  for(int year=mn; year<=mx; year++)
  {
    int alive = 0;
    for(int i=0; i<n; i++)
      if(people[i].birth<=year && year<=people[i].death)
        alive++;
    if(alive > maxAlive)
    {
      maxAlive = alive;
      maxAliveYear = year;
    }
  }
  return maxAliveYear;
}
int main()
{
  int n, b, d, mn = 2010, mx = 1890;
  cout<<"Enter no. of people: ";
  cin>>n;
  Person people[n];
  for(int i=0; i<n; i++)
  {
    cout<<"Enter birth year of Person#"<<i<<": ";
    cin>>people[i].birth;
    cout<<"Enter death year of Person#"<<i<<": ";
    cin>>people[i].death;
    mn = min(mn, people[i].birth);
    mx = max(mx, people[i].death);
  }
  cout<<maxAliveYear(people, n, mn, mx)<<endl;
  return 0;
}

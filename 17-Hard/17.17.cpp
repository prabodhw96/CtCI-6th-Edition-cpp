#include <iostream>
#include <string>
using namespace std;
void searchAll(string T[], int n, string b)
{
  for(int i=0; i<n; i++)
  {
    int pos = b.find(T[i]);
    while(pos != string::npos)
    {
      cout<<T[i]<<" found at "<<pos<<endl;
      pos = b.find(T[i], pos+1);
    }
  }
}
int main()
{
  string T[] = {"is", "ppi", "sis", "i", "ssippi"};
  string b = "mississippi";
  int n = sizeof(T)/sizeof(T[0]);
  searchAll(T, n, b);
  return 0;
}

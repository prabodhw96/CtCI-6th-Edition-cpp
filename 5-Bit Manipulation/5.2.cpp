#include <iostream>
using namespace std;
string BinaryToString(double num)
{
  string binary;
  if(num>=1 || num<=0)
    return "ERROR";
  binary += "0.";
  while(num>0)
  {
    if(binary.length()>=32)
      return "ERROR";
    double r = num*2;
    if(r>=1)
    {
      binary += "1";
      num = r-1;
    }
    else
    {
      binary += "0";
      num = r;
    }
  }
  return binary;
}
int main()
{
  double num1 = 0.625;
  string output = BinaryToString(num1);
  cout<<"("<<output<<") in base 2"<<endl;
  double num2 = 0.72;
  output = BinaryToString(num2);
  cout<<"("<<output<<") in base 2"<<endl;
  return 0;
}

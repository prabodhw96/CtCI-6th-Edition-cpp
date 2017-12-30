#include <iostream>
#include <cmath>
using namespace std;
int flipSign(int a)
{
  int neg = 0;
  int newSign = a < 0 ? 1 : -1;
  while(a != 0)
  {
    neg += newSign;
    a += newSign;
  }
  return neg;
}
bool differentSign(int a, int b)
{
  return ((a<0 && b>0) || (a>0 && b<0));
}
int subtract(int a, int b)
{
  return a+flipSign(b);
}
int multiply(int a, int b)
{
  if(a<b)
    return multiply(b, a);
  int sum = 0;
  for(int i=abs(b); i>0; i--)
    sum += a;
  if(b < 0)
    sum = flipSign(sum);
  return sum;
}
int division(int a, int b)
{
  if(b == 0)
    throw(b);
  int quotient=0, dividend;
  int divisor = flipSign(abs(b));
  for(dividend=abs(a); dividend>=abs(divisor); dividend+=divisor)
    quotient++;
  if(differentSign(a, b))
    quotient = flipSign(quotient);
  return quotient;
}
int main()
{
  cout<<"Subtraction is "<<subtract(4, -2)<<endl;
  cout<<"Product is "<<multiply(-9, 6)<<endl;
  try
  {
    cout<<"Division is "<<division(8, 2)<<endl;
  }
  catch(int k)
  {
    cout<<"Exception: Divide by 0"<<endl;
  }
  return 0;
}

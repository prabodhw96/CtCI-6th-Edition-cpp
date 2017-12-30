#include <iostream>
#include <cctype>
using namespace std;
bool isOperand(char c)
{
  return isdigit(c);
}
int toInt(char c) {
  return (c - '0');
}
int evaluate(string exp)
{
  int result = toInt(exp[0]);
  for(int i=1; exp[i]; i+=2)
  {
    char opr = exp[i], opd = exp[i+1];
    if(!isOperand(opd))
      return -1;
    if (opr == '+')  result += toInt(opd);
    else if (opr == '-') result -= toInt(opd);
    else if (opr == '*') result *= toInt(opd);
    else if (opr == '/') result /= toInt(opd);
    else
      return -1;
  }
  return result;
}
int main()
{
    string str = "1+2*5+3";
    cout<<evaluate(str);
    return 0;
}

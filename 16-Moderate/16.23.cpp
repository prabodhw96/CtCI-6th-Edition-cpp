#include <iostream>
using namespace std;
int rand5()
{
    // some code here
}
int rand7()
{
    int i = 5*rand5() + rand5() - 5;
    if (i < 22)
        return i%7 + 1;
    return rand7();
}

int main()
{
    cout<<rand7()<<" "<<endl;
    return 0;
}

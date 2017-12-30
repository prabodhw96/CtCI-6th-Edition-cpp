#include <iostream>
using namespace std;
class Square
{
public:
  double ax, ay, bx, by, cx, cy, dx, dy;
  Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
  {
    ax = x1; ay = y1;
    bx = x2; by = y2;
    cx = x3; cy = y3;
    dx = x4; dy = y4;
  }
};
void findLine(Square S1, Square S2)
{
  double s1MidX, s1MidY, s2MidX, s2MidY;
  s1MidX = (S1.ax + S1.cx)/2;
  s1MidY = (S1.ay + S1.cy)/2;
  s2MidX = (S2.ax + S2.cx)/2;
  s2MidY = (S2.ay + S2.cy)/2;
  cout<<"Line from ("<<s1MidX<<", "<<s1MidY<<") to ("<<s2MidX<<", "<<s2MidY<<")"<<endl;
}
int main()
{
  Square S1(0,0,4,0,4,4,4,0), S2(4,4,8,4,8,8,4,8);
  findLine(S1,S2);
  return 0;
}

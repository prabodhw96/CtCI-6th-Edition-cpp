#include <iostream>
using namespace std;
int main()
{
  int noOfBottles = 20;
  //19 bottles have 1 gm pills but one has pill of weight 1.1 gms.
  double weight[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1.1, 1, 1, 1, 1, 1, 1, 1};
  double weightMix = 0;
  double totalWeight = (20*21)/2;
  for(int i=0; i<20; i++)
    weightMix += weight[i]*(i+1);
  int bottleNo = (weightMix - totalWeight)/0.1;
  cout<<"Bottle #"<<bottleNo<<" is the heavy bottle"<<endl;
  return 0;
}

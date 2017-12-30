#include <iostream>
#include <vector>
using namespace std;
double getVolume(vector<int> histogram)
{
  int i = 0;
  while(i < histogram.size()-1 && histogram[i] == 0)
    i++;
  int j = histogram.size() - 1;
  while(j > i && histogram[j] == 0)
    j--;
  double volume = 0.0;
  while(i != j)
  {
    if(histogram[i] < histogram [j])
    {
      double height = histogram[i];
      double barsVolume = 0.0;
      int start = i++;
      while(histogram[i] < height)
      {
        barsVolume += histogram[i];
        i++;
      }
      volume += (i - start - 1) * height - barsVolume;
    }
    else
    {
      double height = histogram[j];
      double barsVolume = 0.0;
      int end = j--;
      while(histogram[j] < height)
      {
        barsVolume += histogram[j];
        j--;
      }
      volume += (end - j - 1) * height - barsVolume;
    }
  }
  return volume;
}
int main()
{
  vector<int> histogram;
  histogram.push_back(0);
  histogram.push_back(0);
  histogram.push_back(4);
  histogram.push_back(0);
  histogram.push_back(0);
  histogram.push_back(6);
  histogram.push_back(0);
  histogram.push_back(0);
  histogram.push_back(3);
  histogram.push_back(0);
  histogram.push_back(8);
  histogram.push_back(0);
  histogram.push_back(2);
  histogram.push_back(0);
  histogram.push_back(5);
  histogram.push_back(2);
  histogram.push_back(0);
  histogram.push_back(3);
  histogram.push_back(0);
  histogram.push_back(0);
  cout<<"The volume of the histogram is: "<<getVolume(histogram)<<endl;
  return 0;
}

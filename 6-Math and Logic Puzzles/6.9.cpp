#include <iostream>
using namespace std;
int main()
{
  bool is_open[100] = {false};
  for(int pass=0; pass<100; ++pass)
		for(int door=pass; door<100; door+=pass+1)
			is_open[door] = !is_open[door];

	// output the result
	for (int door = 0; door < 100; ++door)
  {
    if(is_open[door])
		cout<<"door #"<<door+1<<" is open."<<endl;
	}
  //Optimized
	/*for(int i=1; i*i<=100; i++)
		cout<<"Door #"<<i*i<<" is open!"<<endl;*/
}

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	map<string,string> mymap;
	string wordArr[100] = {"cat", "dog", "tac", "god", "act"};
	string wordArr1[] = {"cat", "dog", "tac", "god", "act"};
	map<string,string>::iterator it;
	for(int i=0; i<5; i++)
	{
    sort(wordArr1[i].begin(), wordArr1[i].end());
    if(mymap[wordArr1[i]].compare("") == 0)
		  mymap[wordArr1[i]].append(wordArr[i]);
		else
		  mymap[wordArr1[i]].append(" "+wordArr[i]);
	}
	for(it=mymap.begin();it!=mymap.end();it++)
		cout<<it->second<<" ";
  return 0;
}

#include <iostream>
#include <climits>
using namespace std;
int getMinDistance(string words[], int n, string word1, string word2)
{
  int pos = 0, min = INT_MAX, word1_pos = -1, word2_pos = -1;
  for(int i=0; i<n; i++)
  {
    string current_word = words[i];
    if(current_word == word1)
    {
      word1_pos = pos;
      int distance = word1_pos - word2_pos;
      if(min > distance) min = distance;
    }
    else if(current_word == word2)
    {
      word2_pos = pos;
      int distance = word2_pos - word1_pos;
      if(min > distance) min = distance;
    }
    ++pos;
  }
  return min;
}
int main()
{
  string words[] = {"as", "was", "is", "the", "as", "the", "yahoo", "you", "me", "was", "the", "and"};
  int n = sizeof(words)/sizeof(words[0]);
  cout<<"The minimum distance between \"you\" and \"the\" is "<<getMinDistance(words, n, "you", "the")<<endl;
  return 0;
}

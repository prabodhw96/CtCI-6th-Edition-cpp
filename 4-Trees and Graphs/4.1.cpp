#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Graph
{
  int V;
  list<int> *adj;
public:
  Graph(int v)
  {
    V = v;
    adj = new list<int>[V];
  }
  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
  }
  bool isReachable(int s, int d)
  {
    if(s == d)
      return true;
    bool visited[V];
    for(int i=0; i<V; i++)
      visited[i] = false;
    queue<int> bfsq;
    visited[s] = true;
    bfsq.push(s);
    list<int>::iterator i;
    while(!bfsq.empty())
    {
      s = bfsq.front();
      for(i=adj[s].begin(); i!=adj[s].end(); i++)
      {
        if(*i == d)
          return true;
        if(!visited[*i])
        {
          visited[*i] = true;
          bfsq.push(*i);
        }
      }
      bfsq.pop();
    }
    return false;
  }
};
int main()
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  int u = 1, v = 3;
  if(g.isReachable(u, v))
    cout<<"There is a path from "<<u<<" to "<<v<<endl;
  else
    cout<<"There is no path from "<<u<<" to "<<v<<endl;
  u = 3, v = 1;
  if(g.isReachable(u, v))
    cout<<"There is a path from "<<u<<" to "<<v<<endl;
  else
    cout<<"There is no path from "<<u<<" to "<<v<<endl;
  return 0;
}

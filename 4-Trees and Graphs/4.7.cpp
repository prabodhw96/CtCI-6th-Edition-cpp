#include<iostream>
#include <list>
#include <stack>
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz";
class Graph
{
  int V;
  list<int> *adj;
  void BuildOrderUtil(int v, bool visited[], stack<int> &st);
public:
  Graph(int V);
  void addEdge(char v, char w);
  void BuildOrder();
};
Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}
void Graph::addEdge(char v, char w)
{
  int x = v - 97;
  int y = w - 97;
  adj[x].push_back(y);
}
void Graph::BuildOrderUtil(int v, bool visited[], stack<int> &st)
{
  visited[v] = true;
  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      BuildOrderUtil(*i, visited, st);
  st.push(v);
}
void Graph::BuildOrder()
{
  stack<int> st;
  bool visited[V];
  for(int i=0; i<V; i++)
    visited[i] = false;
  for(int i=0; i<V; i++)
    if(!visited[i])
      BuildOrderUtil(i, visited, st);
  while(!st.empty())
  {
    cout<<alpha[st.top()]<<" ";
    st.pop();
  }
}int main()
{
  Graph g(6);
  g.addEdge('a', 'd');
  g.addEdge('f', 'b');
  g.addEdge('b', 'd');
  g.addEdge('f', 'a');
  g.addEdge('d', 'c');
  g.BuildOrder();
  return 0;
}

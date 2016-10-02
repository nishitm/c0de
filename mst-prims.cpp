#include<bits/stdc++.h>

using namespace std;

void insertEdge(list<pair<int,int> >* &g, int u, int v, int wt)
{
  g[u].push_back({v,wt});
  g[v].push_back({u,wt});
  return;
}

struct comp
{
  bool operator()(pair<int,int>x, pair<int,int>y)
  {
    return (x.second > y.second);
  }
};

vector<int> prims(list<pair<int,int> >* g, int nodes)
{
  priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pq;
  vector<int> visited(nodes,false);
  vector<int> dist(nodes,INT_MAX);

  pq.push({0,0});
  dist[0]=0;

  while(!pq.empty())
  {
    pair<int,int> p = pq.top();
    visited[p.first]=true;
    pq.pop();
    for(auto a:g[p.first])
    {
      if(!visited[a.first] &&  a.second < dist[a.first])
      {
        pq.push({a.first,a.second});
        dist[a.first]= a.second;
      }
    }
  }
  return dist;
}

int main()
{
  int nodes;
  cout<<"Enter total nodes:";
  cin>>nodes;
  list<pair<int,int> > *g = new list<pair<int,int> >[nodes];

  insertEdge(g,0,1,5);
  insertEdge(g,0,3,7);
  insertEdge(g,0,2,6);
  insertEdge(g,2,4,8);
  insertEdge(g,3,4,9);

  for(auto a:prims(g,nodes))
    cout<<a<<endl;
  return 0;
}

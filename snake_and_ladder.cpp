// Problem::https://www.hackerrank.com/challenges/the-quickest-way-up

#include<bits/stdc++.h>
using namespace std;

void insertEdge(list<pair<int,int> >* &g, int u, int v,int wt)
{
    g[u].push_back({v,wt});
  return;
}

struct comp
{
  bool operator()(pair<int,int>x, pair<int,int>y)
  {
    return (x.second > y.second);
  }
};

int BFS(list<pair<int,int> >* g, int nodes)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >,  comp> pq;
    vector<int> dist(nodes,INT_MAX);
    vector<bool> visited(nodes,false);

    int src=1;
    dist[src]=0;
    pq.push({src,0});
    while(!pq.empty())
    {
        pair<int,int> vertex=pq.top();
        int u = vertex.first,wt=vertex.second;
        visited[u]=true;
        pq.pop();
        for(auto v:g[u])
        {
            if(!visited[v.first]  && dist[v.first] > wt+v.second)
            {
                dist[v.first] = wt+v.second;
                pq.push({v.first,dist[v.first]});
            }
        }
    }

    /*for(auto a:dist)
        cout<<a<<" ";
    cout<<endl;*/
    if(dist[100]!=INT_MAX)
        return dist[100];
    else
        return -1;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    cin>>t;

    while(t--)
    {
        int nodes=100;
        list<pair<int,int> > *g = new list<pair<int,int> >[nodes+1];

        for(int i=1;i<=99;i++)
            for(int j=i+1;j<=i+6 && j<=100;j++)
                insertEdge(g,i,j,1);

        int lad,snak;
        cin>>lad;

        for(int i=0;i<lad;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].clear();
            insertEdge(g,u,v,0);
        }
        cin>>snak;
        for(int i=0;i<snak;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].clear();
            insertEdge(g,u,v,0);
        }

        cout<<BFS(g,101)<<endl;

    }

    return 0;
}

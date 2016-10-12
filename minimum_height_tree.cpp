// Problem::For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree.
            // Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs).
            // Given such a graph, write a function to find all the MHTs and return a list of their root labels.
            //
            // Format
            // The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
            //
            // You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
            //
            // Example 1:
            //
            // Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
            //
            //         0
            //         |
            //         1
            //        / \
            //       2   3
            // return [1]
            //
            // Example 2:
            //
            // Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
            //
            //      0  1  2
            //       \ | /
            //         3
            //         |
            //         4
            //         |
            //         5
            // return [3, 4]

#include<bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

        vector<int> ans;

        if(n <= 0)
            return ans;
        else if(n == 1)
        {
            ans.push_back(0);
            return ans;
        }

        vector<unordered_set<int>> adj(n);

        for(auto edge : edges)
        {
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }

        for(int i = 0; i < adj.size(); ++i)
        {
            if(adj[i].size() == 1)
                ans.push_back(i);
        }

        while(true)
        {
            vector<int> next;

            for(int i : ans)
            {
                for(int neighbour : adj[i])
                {
                    adj[neighbour].erase(i);
                    if(adj[neighbour].size() == 1)
                        next.push_back(neighbour);
                }
            }
            if(next.empty())
                return ans;

            ans = next;
        }

}

int main()
{
    int n;
    cout<<"Enter no of nodes:";
    cin>>n;
    int m;
    cout<<"Enter the no of edges you want to enter:";
    cin>>m;

    cout<<"Enter the edges:\n";
    vector<pair<int,int> > edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cout<<"Enter first vertex:";
        cin>>a;
        cout<<"Enter second vertex:";
        cin>>b;
        edges[i]={a,b};
    }

    vector<int> ans= findMinHeightTrees(n,edges);

    cout<<"Minimum height tree possible with below nodes as a root:\n";
    for(auto a: ans)
        cout<<a<<endl;

    return 0;
}

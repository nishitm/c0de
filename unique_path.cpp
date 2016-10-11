// Problem::Now consider if some obstacles are added to the grids. How many unique paths would there be?
            //
            // An obstacle and empty space is marked as 1 and 0 respectively in the grid.
            //
            // For example,
            // There is one obstacle in the middle of a 3x3 grid as illustrated below.
            //
            // [
            //   [0,0,0],
            //   [0,1,0],
            //   [0,0,0]
            // ]
            // The total number of unique paths is 2.
            //
            // Note: m and n will be at most 100.

#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> f(n + 1, 0);
        f[1] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                f[j] = obstacleGrid[i][j - 1] == 1? 0 : (f[j] + f[j - 1]);
            }
        }

        return f[n];

}

int main()
{
        int n,m;
        cout<<"Enter no of rows:";
        cin>>n;
        cout<<"enter no of columns:";
        cin>>m;

        vector<vector<int> >grid;
        cout<<"enter elements row by row:\n";
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<m;j++)
            {

                int x;
                cin>>x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }
         cout<<"No of unique path from begining to end is:"<<uniquePathsWithObstacles(grid)<<endl;

         return 0;

}

#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> matrix, int n)
{
    int x[n][n];

    for(int i=0;i<n;i++)
      x[i][i]=0;

    for(int k=2; k<n;k++)
    {
      for(int i=1; i<n-k+1; i++)
      {
        int j = i+k-1;
        x[i][j] = INT_MAX;
        for (int l=i; l<=j-1; l++)
        {
            int q = x[i][l] + x[l+1][j] + matrix[i-1]*matrix[l]*matrix[j];
            if (q < x[i][j])
                x[i][j] = q;
        }
      }
    }
  return x[1][n-1];

}


int main()
{
  vector<int> matrix={3,4,2,5};

  cout<<"Minimum no of multiplication Required:"<<mcm(matrix,matrix.size())<<endl;

  return 0;
}

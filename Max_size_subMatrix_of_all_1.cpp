#include<bits/stdc++.h>
using namespace std;

int submatrixof1(vector< vector<int> > mat, int R, int C)
{
  int S[R][C];

  for(int i=0; i<R; i++)
     S[i][0] = mat[i][0];

  for(int j=0; j<C; j++)
     S[0][j] = mat[0][j];

  for(int i=1; i<R; i++)
  {
    for(int j=1; j<C; j++)
    {
      if(mat[i][j] == 1)
        S[i][j] = std::min({S[i][j-1], S[i-1][j], S[i-1][j-1]}) + 1;
      else
        S[i][j] = 0;
    }
  }

  int max=INT_MIN;
  for(int i=0; i<R; i++)
  {
    for(int j=0; j<C; j++)
    {
      if(S[i][j]>max)
        max=S[i][j];
    }
  }
  return max;


}

int main()
{
  vector<vector<int> > mat;

  int r,c;
  cout<<"Enter no of rows:";
  cin>>r;

  cout<<"Enter no of colums:";
  cin>>c;

  cout<<"Now enter the matrix data row by row:"<<endl;

  for(int i=0;i<r;i++)
  {
    vector<int> temp;
    for(int j=0;j<c;j++)
    {
      int x;
      cin>>x;
      temp.push_back(x);
    }
    mat.push_back(temp);
  }

  int size=submatrixof1(mat,r,c);

  cout<<"Maximum size of submatrix odf all 1 is:"<<size<<endl;

  return 0;
}

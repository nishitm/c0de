#include<bits/stdc++.h>
using namespace std;

int min_points(vector<vector<int> > mat)
{
  int r=mat.size();
  int c=mat[0].size();

  int table[r][c];

  if(mat[r-1][c-1]>0)
    table[r-1][c-1]=1;
  else
    table[r-1][c-1]=abs(mat[r-1][c-1]) + 1;

  for(int i=r-2; i>=0; i--)
    table[i][c-1]= max(table[i+1][c-1]-mat[i][c-1],1);

  for(int i=c-2; i>=0; i--)
    table[r-1][i]= max(table[r-1][i+1]-mat[r-1][i],1);

  for(int i=r-2; i>=0; i--)
  {
    for(int j=c-2; j>=0; j--)
    {
      int min_point = min(table[i+1][j],table[i][j+1]);
      table[i][j] = max(min_point - mat[i][j],1);
    }
  }

  return table[0][0];
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

  int points= min_points(mat);

  cout<<"Min points required is:"<<points<<endl;
  return 0;
}

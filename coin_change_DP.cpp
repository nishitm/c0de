#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> coin={1,2,5};

int coin_change_DP(int val)
{
  int x, y;
  int m=coin.size();
  int table[val+1][m];

  for (int i=0; i<m; i++)
      table[0][i] = 1;

  for (int i = 1; i < val+1; i++)
  {
      for (int j = 0; j < m; j++)
      {
          if(i-coin[j] >= 0)
            x=table[i-coin[j]][j];
          else
            x=0;
          if(j >= 1)
            y=table[i][j-1];
          else
            y=0;
          table[i][j] = x + y;
      }
  }
  return table[val][m-1];
}


int main()
{
  int val;
  cout<<"Enter value to get using coins(1,2,5):";
  cin>>val;

  std::sort(coin.begin(),coin.end());
  int ways= coin_change_DP(val);

  cout<<"#of ways:"<<ways<<endl;
  return 0;
}

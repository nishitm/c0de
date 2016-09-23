#include<bits/stdc++.h>
using namespace std;

int min_coin(vector<int> coin, int value)
{
  int table[value+1];

  table[0] = 0;

  for (int i=1; i<=value; i++)
      table[i] = INT_MAX;

  for (int i=1; i<=value; i++)
  {
      for (int j=0; j<coin.size(); j++)
        if (coin[j] <= i)
        {
            int sub = table[i-coin[j]];
            if (sub != INT_MAX && sub + 1 < table[i])
                table[i] = sub + 1;
        }
  }
  return table[value];

}


int main()
{
  vector<int> coin;
  int no_of_coin;
  cout<<"How many coins?-";
  cin>>no_of_coin;
  cout<<"Enter the values of coins:"<<endl;
  for(int i=0;i<no_of_coin;i++)
  {
    int x;
    cin>>x;
    coin.push_back(x);
  }

  int value;
  cout<<"Enter the total value:";
  cin>>value;

  int no=min_coin(coin,value);

  cout<<"Min no of coins required:"<<no<<endl;
  return 0;
}

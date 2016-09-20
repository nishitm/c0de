#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> coin={3,5,10};


int coin3(int val)
{
  if(val==0)
  {
    return 1;
  }
  if(val>=coin[2])
    return coin3(val-coin[2]);
  else
    return 0;
}

int coin2(int val)
{
  if(val==0)
  {
    return 1;
  }
  if(val>=coin[1])
    return coin2(val-coin[1]) + coin3(val-coin[2]);
  else
    return 0;
}


int coin1(int val)
{
  if(val==0)
  {
    return 1;
  }

  if(val>=coin[0])
    return coin1(val-coin[0]) + coin2(val-coin[1]) + coin3(val-coin[2]);
  else if(val>=coin[1])
    return coin2(val-coin[1]) + coin3(val-coin[2]);
  else if(val>=coin[2])
    return coin3(val-coin[2]);
  else
    return 0;
}

int main()
{
  int val = 20;

  std::sort(coin.begin(),coin.end());
  int ways= coin1(val);

  cout<<"#of ways:"<<ways<<endl;
  return 0;
}

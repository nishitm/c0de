#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int knapSack(int W, vector<int> wt, vector<int> val, int n)
{

   if (n == 0 || W == 0)
       return 0;

   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);
   else
       return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
}

int main()
{
  vector<int> val = {10,4,5,5,10};
  vector<int> wt = {1,2,5,3,6};
  int  W = 9;

  cout<< "Max value is:"<<knapSack(W,wt,val,wt.size())<<endl;

  return 0;
}

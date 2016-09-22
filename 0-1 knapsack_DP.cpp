#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val)
{
  int n=wt.size();
  int K[n+1][W+1];

  for (int i = 0; i <= n; i++)
   {
       for (int w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];

}

int main()
{
  vector<int> val = {10,4,5,5,10};
  vector<int> wt = {1,2,5,3,6};
  int  W = 9;

  cout<< "Max value is:"<<knapSack(W,wt,val)<<endl;

  return 0;
}

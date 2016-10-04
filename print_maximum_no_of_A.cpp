// Problem:Imagine you have a special keyboard with the following keys:
//         A
//         Ctrl+A
//         Ctrl+C
//         Ctrl+V
        // where CTRL+A, CTRL+C, CTRL+V each acts as one function key for “Select All”, “Copy”, and “Paste” operations respectively.
        // If you can only press the keyboard for N times (with the above four keys),
        // please write a program to produce maximum numbers of A.
        // If possible, please also print out the sequence of keys.

#include<bits/stdc++.h>

using namespace std;

int find_max(int n)
{
  int dp[n];

  if(n<=6)
    return n;

  for(int i=0;i<7;i++)
    dp[i]=i+1;

  for(int i=7;i<=n;i++)
  {
    dp[i-1]=0;

    for(int j=i-3;j>=1;j--)
    {
      int max=dp[j-1]*(i-j-1);

      if(max>dp[i-1])
        dp[i-1]=max;
    }
  }

  return dp[n-1];


}

int main()
{
   int n;
   cout<<"No of keys one can press:";
   cin>>n;

   int max = find_max(n);

   cout<<"Max no of A's can be printed is:"<<max<<endl;

   return 0;
}

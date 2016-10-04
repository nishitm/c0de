#include<bits/stdc++.h>
using namespace std;

int count(string s)
{
  int n=s.length();

  int dp[n+1];
  dp[0]=1;

  vector<int> v(CHAR_MAX,-1);

  for(int i=1;i<=n;i++)
  {
    dp[i]=dp[i-1]*2;

    if(v[s[i-1]]!=-1)
      dp[i]=dp[i]-dp[v[s[i-1]]];

    v[s[i-1]]=i-1;
  }

  return dp[n];
}

int main()
{
  string s;
  cout<<"Enter string:";
  cin>>s;

  int n=count(s);
  cout<<"No of distinct subsequence:"<<n<<endl;

  return 0;

}

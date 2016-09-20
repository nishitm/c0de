#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


int LCS(string s1, string s2, int n, int m)
{
    if(n== s1.length() || m==s2.length())
      return 0;

    if(s1[n]==s2[m])
      return 1 + LCS(s1,s2,n+1,m+1);

    else
      return std::max(LCS(s1,s2,n,m+1), LCS(s1,s2,n+1,m));

}


string LCS_print(string s1, string s2, int n, int m)
{
  string ans="";
  string ans2="";
  if(n<0 || m<0)
    return ans;

  if(s1[n]==s2[m])
  {
    ans+=s1[n];
    ans+= LCS_print(s1,s2,n-1,m-1);
    return ans;
  }
  else
  {
    //ans+=s1[n];
    ans+=LCS_print(s1,s2,n-1,m);

    //ans2+=s2[m];
    ans2+=LCS_print(s1,s2,n,m-1);

    if(ans.size()>ans2.size())
      return ans;

    return ans2;
  }
}





int main()
{
  string s1="aflhjsdfkjh";
  string s2="adfglkdfglj";

  int size = LCS(s1,s2,0,0);
  cout<<"LCS size:"<<size<<endl;

  string ans=LCS_print(s1,s2,s1.length(),s2.length());
  reverse(ans.begin(),ans.end());
  cout<<"LCS string:"<<ans<<endl;

  return 0;
}

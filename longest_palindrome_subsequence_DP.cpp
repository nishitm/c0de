#include<bits/stdc++.h>
using namespace std;

int longest_palindrome(string s, int n)
{
  int L[n][n];

  for(int i=0;i<n;i++)
    L[i][i]=1;

    for (int x=2; x<=n; x++)
     {
         for (int i=0; i<n-x+1; i++)
         {
             int j = i+x-1;
             if (s[i] == s[j] && x == 2)
                L[i][j] = 2;
             else if (s[i] == s[j])
                L[i][j] = L[i+1][j-1] + 2;
             else
                L[i][j] = std::max(L[i][j-1], L[i+1][j]);
         }
     }
    return L[0][n-1];
}



int main()
{
  string s;//="abbababdc";

  cout<<"Enter String:";
  cin>>s;

  int size=longest_palindrome(s,s.length());

  cout<<"Size of Longest Palindrome subsequence is:"<<size<<endl;
  return 0;
}

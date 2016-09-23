#include<bits/stdc++.h>
using namespace std;


int longest_palindrome(string s)
{
  int n = s.length();
  vector<vector<bool> > table(n);
  for(auto &x:table)
    x.resize(n);

  for (int i=0; i<n; i++)
    table[i][i] = true;

  int max=1;

  for(int i=0; i<n-1; i++)
  {
    if(s[i]==s[i+1])
    {
      table[i][i+1]=true;
      max=2;
    }
  }

  for(int i=3; i<=n; i++)
  {
    for(int j=0; j<n-i+1; j++)
    {
      int k=i+j-1;

      if(table[j+1][k-1] && s[j]==s[k])
      {
        table[j][k]=true;

        if(i>max)
          max=i;
      }
    }
  }

  return max;
}

int main()
{
  string s;
  cout<<"Enter the string:";
  cin>>s;

  int size=longest_palindrome(s);

  cout<<"Longest palindrome substring is of size:"<<size<<endl;
  return 0;
}

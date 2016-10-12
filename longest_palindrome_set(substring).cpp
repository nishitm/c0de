#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {

    int i = 0;
       int p = 0, q = 0;
       int len = s.length();
       int pos = 0;
       int max_len = 1;

       while (i < len)
       {
           //odd
           p = i - 1;
           q = i + 1;

           if ((len - q) * 2 + 1 < max_len)
               break;

           while (p >= 0 && q < len && s[p] == s[q])
           {
               p--;
               q++;
           }

           p++;
           q--;
           int tmp = q - p + 1;
           if (tmp > max_len)
           {
               max_len = tmp;
               pos = p;
           }

           //even
           p = i;
           q = i + 1;

           while (p >= 0 && q < len && s[p] == s[q])
           {
               p--;
               q++;
           }

           p++;
           q--;
           tmp = q - p + 1;
           if (tmp > max_len)
           {
               max_len = tmp;
               pos = p;
           }

           i++;
       }

       return s.substr(pos, max_len);

}

int longest_palindrome_length(string s)
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

  int size=longest_palindrome_length(s);

  cout<<"Longest palindrome substring is of size:"<<size<<endl;
  cout<<"Longest palindrome string is:"<<longestPalindrome(s)<<endl;
  return 0;
}

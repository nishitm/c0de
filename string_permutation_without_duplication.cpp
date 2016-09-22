#include<iostream>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void permutation_without_dups(string s, int n, int m)
{
   char comp[256]; //for comparing repetation

  //  for(int i=0;i<256;i++)
  //     comp[i]=0;

   bzero(comp,256);
   if (n == m)
     cout<<s<<endl;
   else
   {
       for (int i = n; i <= m; i++)
       {
        if(!comp[s[i]]){
          comp[s[i]]=1;
          std::swap(s[n], s[i]);
          permutation_without_dups(s, n+1, m);

        }
       }
   }
}


int main()
{
  string s;
  cout<<"Enter string:";
  cin>>s;

  permutation_without_dups(s,0,s.length()-1);

  return 0;
}

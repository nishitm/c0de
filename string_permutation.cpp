#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

void permutation(string s, int n, int m)
{
   if (n == m)
     cout<<s<<endl;
   else
   {
       for (int i = n; i <= m; i++)
       {
          std::swap(s[n], s[i]);
          permutation(s, n+1, m);
       }
   }
}


int main()
{
  string s;
  cout<<"Enter string:";
  cin>>s;

  permutation(s,0,s.length()-1);

  return 0;
}

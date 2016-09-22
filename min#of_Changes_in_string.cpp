#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int edit=0;
int del=0;

void find_changes(string s1, string s2, int n, int m)
{
  if(n<0 || m<0)
    return;


  if(s1[n]==s2[m])
  {
    find_changes(s1,s2,n-1,m-1);
  }

  else
  {
      if(n==m)
      {
          edit++;
          find_changes(s1,s2,n-1,m-1);

      }

      else
      {
        del++;
          if(n>m)
            find_changes(s1,s2,n-1,m);
          else
            find_changes(s1,s2,n,m-1);
      }
    }
}


int main()
{
  string s1,s2;
  cout<<"Enter string 1:";
  cin>>s1;
  cout<<"Enter string 2:";
  cin>>s2;

  find_changes(s1,s2,s1.length(),s2.length());

  cout<<"Edit Req:"<<edit<<endl;
  cout<<"Ins/Del Req:"<<del<<endl;

  return 0;
}

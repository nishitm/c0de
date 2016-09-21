#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

void possible_paranthesis_pair(int n, int m, int count, string par)
{
  if(n==0)
  {
    if(m!=0)
    {
      while(m!=0)
      {
        par+=")";
        m--;
      }
      cout<<par<<endl;
      return;
    }
    else
    {
      cout<<par<<endl;
      return;
    }
  }
  else
  {
    if(count==0)
    {
      par+="(";
      possible_paranthesis_pair(n-1,m,count+1,par);
      return;
    }
    else
    {
      possible_paranthesis_pair(n,m-1,count-1,par+")");
      possible_paranthesis_pair(n-1,m,count+1,par+"(");
      return;
    }
  }
  return;
}


int main()
{
  int n=4; //no of paranthesis

  possible_paranthesis_pair(n,n,0,"");

  return 0;
}

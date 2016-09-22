#include<bits/stdc++.h>
using namespace std;

int min_jumps(vector<int> v)
{

  int n=v.size();
  int jump[n];
  if(n==0 || v[0]==0)
    return INT_MAX;

  jump[0]=0;

  for (int i = 1; i < n; i++)
    {
        jump[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= j + v[j] && jump[j] != INT_MAX)
            {
                 jump[i] = min(jump[i], jump[j] + 1);
                 break;
            }
        }
    }

    return jump[n-1];
}

int main()
{
  vector<int> v={1,3,5,8,9,2,6,7,6,8,9};

  int jumps=min_jumps(v);

  cout<<"Min Required jumps to reach end is:"<<jumps<<endl;
  return 0;
}

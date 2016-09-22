#include<bits/stdc++.h>
using namespace std;

int bitonic( vector<int>v)
{
    int n=v.size();


    vector<int>lis(n);
    for (int i = 0; i < n; i++)
      lis[i] = 1;

    vector<int> lis2(n);
    for (int i = 0; i < n; i++)
      lis2[i] = 1;

    for (int i = 1; i < n; i++)
      for (int j = 0; j < i; j++)
         if (v[i] > v[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;


    for (int i = n-2; i >= 0; i--)
      for (int j = n-1; j > i; j--)
         if (v[i] > v[j] && lis2[i] < lis2[j] + 1)
            lis2[i] = lis2[j] + 1;

    int max = lis[0] + lis2[0] - 1;
    for (int i = 1; i < n; i++)
     if (lis[i] + lis2[i] - 1 > max)
         max = lis[i] + lis2[i] - 1;

    return max;
}

int main()
{
  vector<int> v={2,3,6,9,1,21,245,4,9687,62,13,21,684,3,6,655,41,2,3,56,5};

  int size=bitonic(v);

  cout<<"Size of longest bitonic sequence is:"<<size<<endl;
  return 0;
}

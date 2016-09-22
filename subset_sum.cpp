#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> arr, int n, int sum)
{
    bool subset[sum+1][n+1];

    for (int i = 0; i <= n; i++)
      subset[0][i] = true;

    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;

      for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= arr[j-1])
           subset[i][j] = subset[i][j] || subset[i - arr[j-1]][j-1];
       }
     }

     return subset[sum][n];
}


int main()
{
  vector <int> arr = {1,3,2,9};
  int n = arr.size();
  int sum;
  cout<<"Enter required sum:";
  cin>>sum;
  bool ans=subsetSum(arr, n, sum);
  if(ans)
    cout << "subset found with required sum"<<endl;
  else
    cout<< "no subset found with required sum"<<endl;
  return 0;
}

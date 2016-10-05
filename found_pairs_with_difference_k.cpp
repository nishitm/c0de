#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cout<<"Enter the size of input array:";
  cin>>n;
  unordered_map<int,int> map;
  vector<int> array;

  int k;
  cout<<"Enter the value of difference k:";
  cin>>k;

  cout<<"Enter values\n";

  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    array.push_back(x);
    map[x]=1;
  }

  int count=0;
  for(int i=0;i<array.size();i++)
  {
      if(map[array[i]+k]==1)
        count++;

      if(map[array[i]-k]==1)
        count++;

      map[array[i]]=0;
  }

  cout<<"Total no of pairs with k difference is:"<<count<<endl;

  return 0;

}

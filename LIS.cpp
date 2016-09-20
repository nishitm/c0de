#include<iostream>
#include <vector>
using namespace std;
vector<int> arr = {5,1,3,6,9,7,4,23,65,9,8,7,4,1,2,23,5,49684};

void LIS()
{
  vector< vector<int> > t(arr.size());

  t[0].push_back(arr[0]);

  for(int i=1;i<arr.size();i++)
  {
    for(int j=0; j<i; j++)
    {
      if(arr[i]>arr[j] && t[i].size()<t[j].size()+1)
        t[i]=t[j];
    }
    t[i].push_back(arr[i]);
  }

  vector<int> lis = t[0];

  for(vector<int> i : t)
  {
    if(i.size()>lis.size())
      lis=i;
  }

  cout<<"LIS is:"<<endl;
  for(int i=0;i<lis.size();i++)
    cout<<lis[i]<<endl;
}


int main()
{
  LIS();
  return 0;

}

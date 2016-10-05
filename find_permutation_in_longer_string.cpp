/*find all permutation of shorter string in longer string*/
#include<bits/stdc++.h>
using namespace std;



void find_permutation(unordered_map<char,int> map,string smaller, string larger, int start, int end)
{
  if(end>=larger.size())
    return;
  unordered_map<char,int> temp;

  for(int i=start;i<end;i++)
    temp[larger[i]]+=1;

  int count=0;
  for(int i=0;i<smaller.size();i++)
  {
    if(map[smaller[i]]==temp[smaller[i]])
      count++;
  }
  if(count==smaller.size())
  {
    for(int i=start;i<end;i++)
      cout<<larger[i];

    cout<<" & location starting index="<<start;
    cout<<endl;
  }
  find_permutation(map,smaller,larger,start+1,end+1);
}

int main()
{
  string larger,smaller;

  cout<<"Enter larger string:";
  cin>>larger;
  cout<<"enter smaller string:";
  cin>>smaller;

  unordered_map<char,int> map;
  for(int i=0;i<smaller.size();i++)
  {
    map[smaller[i]]+=1;
  }

  find_permutation(map,smaller,larger,0,smaller.size());
  return 0;
}

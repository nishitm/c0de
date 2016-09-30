// Problem::In a certain language which has same alphabets as in english language (ie. a-z),
          // but the order of the alphabets is different (for eg 's' is the first character, 'g' is second, and likewise).
          // Given a dictionary of this new language (which has words arranged according to new alphabetical order),
          // FInd out the order of alphabets in this language.


#include<bits/stdc++.h>

using namespace std;

void topo_sort(vector< list< char > > adjacencyList, vector<int> ind)
{
  if(find(ind.begin(), ind.end(), 0) == ind.end())
  {
    cout<<"Cycle detected";
    return;
  }

  while(find(ind.begin(), ind.end(), 0) != ind.end())
  {
      bool flag=false;
      int index=0;
      while(index<26)
      {
        if(ind[index]==0)
        {
          flag=true;
          break;
        }
        index++;
      }
      if(flag)
      {
        cout<<(char)(index+'a')<<endl;
        while(!adjacencyList[index].empty())
        {
          ind[adjacencyList[index].front()-'a']--;
          adjacencyList[index].pop_front();
        }
        ind[index]=-1;
      }
      else
        return;
  }
}

int main()
{
    vector<string> s;
    cout<<"Enter the no of strings that dictonary have:";
    int n;
    cin>>n;

    cout<<"Enter all words one by one:\n";
    for(int i=0;i<n;i++)
    {
      string x;
      cin>>x;
      s.push_back(x);
    }

    vector< list< char > > adjacencyList(26);
    vector<int> ind(26);

    for(int i=0;i<26;i++)
      ind[i]=-1;

    for(int i=0;i<n-1;i++)
    {
      int s1 = s[i].size();
      for(int j=i+1;j<n;j++)
      {
        int s2 = s[j].size();

        for(int k=0;k<min(s1,s2);k++)
        {
          if(s[i][k]!=s[j][k])
          {
            if(find(adjacencyList[s[i][k]-'a'].begin(), adjacencyList[s[i][k]-'a'].end(), s[j][k])==adjacencyList[s[i][k]-'a'].end())
            {
              adjacencyList[s[i][k]-'a'].push_back(s[j][k]);
              if(ind[s[i][k]-'a']==-1)
                ind[s[i][k]-'a']=0;
              if(ind[s[j][k]-'a']==-1)
                ind[s[j][k]-'a']=1;
              else
                ind[s[j][k]-'a']++;
            }
            break;
          }
        }
      }
    }
    
    topo_sort(adjacencyList,ind);

    return 0;
}

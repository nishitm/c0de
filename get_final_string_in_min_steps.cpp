// Problem::There is a string whose characters can only be either ‘a’, ‘b’ or ‘_’ (there can be only one ‘_’ in the string).
          // At each step, we can modify the string as follows:
          // 1. ‘_’ can be swapped with its adjacent character, example “a_ba” can be changed to either “_aba” or “ab_a”.
          // 2. Two characters adjacent to ‘_’ (both on the same side of ‘_’) can be reversed along with the ‘_’ if both characters are different,
          // example, “aa_ba” can be changed to “aaab_” but not to “_aaba” because both characters are ‘a’.
          // You are given two strings, the initial state and the final state (lengths will be same),
          // you have to output the minimum number of steps required to change the string in initial state to the string in the final state.
          // example: input: a_b ab_ output: 1
          // input: abaa_a b_aaaa output: 4 reason for example 2:- abaa_a -> aba_aa -> ab_aaa -> _baaaa -> b_aaaa

#include<bits/stdc++.h>

using namespace std;

int Intial2final(string i, string f)
{
  if(i.length()!=f.length())
    return -1;

  if(i==f)
    return 0;

  vector<string> visited;
  visited.push_back(i);

  queue<pair<string,int> > q;

  q.push(pair<string,int>(i,0));

  int index_in_initial, index_in_final;



  while(!q.empty())
  {
      if(q.front().first==f)
        return q.front().second;
      else
      {
        string x=q.front().first;
        int w=q.front().second;
        q.pop();

        int j;
        for(j=0; j<i.length(); j++)
        {
          if(x[j]=='_')
          {
            index_in_initial=j;
            break;
          }
        }

        if(j-1>=0){
            swap(x[j-1],x[j]);
            if(find(visited.begin(), visited.end(), x) == visited.end())
                  q.push(pair<string,int>(x,w+1));
            swap(x[j-1],x[j]);
          }

        if(j+1<i.length()){
            swap(x[j],x[j+1]);
            if(find(visited.begin(), visited.end(), x) == visited.end())
                  q.push(pair<string,int>(x,w+1));
            swap(x[j],x[j+1]);
          }

        if(j-2>=0)
        {
            if(i[j-1]!=i[j-2])
            {
                swap(x[j-2],x[j]);
                if(find(visited.begin(), visited.end(), x) == visited.end())
                      q.push(pair<string,int>(x,w+1));
                swap(x[j-2],x[j]);
            }
          }

        if(j+2<i.length())
        {
            if(i[j+1]!=i[j+2])
            {
                swap(x[j],x[j+2]);
                if(find(visited.begin(), visited.end(), x) == visited.end())
                      q.push(pair<string,int>(x,w+1));
                swap(x[j],x[j+2]);
            }
          }

      }
  }
  return -1;

}

int main()
{
  string i,f;
  cout<<"Enter Initial string:";
  cin>>i;
  cout<<"Enter final string:";
  cin>>f;

  int min_step= Intial2final(i,f);

  cout<<"min no of steps are:"<<min_step<<endl;

  return 0;
}

// Problem::Equations are given in the format A / B = k,
          // where A and B are variables represented as strings, and k is a real number (floating point number).
          // Given some queries, return the answers.
          // If the answer does not exist, return -1.0.


#include<bits/stdc++.h>

using namespace std;

bool Get_res(const string &from, const string &to, unordered_map<string,map<string,double> > &m, unordered_set<string> &visited, double &ins)
{
  if(from==to)
    return true;

  if(visited.find(from)!=visited.end())
    return false;

  visited.insert(from);

  for(auto &p :m[from])
  {
      double I = ins * p.second;
      if(Get_res(p.first,to,m,visited,I) == true)
      {
          ins = I;
          return (true);
      }
  }
  return false;
}

vector<double> evaluate_division(vector<pair<string,string> > equn, vector<double>& ratio, vector<pair<string,string> > q)
{
  unordered_map<string,map<string,double> > m;
  vector<double> result;

  int i=0;
  for(auto &p:equn)
  {
    m[p.first].insert({p.second,ratio[i]});
    m[p.second].insert({p.first,(1.0/ratio[i])});
    i++;
  }

  for(auto &p:q)
  {
    unordered_set<string> visited;

    if(m.find(p.first)==m.end())
    {
      result.push_back(-1);
      continue;
    }

    if(m[p.first].find(p.second) != m[p.first].end())
    {
        result.push_back(m[p.first][p.second]);
        continue;
    }
    double ins = 1.0;

    if(Get_res(p.first,p.second,m,visited,ins))
    {
        result.push_back(ins);
    }
    else
    {
        result.push_back(-1.0);
    }

  }
  return result;
}


int main()
{
  int n;
  vector<pair<string,string> > equn;
  vector<double> ratio;
  cout<<"Enter the no of equations you have:";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cout<<"Enter the numerator:";
    string num;
    cin>>num;
    cout<<"Enter the denomenator:";
    string num2;
    cin>>num2;
    equn.push_back({num,num2});
    cout<<"Enter value of K:";
    double k;
    cin>>k;
    ratio.push_back(k);
  }
  int nodes=equn.size();

  cout<<"Enter the no of queries:";
  int queries;
  cin>>queries;
  vector<pair<string,string> > q;
  while(queries--)
  {
      cout<<"Enter the numerator:";
      string qn;
      cin>>qn;
      cout<<"Enter the denomenator:";
      string qd;
      cin>>qd;
      q.push_back({qn,qd});
  }
  vector<double> ans = evaluate_division(equn,ratio,q);

  for(double d:ans)
    cout<<d<<endl;


  return 0;
}

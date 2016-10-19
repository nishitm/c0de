// Problem::Given two integers ‘n’ and ‘m’, find all the stepping numbers in range [n, m]. A number is called stepping number if all adjacent digits have an absolute difference of 1. 321 is a Stepping Number while 421 is not.
            //
            // Examples:
            //
            // Input : n = 0, m = 21
            // Output : 0 1 2 3 4 5 6 7 8 9 10 12 21
            //
            // Input : n = 10, m = 15
            // Output : 10, 12
#include<bits/stdc++.h>
using namespace std;

vector<int> steppin_no(int n, int m)
{
    queue<int> q;
    if(n>=10)
    {
        for(int i=0;i<10;i++)
            q.push(i);
    }
    else if(n<10 && m>=10)
    {
        for(int i=n;i<10;i++)
            q.push(i);
    }
    else
    {
        for(int i=n;i<=m;i++)
            q.push(i);
    }

    vector<int> ans;
    while(!q.empty())
    {
        int a=q.front();
        if(a>=n && a<=m)
            ans.push_back(a);
        q.pop();

        if(a<10)
        {
            if((a-1)>=0 && a*10+(a-1) <=m && a*10+(a-1)>=n)
                q.push(a*10+(a-1));

            if(a*10+(a+1) <=m && a*10+(a+1)>=n)
                q.push(a*10+(a+1));
        }
        else
        {
            int n=a;
            a=a%10;
            if((a-1)>=0 && n*10+(a-1) <=m && a*10+(a-1)>=n)
                q.push(n*10+(a-1));

            if(n*10+(a+1) <=m && a*10+(a+1)>=n)
                q.push(n*10+(a+1));
        }
    }
    return ans;
}


int main()
{
    int n,m;
    cout<<"Enter lower bound and upper bound:";
    cin>>n>>m;

    vector<int>ans=steppin_no(n,m);

    for(auto a:ans)
        cout<<a<<" ";
    cout<<endl;
    return 0;

}

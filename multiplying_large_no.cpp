#include<bits/stdc++.h>

using namespace std;


string multiply(string a, string b)
{
    int len_a=a.length();
    int len_b=b.length();

    int r=len_b;
    int c=len_a+len_b+1;
    int mat[r][c];

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            mat[i][j]=0;

    int carry=0;
    int x=len_a-1;
    int y=len_b-1;
    int temp;
    for(int i=0;i<r;i++)
    {
        carry=0;
        x=len_a-1;
        for(int j=c-i-1; j>=0;j--)
        {
            if(x>=0&&y>=0)
            {
                    temp=(a[x]-'0')*(b[y]-'0') + carry;
                    mat[i][j]=temp%10;
                    if(temp<10)
                        carry=0;
                    else
                        carry=temp/10;
            }
            else if(x>=-1 && y>=-1)
                mat[i][j]=carry;

            x--;
        }
        y--;
    }

    int sum[c];
    for(int i=0;i<c;i++)
        sum[i]=0;

    for(int i=0;i<r;i++)
        for(int j=c-1;j>=0;j--)
            sum[j]+=mat[i][j];

    carry=0;
    for(int i=c-1;i>=0;i--)
    {
        sum[i]+=carry;
        temp=sum[i];
        sum[i]=sum[i]%10;
        if(temp<10)
            carry=0;
        else
            carry=temp/10;
    }

    string ret;
    for(int i=0;i<c;i++)
    {
        char x=sum[i]+'0';
        ret=ret+x;
    }

    return ret;
}


int main()
{
    string a,b;
    cout<<"enter no1:";
    cin>>a;
    cout<<"enter no2:";
    cin>>b;

    string ans=multiply(a,b);

    cout<<"ans="<<ans<<endl;
    return 0;
}

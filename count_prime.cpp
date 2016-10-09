// Problem::Count the number of prime numbers less than a non-negative number, n.

#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {

        vector<bool> prime(n,true);

        for(int i=2;i*i<n;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<n;j+=i)
                    prime[j]=false;
            }
        }
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(prime[i])
                ans++;
        }
        return ans;

}

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;

    cout<<"No of prime no less than n is:"<<countPrimes(n)<<endl;

    return 0;
}

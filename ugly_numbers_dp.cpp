// Problem::Write a program to find the n-th ugly number.
            //
            // Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
            //
            // Note that 1 is typically treated as an ugly number.

#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {

       int dp[n]; memset(dp, 0, sizeof(dp)); dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0, min2 = 2, min3 = 3, min5 = 5;

        for (int i = 1; i < n; i++) {
            dp[i] = min(min2, min(min3, min5));
            if (dp[i] == min2) { min2 = dp[++p2] * 2; }
            if (dp[i] == min3) { min3 = dp[++p3] * 3; }
            if (dp[i] == min5) { min5 = dp[++p5] * 5; }
        }

        return dp[n - 1];
    }

int main()
{
    int n;
    cout<<"write nth no for which you want to find ugly no:";
    cin>>n;

    cout<<"Nth ugly no is:"<<nthUglyNumber(n)<<endl;

    return 0;

}

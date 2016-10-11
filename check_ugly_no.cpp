// Problem::Write a program to check whether a given number is an ugly number.
            //
            // Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
            //
            // Note that 1 is typically treated as an ugly number.

#include<bits/stdc++.h>
using namespace std;

bool isUgly(int num) {

        if (num <= 0 || num > INT32_MAX)
            return false;
        else
        {
            while (num % 5 == 0)
                num = num / 5;

            while (num % 3 == 0)
                num = num / 3;

            while (num % 2 == 0)
                num = num / 2;

            if (num > 1)
                return false;
            else
                return true;
        }
    }

int main()
{
    int n;
    cout<<"Write a no for which you want to check whether it is ugly or not:";
    cin>>n;

    cout<<"No is ugly or not? 1-yes 0-No :"<<isUgly(n)<<endl;

    return 0;
}

// Problem::Given a list of non negative integers, arrange them such that they form the largest number.
//
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
// Note: The result may be very large, so you need to return a string instead of an integer.

#include<bits/stdc++.h>
using namespace std;

bool mysort(string a,string b)
{
    string ab=a+b,ba=b+a;
    return ab>ba;
}

string largestNumber(vector<int>& nums) {
    //sort(nums.begin(),nums.end(),mysort);
    vector<string> n;
    for(auto a:nums)
    {
        stringstream ss;
        ss<<a;
        n.push_back(ss.str());
    }
    sort(n.begin(),n.end(),mysort);
    string s="";
    if(n[0]=="0")
        return "0";
    for(auto a:n)
        s+=a;
    return s;

}

int main()
{
    vector<int> v{9,12,32};

    cout<<"Largest string:"<<largestNumber(v)<<endl;
    return 0;
}

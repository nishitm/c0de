/*
We have N numbers as an array, you need to find a prefix array and a suffix array,
which we can get the maximum xor value with all elements in them. Notice that for
prefix[0, l] and suffix[r, n - 1], do not intersect (l < r), and they can be empty.

Input
The first line is one number N (1 <= N <= 100000)
The second line contains N numbers ai(0 <= ai <= 1e12) separated by space,
which represents the array.

Output
Just output the maximum xor result.

Input
3
1 2 3
output
3
*/
#include <bits/stdc++.h>

using namespace std;

long long int max_xor_prefix_suffix(vector<long long int> nums)
{
    vector<long long int> prefix(nums.size()+1),suffix(nums.size()+1);
    int n=nums.size();
    prefix[0]=0;
    suffix[nums.size()]=0;
    for(int i=1;i<=nums.size();++i)
        prefix[i]=prefix[i-1]^nums[i-1];
    for(int j=nums.size()-1;j>=0;--j)
        suffix[j]=suffix[j+1]^nums[j];

    long long int maxxor=0;
    for(int i=0;i<=nums.size();++i)
        for(int j=i;j<=nums.size();++j)
            maxxor=max(prefix[i]^suffix[j],maxxor);
    return maxxor;
}

int main()
{
    vector<long long int> v;
    int n;
    long long int temp;
    cin>>n;
    while(n--){
        cin>>temp;
        v.push_back(temp);
    }
    cout<<max_xor_prefix_suffix(v)<<endl;
    return 0;
}

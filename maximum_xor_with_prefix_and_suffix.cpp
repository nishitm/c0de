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

long long max_xor_prefix_suffix(vector<long long> vec)
{
    vector<long long> prefix(vec.size()+1),suffix(vec.size()+1);
    int n=vec.size();
    prefix[0]=0;
    suffix[vec.size()]=0;

    for(int i=1;i<=vec.size();++i)
        prefix[i]=prefix[i-1]^vec[i-1];
        
    for(int j=vec.size()-1;j>=0;--j)
        suffix[j]=suffix[j+1]^vec[j];

    long long maxxor=0;
    for(int i=0;i<=vec.size();++i)
        for(int j=i;j<=vec.size();++j)
            maxxor=max(prefix[i]^suffix[j],maxxor);

    return maxxor;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> vec(n);
    int i=0;
    while(n--){
        cin>>vec[i];
        i++;
    }
    cout<<max_xor_prefix_suffix(vec)<<endl;
    return 0;
}

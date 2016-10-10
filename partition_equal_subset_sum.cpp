// Problem::Given a non-empty array containing only positive integers,
            //find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
            // Note:
            // Both the array size and each of the array element will not exceed 100.
            //
            // Example 1:
            //
            // Input: [1, 5, 11, 5]
            //
            // Output: true
            //
            // Explanation: The array can be partitioned as [1, 5, 5] and [11].
            // Example 2:
            //
            // Input: [1, 2, 3, 5]
            //
            // Output: false
            //
            // Explanation: The array cannot be partitioned into equal sum subsets.

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {

        int sum=0;

        for(auto a:nums)
            sum+=a;

        if(sum%2!=0)
            return false;

        bool table[(sum/2)+1][nums.size()+1];

        for(int i=0;i<=nums.size();i++)
            table[0][i]=true;

        for(int i=1;i<(sum/2)+1;i++)
            table[i][0]=false;

        for(int i=1;i<(sum/2)+1;i++)
        {
            for(int j=1;j<=nums.size();j++)
            {
                table[i][j]=table[i][j-1];
                if(i>=nums[j-1])
                    table[i][j] = table[i][j] || table[i-nums[j-1]][j-1];
            }
        }
         return table[(sum/2)][nums.size()];

    }

int main()
{
    int n;
    cout<<"enter size of vector:";
    cin>>n;
    vector<int> v(n);
    cout<<"enter vector elements\n";
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<"Can array be divided into two equal sum subset? 1.yes 0.No :"<<canPartition(v)<<endl;

    return 0;
}

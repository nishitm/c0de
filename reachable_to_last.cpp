// Problem::Given an array of non-negative integers, you are initially positioned at the first index of the array.
            //
            // Each element in the array represents your maximum jump length at that position.
            //
            // Determine if you are able to reach the last index.
            //
            // For example:
            // A = [2,3,1,1,4], return true.
            //
            // A = [3,2,1,0,4], return false.
            //

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {

        int last_good=nums.size()-1;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i+nums[i]>=last_good)
                last_good=i;
        }

        if(last_good!=0)
            return false;
        return true;
    }

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> v(n);

    cout<<"Enter the elements of array:\n";
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<"Reachable to last or not? 1-yes 0-No: "<<canJump(v)<<endl;

    return 0;
}

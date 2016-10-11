// Problem::Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
            //
            //     For example, given array S = {-1 2 1 -4}, and target = 1.
            //
            //     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size() < 3) return 0;
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());

        for(int f=0;f<nums.size()-2;f++)
        {
            if(f > 0 && nums[f] == nums[f-1])
                continue;

            int s=f+1;
            int t=nums.size()-1;

            while(s<t)
            {
                int curSum = nums[f]+nums[s]+nums[t];
                if(curSum == target)
                    return curSum;

                if(abs(target-curSum)<abs(target-closest))
                    closest = curSum;

                if(curSum > target)
                    t--;

                else
                    s++;
            }
        }
        return closest;

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

    cout<<"Enter the target value:";
    int target;
    cin>>target;

    cout<<"Closest sum to target of a triplet exist in array is:"<<threeSumClosest(v,target)<<endl;

    return 0;

}

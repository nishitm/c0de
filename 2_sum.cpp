// Problem::Given an array of integers, return indices of the two numbers such that they add up to a specific target.
            //
            // You may assume that each input would have exactly one solution.
            //
            // Example:
            // Given nums = [2, 7, 11, 15], target = 9,
            //
            // Because nums[0] + nums[1] = 2 + 7 = 9,
            // return [0, 1].

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> bak = nums;
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {

                for (int k = 0; k < bak.size(); k++)
                {
                    if (bak[k] == nums[i] || bak[k] == nums[j])
                    {
                        res.push_back(k);
                    }
                }
                return res;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
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

    int target;
    cout<<"Enter target sum:";
    cin>>target;

    vector<int> ans= twoSum(v,target);

    cout<<"Pair with target sum is:\n";
    for(auto a:ans)
        cout<<a<<" ";
    cout<<endl;

    return 0;

}

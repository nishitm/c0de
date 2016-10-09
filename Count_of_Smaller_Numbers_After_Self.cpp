// Problem::You are given an integer array nums and you have to return a new counts array.
            // The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
            //
            // Example:
            //
            // Given nums = [5, 2, 6, 1]
            //
            // To the right of 5 there are 2 smaller elements (2 and 1).
            // To the right of 2 there is only 1 smaller element (1).
            // To the right of 6 there is 1 smaller element (1).
            // To the right of 1 there is 0 smaller element.
            // Return the array [2, 1, 1, 0].

#include<bits/stdc++.h>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {

        vector<int> sorted;
        vector<int> ans(nums.size());

        if(nums.size()==0)
            return ans;

        sorted.push_back(nums[nums.size()-1]);
        ans[nums.size()-1]=0;


        for(int i=nums.size()-2;i>=0;i--)
        {
            vector<int>::iterator it;
            it=lower_bound(sorted.begin(),sorted.end(),nums[i]);
            ans[i]=(it-sorted.begin());
            sorted.insert(it,nums[i]);
        }

        return ans;
    }

int main()
{
    int n;
    cout<<"Enter the size of vector:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<int> ans = countSmaller(nums);

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;

    return 0;


}

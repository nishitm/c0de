// Problem::Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
            //
            // Note: The solution set must not contain duplicate triplets.
            //
            // For example, given array S = [-1, 0, 1, 2, -1, -4],
            //
            // A solution set is:
            // [
            //   [-1, 0, 1],
            //   [-1, -1, 2]
            // ]
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {

        vector<vector<int> > ans;

        if(nums.size()==0)
            return ans;

        sort(nums.begin(),nums.end());

        int n=nums.size();

        int i=0;
        while(i<n-2)
        {
            int j=i+1;
            int k=n-1;

            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[k]);
                    ans.push_back(t);

                    while(nums[j]==nums[j+1])
                        j++;

                    while(nums[k]==nums[k-1])
                        k--;

                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                    k--;
                else
                    j++;
            }
            while(nums[i]==nums[i+1])
                i++;

            i++;
        }

        return ans;


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

    vector<vector<int> > ans= threeSum(v);

    cout<<"triplets that contains sum 0 is-\n";
    for(auto a:ans)
    {
        for(auto b:a)
            cout<<b;
        cout<<endl;
    }
    return 0;
}

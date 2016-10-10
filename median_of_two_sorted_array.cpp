// Problem::There are two sorted arrays nums1 and nums2 of size m and n respectively.
            //
            // Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
            //
            // Example 1:
            // nums1 = [1, 3]
            // nums2 = [2]
            //
            // The median is 2.0
            // Example 2:
            // nums1 = [1, 2]
            // nums2 = [3, 4]
            //
            // The median is (2 + 3)/2 = 2.5

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int l1=nums1.size();
        int l2=nums2.size();

        stack<int> s;
        int i1=0,i2=0;

        while(i1<l1 || i2<l2)
        {
            if(i1>=l1 || i2>=l2)
            {
                if(i1<l1)
                {
                    s.push(nums1[i1]);
                    i1++;
                }
                else
                {
                    s.push(nums2[i2]);
                    i2++;
                }
            }
            else
            {
                if(nums1[i1]>nums2[i2])
                {
                    s.push(nums2[i2]);
                    i2++;
                }
                else
                {
                    s.push(nums1[i1]);
                    i1++;
                }
            }

            if(s.size()>((l1+l2)/2))
            {
                if((l1+l2)%2==0)
                {
                    int a=s.top();
                    s.pop();
                    return (a+s.top())/2.0;
                }

                else
                    return s.top();
            }
        }
        return 0;
}

int main()
{
    int n1;
    cout<<"enter size of sorted vector-1:";
    cin>>n1;
    vector<int> v1(n1);
    cout<<"enter vector elements\n";
    for(int i=0;i<n1;i++)
        cin>>v1[i];

    int n2;
    cout<<"enter size of sorted vector-2:";
    cin>>n2;
    vector<int> v2(n2);
    cout<<"enter vector elements\n";
    for(int i=0;i<n2;i++)
        cin>>v2[i];

    cout<<"Median of two sorted array is:"<<findMedianSortedArrays(v1,v2)<<endl;
    return 0;
}

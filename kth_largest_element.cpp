/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {

       make_heap(nums.begin(),nums.end());

       while(k-1!=0)

       {

           pop_heap(nums.begin(),nums.end());

           nums.pop_back();

           k--;

       }

       return nums.front();
    }

int main()
{
	int n;
	cout<<"Enter the no of elements:";
	cin>>n;
	vector<int> v(n);
	cout<<"Enter the array\n";
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	cout<<"Enter the K:";
	int k;
	cin>>k;
	cout<<"Kth largest element is:"<<findKthLargest(v,k)<<endl;
	return 0;
}

// Problem::Find the median of the array in O(n) time
        // One can do it using
                // nth_element(a, a + size / 2, a + size);
                // median = a[size/2];
        // It also takes o(n) but for the algorithm perspective using below code

#include<bits/stdc++.h>
using namespace std;

int random_partition(vector<int> v, int left, int right)
{
    int pivot = (left+right)/2;
    int pivot_value = v[right];
    int i = left - 1;
    for(int j=left; j<right; ++j)
    {
        if (v[j]<=pivot_value)
        {
            i++;
            int t=v[i];
            v[i]=v[j];
            v[j]=t;
        }
    }
    int t=v[i+1];
    v[i+1]=v[right];
    v[right]=t;

    return i+1;
}

int find_median(vector<int> v, int left, int right, int i)
{
    if (left==right)
        return v[left];
    int pivot = random_partition(v,left,right);
    int left_partition_length = pivot - left + 1;
    if (i==left_partition_length)
        return v[pivot];
    else if (i<left_partition_length)
        return find_median(v,left,pivot-1,i);
    else
        return find_median(v,pivot+1,right,i-left_partition_length);
}

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int> v(n);

    cout<<"enter the elements:\n";

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<"Median of the array is:"<<find_median(v,0,n-1,n/2+1)<<endl;

    return 0;
}

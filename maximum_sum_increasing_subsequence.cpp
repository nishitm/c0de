#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int maxSum( vector<int>seq, int n )
{
    int i, j, max = 0;
    int temp[n];

    for ( i = 0; i < n; i++ )
        temp[i] = seq[i];

    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( seq[i] > seq[j] && temp[i] < temp[j] + seq[i])
                temp[i] = temp[j] + seq[i];

     for ( i = 0; i < n; i++ )
        if ( max < temp[i] )
            max = temp[i];

    return max;
}

int main()
{

  vector<int> seq={1,4,6,100,5,89,9,23,45,32,12};

  int sum = maxSum(seq,seq.size());
  cout<<"Sum of maximum increasing subsequence is:"<<sum<<endl;

  return 0;
}

#include<bits/stdc++.h>
using namespace std;

int lookup[20][20]={0};

bool isPalindrome(string s, int l, int r)
{
	while(l<=r)
	{
    if(s[l]!=s[r])
      return false;
    l++;
    r--;
	}
	return true;
}


int palindrome_partitioning(string s, int l, int r)
{
  if(l==r || isPalindrome(s, l, r))
      return 0;

  int min = INT_MAX, count;

  if(lookup[l][r]==0){
	    for(int k = l; k<=r-1; k++) {
	    	if(lookup[l][k]==0)
	    		lookup[l][k]=palindrome_partitioning(s, l, k);

	    	if(lookup[k+1][r]==0)
	    		lookup[k+1][r]=palindrome_partitioning(s, k+1, r);

	        count = lookup[l][k] + lookup[k+1][r] + 1;
	        if (count < min)
	            min = count;
	    }
	    lookup[l][r] = min;
 	}

    return lookup[l][r];
}


int main()
{
  string s;

  cout<<"Enter the string:";
  cin>>s;

  int partitions=palindrome_partitioning(s,0,s.length()-1);

  cout<<"Min. no of partitions required:"<<partitions<<endl;
  return 0;
}

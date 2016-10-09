// Problem::Given a string, find the length of the longest substring without repeating characters.
            //
            // Examples:
            //
            // Given "abcabcbb", the answer is "abc", which the length is 3.
            //
            // Given "bbbbb", the answer is "b", with the length of 1.
            //
            // Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<bits/stdc++.h>
using namespace std;

int longest_substring(string s)
{
    int len=s.length(),maxLen=1;
    int count[256]={0};

    for(int i=0;i<len-maxLen;i++)
    {
        memset(count,0,sizeof(int)*256);
        int j;
        for(j=i;j<len;j++)
        {
            if(count[s[j]]==1)
            {
                maxLen=max(maxLen,j-i);
                break;
            }
            count[s[j]]++;
        }
        if(j==len)
            maxLen=max(maxLen,j-i);
    }
    return maxLen;
}

int main()
{
    cout<<"Enter the string:";
    string s;
    cin>>s;

    cout<<"Length of longest substring without repeating characters is:"<<longest_substring(s)<<endl;

    return 0;
}

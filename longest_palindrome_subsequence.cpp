#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int longest_palindrome(string s, int i, int j)
{
   if (i == j)
     return 1;

   if (s[i] == s[j] && i + 1 == j)
     return 2;

   if (s[i] == s[j])
      return longest_palindrome(s, i+1, j-1) + 2;

    return max(longest_palindrome(s, i, j-1), longest_palindrome(s, i+1, j));
}

int main()
{

  string s="abbababdc";

  int size=longest_palindrome(s,0,s.length()-1);

  cout<<"Size of Longest Palindrome subsequence is:"<<size<<endl;

  return 0;
}

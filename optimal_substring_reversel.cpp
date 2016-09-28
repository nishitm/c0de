// Problem ::You are given a string S. Each character of S is either ‘a’, or ‘b’.
          // You wish to reverse exactly one sub-string of S
          // such that the new string is lexicographically smaller than all the other strings that you can get by reversing exactly one sub-string.
          // For example, given ‘abab’, you may choose to reverse the substring ‘ab’ that starts from index 2 (0-based).
          // This gives you the string ‘abba’.
          // But, if you choose the reverse the substring ‘ba’ starting from index 1, you will get ‘aabb’.
          // There is no way of getting a smaller string, hence reversing the substring in the range [1, 2] is optimal.

#include<bits/stdc++.h>
using namespace std;

void sub_reversel(string s)
{
  int start_index,end_index;
  string min_string=s;
  int n = s.length();

  for(int i=0;i<n;i++)
  {
    if(s[i]=='b')
    {
      start_index=i;
      break;
    }
  }

  if(!(start_index>=0 && start_index<n))
  {
    cout<<"0, 0"<<endl;
    return;
  }

  for(int i=n-1; i>=start_index; i--)
  {
    if(s[i]=='b')
      continue;

    else
    {
      reverse(s.begin()+start_index,s.begin()+i+1);

      if(s<min_string)
      {
        // cout<<endl<<"inside";
        min_string=s;
        end_index=i;
      }
      reverse(s.begin()+start_index,s.begin()+i+1);
    }
  }
  
  if(!(end_index>=0 && end_index<n))
  {
    cout<<"0, 0"<<endl;
    return;
  }

  cout<<start_index<<", "<<end_index<<endl<<"Min lexicographic string is:"<<min_string<<endl;
  return;
}


int main()
{
    string s;
    cout<<"Enter the string of a&b:";
    cin>>s;

    sub_reversel(s);
    return 0;
}

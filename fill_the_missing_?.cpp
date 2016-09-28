// Problem::A string can contain only a, b or c.
          // There cannot be 2 consecutive same character.
          // First and last character cannot be same.
          // Now given a string with ‘a’, ‘b’, ‘c’ or ‘?’.
          // We need to find the string replacing ‘?’ that satisfy the above conditions.
          // For multiple answer display lexicographically smallest string.
          // For no answer possible display “Not Possible”.

#include<bits/stdc++.h>
using namespace std;

void missing_char(string s)
{
  int n=s.length();

  if(s[0]!='?' && (s[0]==s[1] || s[0]==s[n-1]))
  {
    cout<<"Not Possible"<<endl;
    return;
  }
  if(s[n-1]!='?' && (s[0]==s[n-1] || s[n-1]==s[n-2] ))
  {
    cout<<"Not Possible"<<endl;
    return;
  }

  if(s[0]=='?')
  {
    if(s[1]=='a' || s[n-1]=='a')
    {
      if(s[1]=='b' || s[n-1]=='b')
        s[0]='c';
      else
        s[0]='b';
    }
    else
      s[0]='a';
  }

  if(s[n-1]=='?')
  {
    if(s[n-2]=='a' || s[0]=='a')
    {
      if(s[n-2]=='b' || s[0]=='b')
        s[n-1]='c';
      else
        s[n-1]='b';
    }
    else
      s[n-1]='a';
  }

  bool f=true;
  for(int i=1;i<n-1;i++)
  {
    char p=s[i-1],q=s[i+1];

    switch (s[i]) {
      case 'a':
        if(p=='a' || q=='a')
          f=false;
        break;

      case 'b':
        if(p=='b' || q=='b')
          f=false;
        break;

      case 'c':
        if(p=='c' || q=='c')
          f=false;
        break;

      case '?':
        if(p!='a' && q!='a')
          s[i]='a';
        else
        {
          if(p=='b' || q=='b')
            s[i]='c';
          else
            s[i]='b';
        }
    }

    if(!f)
    {
      cout<<"Not Possible"<<endl;
      return;
    }
  }

  cout<<"After filling '?' in string, lexicographically min string is:"<<s<<endl;
  return;
}

int main()
{
  string s;
  cout<<"Enter string with only a,b,c,? characters:";
  cin>>s;

  missing_char(s);
  return 0;
}

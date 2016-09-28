// Problem::There is a compressed string eg. ”ab2c3”, the string has lowercase characters and numbers.
          // We can uncompress the given string as follows:
          // whenever we get a number “n” in the string, the portion of the string before the number will repeat “n” times.
          // So in the above example, we get a 2, so string will become “ababc3”, now we get a 3, so final string will be “ababcababcababc”.
          // Given a compressed string and a number k, you have to output the k’th character in the uncompressed string.

#include<bits/stdc++.h>
using namespace std;

string uncompressed(string s, int index)
{
  if(index >= s.length())
    return s;

  if(!isdigit(s[index]))
    return uncompressed(s,index+1);
  else
  {
    string x=s.substr(0,index);
    int n = x.size();
    int digit = s[index]-'0';
    digit--;

    for(int i=0; i<digit; i++)
      x = x+s.substr(0,index);

    s=s.erase(0,index+1);
    s = x + s;
    return uncompressed(s,index+(n*digit));

  }
}

int main()
{
  string s;
  cout<<"Enter compressed string:";
  cin>>s;

  string a = uncompressed(s,0);
  cout<<"Uncompressed string is:"<<a<<endl;
  return 0;
}

// Problem:: Let’s define a string as an opening tag, where x is any small letter of the Latin alphabet.
          // Each opening tag matches a closing tag of the type , where x is the same letter.
          // Tags can be nested into each other i.e., one opening and closing tag pair can be located inside another pair.
          //
          // Let’s define the notion of a XML-text:
          //
          // 1) An empty string is a XML-text
          // 2) If S is a XML-text, then “<a> S </a>” (quotes and spaces are for clarity) also is a XML-text,
          // where a is any small Latin letter
          // 3) If S1, S2 are XML-texts, then “<a>S1<b></b> S2</a>″ (quotes and spaces are for clarity) also is a XML-text
          //
          // You are given a string. You have to verify if the given string is a valid xml or not.

#include<bits/stdc++.h>

using namespace std;

bool varify_tag(string s)
{
  int i=0,n=s.length();
  stack<char> st;

  while(i<n)
  {
    if(s[i]=='<' || s[i]=='>')
    {
      i++;
      continue;
    }
    if(s[i]=='/')
    {
      i++;
      if(s[i]!=st.top())
        return false;

      st.pop();
    }
    else
    {
      st.push(s[i]);
    }
    i++;
  }
  if(!st.empty())
    return false;

  return true;
}


int main()
{
  string s;
  cout<<"Enter XML string:";
  cin>>s;

  if(varify_tag(s))
    cout<<"Valid"<<endl;
  else
    cout<<"Invalid"<<endl;

  return 0;
}

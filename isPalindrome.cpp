// Problem::Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

#include<bits/stdc++.h>
using namespace std;

bool ispal(string s)
{
    int i=0;
    int j=s.size()-1;
    while(i<=j)
        if(s[i++]!=s[j--])
            return false;

    return true;
}

    bool isPalindrome(string s) {


        for(int i=0;i<s.size();i++)
            s[i]=tolower(s[i]);

        string str="";

        for(int i=0;i<s.size();i++)
            if(isalpha(s[i]) || isdigit(s[i]))
                str+=s[i];

        return ispal(str);


    }

int main()
{
    string s="";
    cout<<"Enter sentence:";

    char c;
    scanf("%c",&c);

    while(c!='\n')
    {
        s+=c;
        scanf("%c",&c);
    }
    cout<<"Sentence is palindrome?1-yes 0-no :"<<isPalindrome(s)<<endl;
    return 0;
}

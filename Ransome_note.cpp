// Problem::

#include<bits/stdc++.h>
using namespace std;

bool ransomeNote(string ransomNote, string magazine)
{
        int magHash[256] = {0};
        for(auto ch : magazine)
            magHash[ch]++;
        for(auto ch : ransomNote)
        {
            magHash[ch]--;
            if(magHash[ch] < 0)
                return false;
        }
        return true;
}
int main()
{
    string s1,s2;
    cout<<"Enter ransome note:";
    cin>>s1;
    cout<<"Enter magazine:";
    cin>>s2;

    cout<<"Whether ransome note will use to make magazine? 1:Yes 2:No"<<ransomeNote(s1,s2)<<endl;
    return 0;
}

/*write a function to convert spaces in string with '%20' with no extra space. You assume that string has sufficient space at the end to hold additional characters*/

#include<bits/stdc++.h>

using namespace std;

string urlify(string &s,int true_length)
{
    int last_index=true_length-1;
    int last = s.length()-1;

    while(last_index>=0)
    {

        if(s[last_index]==' ')
        {

            last_index--;
            s[last]='0';
            s[last-1]='2';
            s[last-2]='%';
            last=last-3;
        }
        else
        {

            s[last]=s[last_index];
            last--;
            last_index--;
        }
    }

    return s;
}

int main()
{
    string s="Mr John Smith    ";

    string urlified_string=urlify(s,13);

    cout<<"urilified string is:"<<urlified_string<<endl;
    return 0;
}

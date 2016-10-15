/*Write a function to find the longest common prefix string amongst an array of strings.*/

#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

        

        if(strs.size()==0)

            return "";

        

        int min=strs[0].size();

        

        for(int i=0;i<strs.size();i++)

            if(min>strs[i].size())

                min=strs[i].size();

        

        string s="";

        for(int i=0;i<min;i++)

        {

            bool flag=true;

            for(int j=0;j<strs.size()-1;j++)

            {

                if(strs[j][i]!=strs[j+1][i])

                    flag=false;

            }

            if(flag)

                s=s+strs[0][i];

            else

                break;

            

        }

        

        return s;

    }

int main()
{
	int n;
	cout<<"Enter the no of strings:";
	cin>>n;
	vector<string> s(n);
	cout<<"Enter strings\n";
	for(int i=0;i<n;i++)
		cin>>s[i];
	
	cout<<"largest common prefix is:"<<longestCommonPrefix(s)<<endl;
	return 0;
}

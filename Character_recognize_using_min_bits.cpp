/*
Character recognition is the conversion of images into text. For now we consider each
character in the picture is a N*M matrix with only zeros and ones, and we need to
recognize K characters. You are to write a program to find minimal number of pixels so
that we can recognize each character.
For example, we have only two characters 'T' and 'L', and the matrix size is 3*3, we
can think 'T' and 'L' are
111 100
010 100
010 111
So we can recognize the character with only bottom-left pixel, the answer is 1.
*/
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<string> subseq)
{
    set<string> existed;
    for(string s:subseq){
        if(existed.find(s)!=existed.end())
            return false;
        else
            existed.insert(s);
    }
    return true;
}

void subsequncesOfKLength(vector<string> pref,vector<string> input ,int k, vector<vector<string> > &result)
{                                                                                                                               //function to generate all possible k length bit combinations
    if(k<0)
        return;
    if(k==0)
        result.push_back(pref);
    else if(input[0].size()){
        vector<string> pref2,input2;
        for(int i=0;i<pref.size();++i)
        {
            pref2.push_back(pref[i]+input[i][0]);
            input2.push_back(input[i].substr(1));
        }
        subsequncesOfKLength(pref2,input2,k-1,result);
        pref2.clear();
        input2.clear();
        for(int i=0;i<pref.size();++i)
        {
            pref2.push_back(pref[i]);
            input2.push_back(input[i].substr(1));
        }
        subsequncesOfKLength(pref2,input2,k,result);
    }
}

int min_bits_differ(vector<string> input)
{
    int lower = ceil(log2(input.size())),upper=input.size()-1;  //set the lower limit for the no of bits required
    vector<string> pref(input.size(),"");
    for(int i=lower;i<=upper;++i)
    {
        vector<vector<string> > subseqs;
        subsequncesOfKLength(pref,input,i,subseqs);           //find all possible i length of bit combinations
        for(auto subseq:subseqs)
            if(isValid(subseq))                                   // check if these i length bit combination can uniquely identify all strings or not?
                return i;
    }
    return -1;
}

void remove_irrelevent(vector<string>& input, int n, int m)
{
    int len=n*m;
    for(int i=0;i<len;i++)
    {
        int and_=1;
        int or_=0;
        for(int j=0;j<input.size();j++)
        {
            and_ = and_ & (input[j][i] - '0');
            or_ = or_ | (input[j][i] - '0');
        }
        if(and_==1 || or_==0)
        {
            for(int j=0;j<input.size();j++)
                input[j].erase(input[j].begin()+i);

            i--;
            len--;
        }
    }

    return;
}


int main()
{
    vector<string> input;
    int N, M, K;
    cin >> N >> M >> K;
    int k=K;
    while (K--){
        string str;
        for (int i = 0; i<N; i++)
        {
            string tmp;
            cin >> tmp;
            str += tmp;
        }
        input.push_back(str);
    }
    if(k<4)
    {
        cout<<k-1<<endl;
        return 0;
    }
    remove_irrelevent(input,N,M); //To remove the irrelevent bits in calculation (i.e. bits which are '1' or '0' in all string at perticular position)

    cout<<min_bits_differ(input)<<endl;
    return 0;
}

// Problem::You are given two strings, say A and B, of the same length, say N.
          // You can swap A[i] and B[i] for all i between 1 and N, inclusive.
          // You cannot swap two characters within A, or within B.
          // Also, you can only swap a character in A with the character at the same index in B, and with no other character.
          // You can perform this operation zero or more times.
          // You wish to modify the strings through the operations in such a way that the number of unique characters in the strings is small.
          // In fact if n(A) is the number of unique characters in A and n(B) is the number of unique characters in B;
          // you wish to perform the operations such that max(n(A),n(B)) is as small as possible.
          // Print the value of max(n(A),n(B)) after all the operations.

#include <bits/stdc++.h>>

using namespace std;

int count(string a, char b, int j, int l)
{
    int c;
    for(int i=0; i<l; i++)
    {
        if(a[i] == b && i != j)
            c++;
    }
    return c;
}

int unique(string a, int l)
{
    int count = 0;
    for(int i=0; i<l; i++)
    {
        for(int j=i+1; j<l; j++)
        {
            if(a[i] == '\0')
                break;
            if(a[i] == a[j])
                a[j] = '\0';
        }
    }
    for(int i=0; i<l; i++)
    {
        if(a[i] != '\0')
            count++;
    }
    return count;
}

int main()
{
    string a,b;
    int l,c1, c2, temp, m1, m2, maxx;
    int final=999;
    cout<<"Enter 2 same length string:"<<endl;
    cin>>a>>b;
    l=a.length();
    for(int j=0; j<l;j++)
    {
        if(a[j] == b[j])
            continue;
        else
        {
            c1 = count(a, a[j], j, l);
            c2 = count(b, a[j], j, l);
            if(c2>c1)
            {
                temp = a[j];
                a[j] = b[j];
                b[j] = temp;
            }
            m1 = unique(a,l);
            m2 = unique(b,l);
            maxx = max(m1,m2);
            if(maxx<final)
                 final = maxx;
        }
    }
    cout<<"Min unique chars after swapping are:"<<final<<endl;
    return 0;
  }

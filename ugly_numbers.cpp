// Problem:Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
          // The sequence
          // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
          // shows the first 11 ugly numbers. By convention, 1 is included.
          // Write a program to find and print the n’th ugly number.

#include<bits/stdc++.h>
using namespace std;

int divide(int a, int b)
{
  while(a%b == 0)
        a = a/b;

  return a;
}

bool isugly(int i)
{
  i=divide(i,2);
  i=divide(i,3);
  i=divide(i,5);

  if(i==1)
    return true;
  else
    return false;
}

int getUgly(int n)
{
  int c=1;
  int i=1;
  while(n>c)
  {
    i++;
    if(isugly(i))
      c++;
  }
  return i;
}

int main()
{
  int n;
  cout<<"Enter value of n:";
  cin>>n;

  int ans=getUgly(n);

  cout<<"Nth ugly no is:"<<ans<<endl;
  return 0;

}

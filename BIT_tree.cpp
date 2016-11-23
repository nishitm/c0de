
Save  New  Duplicate & Edit  Just Text  Twitter
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
#include<bits/stdc++.h>

using namespace std;

void update(vector<int>&bit, int x, int delta)
{
	for(;x<bit.size();x+=x&(-x))
		bit[x]+=delta;
}

void query(vector<int>bit,int p,int q)
{
	int s=bit[q];

	while(q!=0)
	{
		q=q-(q & (-q));
		s+=bit[q];
	}

	int t=bit[p];
	while(p!=0)
	{
		p=p-(p & (-p));
		t+=bit[p];
	}

	cout<<"range sum="<<s-t<<endl;
	return;

}

int main()
{
	int n,t;
	cin>>n;
	t=n;
	vector<int> v(n+1,0);
	int in=1;
	while(n--)cin>>v[in++];

	vector<int> bit(v.size(),0);

	for(int i=1;i<bit.size();i++)
		update(bit,i,v[i]);

	// for(auto a:bit)
	// 	cout<<a;
	// cout<<endl;

	int q,p;
	cout<<"\nrange query:\n";
	cin>>p;
	cin>>q;
	query(bit,p-1,q);
	return 0;

}

/*find median in an expanding array*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int median;
    char c;
    cout<<"You want to enter element? ";
    cin>>c;
    priority_queue<int,vector<int> > max_heap;
    priority_queue<int,vector<int>, greater<int> > min_heap;
    int temp;
    if(c=='y')
    {
        cout<<"enter element:";
        cin>>temp;
        median=temp;
    }
    cout<<"Median:"<<median<<endl;
    cout<<"You want to enter element? ";
    cin>>c;
    if(c=='y')
    {
        cout<<"enter element:";
        cin>>temp;
        if(temp>median)
        {
            min_heap.push(temp);
            max_heap.push(median);
        }
        else
        {
            min_heap.push(median);
            max_heap.push(temp);
        }
        median=min_heap.top();
    }
    else
    {
        cout<<"Median:"<<median<<endl;
        return 0;
    }
    cout<<"Median:"<<median<<endl;
    cout<<"You want to enter element? ";
    cin>>c;

    while(c=='y')
    {
        cout<<"enter element:";
        cin>>temp;

        if(temp>median)
        {
            min_heap.push(temp);
            if(min_heap.size()>max_heap.size()+1)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        else
        {
            max_heap.push(temp);
            if(max_heap.size()>min_heap.size()+1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        median=min_heap.top();
        cout<<"Median:"<<median<<endl;

        cout<<"You want to enter element? ";
        cin>>c;

    }
    return 0;
}

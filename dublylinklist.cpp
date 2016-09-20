#include<iostream>
using namespace std;

template<typename type>
struct dllnode{
  type val;
  struct dllnode<type> *left,*right;
};

template <typename type>
void insert(dllnode<type>* &start,dllnode<type>* &temp)
{
    dllnode<type> *s;
    temp->right = NULL;
    if (start == NULL)
    {
        temp->left = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->right != NULL)
            s = s->right;
        s->right = temp;
        temp->left = s;
    }
  //  cout<<temp->val;
    return;
}

template <typename type>
void printlist(dllnode<type>* start)
{
  while(start!=NULL)
  {
    cout<<start->val<<" ";
    start=start->right;
  }
  return;
}

int main()
{
  dllnode<int>* temp;
  dllnode<int>* start=NULL;
  temp=new dllnode<int>;
  temp->val=5;
  insert(start,temp);
  temp=new dllnode<int>;
  temp->val=3;
  insert(start,temp);
  temp=new dllnode<int>;
  temp->val=8;
  insert(start,temp);
  printlist(start);
}

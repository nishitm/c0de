#include<bits/stdc++.h>
using namespace std;

template<typename type>
struct binarynode{
  type val;
  struct binarynode<type> *left,*right;
  type left_count,right_count;
};

template <typename type>
void insert(binarynode<type>* &root,binarynode<type>* &temp)
{
   if (root == NULL)
    {
        root = new binarynode<type>;
        root->val = temp->val;
        root->left = NULL;
        root->right = NULL;
        root->left_count=0;
        root->right_count=0;
        return;
    }
    if (root->val > temp->val)
    {
        root->left_count++;
        if (root->left != NULL)
        {
            insert(root->left, temp);
	      }
	       else
	        {
            root->left = temp;
            (root->left)->left = NULL;
            (root->left)->right = NULL;
            return;
          }
    }
    else
    {
        root->right_count++;
        if (root->right != NULL)
        {
            insert(root->right, temp);
        }
        else
        {
            root->right = temp;
            (root->right)->left = NULL;
            (root->right)->right = NULL;
            return;
        }
    }

}

template <typename type>
void kth_element(binarynode<type>*root, int k)
{
  if(k>root->left_count+1)
    return kth_element(root->right,(k-root->left_count-1));

  else if(k == root->left_count+1)
    cout<<"Kth element is:"<<root->val<<endl;

  else if(k <= root->left_count)
    return kth_element(root->left, k);
}

int main()
{
  binarynode<int>* root=NULL;
  binarynode<int>* temp=NULL;

  cout<<"Enter the no of nodes you want to enter:";
  int n;
  cin>>n;

  while(n--)
  {
    temp=new binarynode<int>;
    cout<<"Enter value:";
    cin>>temp->val;
    temp->left_count=0;
    temp->right_count=0;
    insert(root,temp);
  }

  int k;
  cout<<"Enter kth element:";
  cin>>k;

  kth_element(root,k);

  return 0;
}

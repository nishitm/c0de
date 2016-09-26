#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return(node);
}

int max_height(struct node * root)
{
  if (root==NULL || (root->left==NULL && root->right==NULL))
      return 0;
  else
  {
      int l = max_height(root->left);
      int r = max_height(root->right);

      if (l > r)
          return(l+1);
      else
          return(r+1);
  }
}

int longest_diameter(struct node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
      return 0;

    if(root->left==NULL || root->right==NULL)
      return 1;

    return std::max( 2 + max_height(root->left) + max_height(root->right) , max(longest_diameter(root->left) , longest_diameter(root->right)));
}

int main()
{

    struct node *root = newNode(10);

    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(1);
    root->left->right->left = newNode(3);
    root->left->right->left->left= newNode(2);
    root->left->right->left->right = newNode(4);

    root->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(1);
    root->right->right = newNode(7);

    int ld= longest_diameter(root);
    cout<<"Longest Diameter in this BT is:"<<ld<<endl;

    return 0;
}

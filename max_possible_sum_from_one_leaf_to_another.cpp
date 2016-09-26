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

int max_sum_path(struct node * root)
{
  if(!root)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->data;

	return max(max_sum_path(root->left),max_sum_path(root->right)) + root->data;
}

int max_sum(struct node * root)
{
	if(!root)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->data;

	return max(root->data + max_sum_path(root->left) + max_sum_path(root->right), max(max_sum(root->left), max_sum(root->right)) );
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


    int ld= max_sum(root);
    cout<<"Max possible sum from one leaf to another is:"<<ld<<endl;

    return 0;
}

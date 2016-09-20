#include<iostream>
using namespace std;

template<typename type>
struct binarynode{
  type val;
  struct binarynode<type> *left,*right;
};

template <typename type>
void insert(binarynode<type>* &root,binarynode<type>* &temp)
{
//   temp.val=v;
   if (root == NULL)
    {
        root = new binarynode<type>;
        root->val = temp->val;
        root->left = NULL;
        root->right = NULL;
        //cout<<"inserted1-->"<<root->val<<endl;
        return;
    }
    if (root->val > temp->val)
    {
        if (root->left != NULL)
        {
            insert(root->left, temp);
	      }
	       else
	        {
            root->left = temp;
            (root->left)->left = NULL;
            (root->left)->right = NULL;
        //    cout<<"inserted2-->"<<root->val<<endl;
            return;
          }
    }
    else
    {
        if (root->right != NULL)
        {
            insert(root->right, temp);
        }
        else
        {
            root->right = temp;
            (root->right)->left = NULL;
            (root->right)->right = NULL;
        //    cout<<"inserted3-->"<<root->val<<endl;
            return;
        }
    }

}

template <typename type>
void inorder(binarynode<type>*root)
{
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->val<<endl;
  inorder(root->right);
}

template <typename type>
void preorder(binarynode<type> *root)
{
  if(root==NULL)
    return;

  cout<<root->val<<endl;

  preorder(root->left);
  preorder(root->right);
}

template <typename type>
void postorder(binarynode<type> *root)
{
  if(root==NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->val<<endl;
}
//--------------------------------------dll---------------------------------------------
template <typename type>
void insertdll(binarynode<type>* &start,int v)
{
    binarynode<int>* temp;
    temp=new binarynode<int>;
    temp->val=v;
    binarynode<type> *s;
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
void printlist(binarynode<type>* start)
{
  while(start!=NULL)
  {
    cout<<start->val<<" ";
    start=start->right;
  }
  return;
}
//-------------------------------------------------------------------------------------
template <typename type>
binarynode<type>* median_list(binarynode<type> *head)
{
  //  cout<<"-1\n";
    binarynode<type> *fast = head,*slow = head;
//    cout<<"0\n";
    while (slow->right && fast->right)
    {
        if(fast->right->right)
          fast = fast->right->right;
        else
          break;
        slow = slow->right;
    }
//    cout<<"1\n";
    if(fast->right)
    {
      binarynode<type> *temp = slow->right;
      slow->right = NULL;
//      cout<<"2\n";
      return temp;
    }
    else
    {
      binarynode<type> *temp = slow;
      slow->left->right = NULL;
//      cout<<"3\n";
      return temp;
    }

}


template <typename type>
void dll2bst(binarynode<type> *start,binarynode<type>*&root)
{
  if(start->left==NULL && start->right==NULL)
    {
      binarynode<int>* temp;
      temp=new binarynode<int>;
      temp->val=start->val;
    //  cout<<"insert in if"<<endl;
      insert(root,temp);
      return;
    }
  binarynode<int>* temp;
  binarynode<int>* second;
  temp=new binarynode<int>;
  second= new binarynode<int>;
//  cout<<"before median"<<endl;
  second=median_list(start);
//  cout<<"after median"<<endl;
  temp=second;
//  cout<<"value of median:"<<temp->val<<endl;
  second=second->right;
  second->left=NULL;
  insert(root,temp);

  dll2bst(start,root);
  dll2bst(second,root);
  return;


}





int main()
{

  binarynode<int>* root=NULL;
  binarynode<int>* start=NULL;

  insertdll(start,-7);
  insertdll(start,-6);
  insertdll(start,-3);
  insertdll(start,1);
  insertdll(start,4);
  insertdll(start,5);
  insertdll(start,8);
  cout<<"printing list...\n";
  printlist(start);
  cout<<"\n---------------\n";
  // inorder(root);
  // cout<<"------------------------------"<<endl;
  // preorder(root);
  // cout<<"------------------------------"<<endl;
  // postorder(root);
  //---------------------------------------dll to BST----------------------------------------
  dll2bst(start,root);

  //------------------------------------------------------------------------------------
  cout<<"Inorder---------------\n";
  inorder(root);
  return 0;
}

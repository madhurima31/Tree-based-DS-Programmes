#include<bits/stdc++.h>
using namespace std;


struct node{
int data;
struct node *left , *right;
};

struct node *LCA_BT(struct node *root,int n1,int n2)
{
   if(!root)
        return root;
   if(root->data==n1 || root->data ==n2)
        return root;
   struct node *leftLCA =LCA_BT(root->left,n1,n2);
   struct node *rightLCA=LCA_BT(root->right,n1,n2);
   if(leftLCA && rightLCA)
    return root;
   return (leftLCA?leftLCA:rightLCA);
}

struct node *newnode(int key)
{
    struct node *temp=new node;
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}


void inorder(struct node *root)
{
    if(root){
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}

int main()
{
    struct node *root=NULL;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->right->left=newnode(5);
     root->left->right=newnode(6);
    root->right->right=newnode(7);






    inorder(root);

    cout<<endl<<"Lowest common ancestor of 4 & 6 is :"<<LCA_BT(root,4,6)->data;

return 0;
}


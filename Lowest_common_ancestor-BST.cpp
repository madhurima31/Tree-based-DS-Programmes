#include<bits/stdc++.h>
using namespace std;


struct node{
int data;
struct node *left , *right;
};

struct node *LCA_BST(struct node *root,int n1,int n2)
{
    while(root){
        if(n1<root->data && n2<root->data)
            root=root->left;
        else if(n1>root->data && n2>root->data)
            root=root->right;
        else
            break;
    }

    return root;
}

struct node *newnode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root,int key)
{
    if(root==NULL){
      return  newnode(key);
    }
    else if(key<root->data)
       root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    return root;
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
    root=insert(root,20);
    insert(root,8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    inorder(root);

    cout<<endl<<"Lowest common ancestor of 10 & 14 is :"<<LCA_BST(root,10,14)->data;
    cout<<endl<<"Lowest common ancestor of 14 & 8 is :"<<LCA_BST(root,14,8)->data;

}

#include<bits/stdc++.h>
using namespace std;

struct node{
int key;
struct node *left , *right;
};

void inorder(struct node *root)
{
    if(root){
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}

struct node *newnode(int key)
{
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->key=key;
    root->left=root->right=NULL;
    return root;
};

struct node *insert(struct node *root,int key)
{
    if(root==NULL)
       return newnode(key);
    else if(key<root->key)
        root->left=insert(root->left,key);
    else if(key>root->key)
        root->right =insert(root->right,key);
    return root;
};

int main()
{
    struct node *root = NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    cout<<"inorder traversal of binary tree after insertion is :"<<endl;
    inorder(root);
}

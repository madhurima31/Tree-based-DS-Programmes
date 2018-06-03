#include<bits/stdc++.h>
using namespace std;

struct node{
int key;
struct node *left , *right;
};

struct node *convertBSTtoDLL(struct node *root)
{
    if(root->left){
        struct node *leftTree=convertBSTtoDLL(root->left);
        for(;leftTree->right!=NULL;leftTree=leftTree->right);
            leftTree->right=root;
            root->left=leftTree;

    }
    if(root->right){
        struct node *rightTree=convertBSTtoDLL(root->right);
        for(;rightTree->left;rightTree=rightTree->left);
        rightTree->left=root;
        root->right=rightTree;
    }

    return root;
};

void printDLL(struct node *root)
{
    struct node *temp=root;

            while(temp->left)
                {
                temp=temp->left;
                }

            while(temp){
                cout<<temp->key<<endl;
                temp=temp->right;
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

void inorder(struct node *root)
{
    if(root){
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}

int main()
{

    struct node *head, *root = NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout<<"inorder traversal of binary tree (in the form of linklist) :"<<endl;
    head=convertBSTtoDLL(root);
    printDLL(head);
}


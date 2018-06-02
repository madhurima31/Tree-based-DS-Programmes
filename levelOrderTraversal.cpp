#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node *left,*right;

};

void levelOrderTraversal(struct node *root)
{
    if(!root)
        return;
    queue<struct node *> q;
    q.push(root);
    while(!q.empty()){
        struct node *t=q.front();
        cout<<t->data;
        q.pop();
        if(t->left!=NULL)
            q.push(t->left);
        if(t->right!=NULL)
            q.push(t->right);
    }
}

struct node *newnode(int key)
{
    struct node *t=new node;
    t->data=key;
    t->left=t->right=NULL;
    return t;

};

int main()
{
    struct node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    levelOrderTraversal(root);
}


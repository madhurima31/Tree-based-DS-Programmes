#include<bits/stdc++.h>
using namespace std;

struct node{

int data;
struct node *left,*right;

};

struct node *newnode(int key)
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=key;
    node->left=node->right =NULL;
    return node;
};

struct node *insert(struct node *root,int key)
{
    if(root==NULL)
      return newnode(key);
    else if(key<root->data)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);
    return root;
};

int checkIdentical(struct node *t1,struct node *t2)
{
    if(!t1 && !t2)
        return 1;
    else{
        return (t1->data==t2->data && checkIdentical(t1->left,t2->left) && checkIdentical(t1->right,t2->right));
    }

}
int main()
{
    struct node *root1 =NULL;
    struct node *root2=NULL;
    root1=insert(root1,10);
    insert(root1,20);
    insert(root1,30);
    insert(root1,40);
    insert(root1,50);
    insert(root1,60);
    insert(root1,70);

    root2=insert(root2,10);
    insert(root2,20);
    insert(root2,30);
    insert(root2,40);
    insert(root2,50);
    insert(root2,60);
    insert(root2,80);

    checkIdentical(root1,root2)?cout<<"identical":cout<<"not identical";
return 0;

}

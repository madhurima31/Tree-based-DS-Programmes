#include<stdio.h>
#include<stdlib.h>

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

int sizeOfBT(struct node *t)
{
    return (t?(1+sizeOfBT(t->left)+sizeOfBT(t->right)):0);
}
int main()
{
    struct node *root =NULL;
    root=insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,40);
    insert(root,50);
    insert(root,60);
    insert(root,70);

    int size= sizeOfBT(root);
    printf("%d",size);

}

#include<stdio.h>
#include<stdlib.h>
#define M 3

struct Btree{
    int count;
    int key[M-1];
    struct Btree* child[M];
};

struct Btree* Create_A_Node(int x)
{
    struct Btree* temp=(struct Btree*)malloc(sizeof(struct Btree));
    temp->count=1;
    temp->key[M-1]={NULL};
    temp->key[0]=x;
    temp->child[0]=NULL;
    temp->child[1]=NULL;
    return temp;
}

struct Btree* Insert(struct Btree* root, int x)
{
    int i=0;
    if(root==NULL)
    {
        return Create_A_Node(x);
    }
    //if(root->count)

    while(i>M-2 && root->key[i]!=NULL)
    {
        if(x == root->key[i]) return root;
        else if(x < root->ley[i]) root->chlid[i]=Insert( root->child[i], x);
    }
}

int main()
{

    

    return 0;
}
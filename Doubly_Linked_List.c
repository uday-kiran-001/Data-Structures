//DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;
//INSERING NODE AT THE HEAD
void Insert_at_head(int x)
{
    struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
    if(head==NULL)
    {
        (*temp).data=x;
        (*temp).next=NULL;
        (*temp).prev=NULL;
        head=temp;
    }else{
    (*temp).data=x;
    (*temp).prev= NULL;
    (*temp).next=head;
    (*head).prev=temp;
    head=temp;
    }
}
//INSERTING NODE AT THE TAIL
void Insert_at_tail(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp1= head;
    while((*temp1).next!=NULL)
    {
        temp1=(*temp1).next;
    }
    (*temp).data=x;
    (*temp).next=NULL;
    (*temp).prev=temp1;
    (*temp1).next=temp;
}    
void Print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d", (*temp).data);
        temp=(*temp).next;
    }
    
}
int main ()
{
    head=NULL;
    Insert_at_head(5);
    Insert_at_head(4);
    Insert_at_head(9);
    Insert_at_tail(8);
    Print();
    return 0 ;
}
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
//Push function
void Push(int x)
{
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node*));
    (*temp).data=x;
    (*temp).next=NULL;
    if(head==NULL)
    {
        head=temp;
    }else{
        struct Node* temp1= head;
        while((*temp1).next!=NULL)
        {
            temp1=(*temp1).next;
        }
        (*temp1).next=temp;
    }
}
//Pop function
void Pop()
{
    struct Node* temp=head ,*temp1=(struct Node*)malloc(sizeof(struct Node*));
    while((*temp).next!=NULL)
    {   
        temp1=temp;
        temp=(*temp).next;
    }
    (*temp1).next=NULL;
    free(temp);

}

void Print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d \n", (*temp).data);
        temp=(*temp).next;
    }
}
int main ()
{
    head=NULL;
    Push(5);  Print();
    Push(6); Print();
    Push(9);Print();
    Pop();Print();


    return 0;
}
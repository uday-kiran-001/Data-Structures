//LINKED LISTS

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
//DEECLARING HEAD AS A GLOBAL VARIABLE
struct Node* head;
//INSERTING FUNCTION
void Insert(int x, int p)
{
    struct Node* temp =( struct Node*)malloc(sizeof(struct Node));
    (*temp).data=x;
    (*temp).next=NULL;
    int i;
    if(p==1)
    {
        (*temp).next= head;
        head=temp;
    }else{
    struct Node* temp1= head;
    for(i=0;i<p-2;++i)
    {
        temp1=(*temp1).next;
    }
    (*temp).next= (*temp1).next;
    (*temp1).next=temp;

    }
} 
//NORMAL PRINT FUNCTION  
void Printf()
{
    struct Node* temp3= head;
    while(temp3!=NULL)
    {
        printf("%d ", (*temp3).data);
        temp3=(*temp3).next;
    }
    printf("\n");
}
//NORMAL PRINTING USING RECURSION
void Print_Using_Recursion(struct Node* p)
{
    if(p==NULL)
    {
       return ;
    }else{
        printf("%d ", (*p).data);
        Print_Using_Recursion((*p).next);
        
    }
}
//REVERSING USING ITERATION
//HERE THE NODE IS COMPLETELY REVERSED
void Reverse()
{
    struct Node *current, *prev, *next;
    current= head;
    prev=NULL;
    while(current!= NULL)
    {
        next= (*current).next; 
        (*current).next= prev;
        prev= current;
        current=next;
    }
    head=prev;
}
//REVERSING THE LINKS USING RECURSION
void Reverse_Using_Recursion(struct Node* HEAD)
{
    struct Node* temp=HEAD;
    if(temp->next==NULL)
    {
        head=temp;
        return;
    }else{
        Reverse_Using_Recursion(temp->next);
        (temp->next)->next=temp;
        temp->next=NULL;
    }
}

//REVERSING USING RECURSION
//HERE THE NODE IS NOT REVERSED, JUST THE NODE IS PRINTED FROM THE BACK ONWARDS
void Reversing_Using_Recursion(struct Node* temp)
{
    if(temp==NULL)
    {
        return;
    }else{
        Reversing_Using_Recursion((*temp).next);
        printf("%d ",(*temp).data);
    }
}
// For counting the position of the given value
int count(int x)
{
    struct Node* temp=head;
    int count=0, flag=0;
    while(temp!=NULL)
    {
        if((temp->data)==x)
        {
            count++;
            flag=1;
            break;
        }else{
            temp=temp->next;
            count++;
        }
    }
    if(flag==0)
    {
        return 0;
    }else{
        return count;
    }
}
//Swapping Nodes
void Swap(int x1,int x2)
{
    struct Node *prev1,*current1,*next1;
    struct Node *prev2,*current2,*next2;
    prev1=NULL; prev2=NULL;
    current1 =head; current2=head;
    next1=head->next;  next2=head->next;
    int p1=count(x1);
    int p2=count(x2);
    if(p1!=0 && p2!=0 )
    {
        for(int i=0;i<p1-1;++i)
        {
            if(next1!=NULL)
            {
            prev1=current1;
            current1=next1;
            next1=next1->next;
            }
        }
        for(int i=0;i<p2-1;++i)
        {
            if(next2!=NULL)
            {
            prev2=current2;
           current2=next2;
           next2=next2->next;
            }
        }
        if(prev1==NULL)
        {
            if( (p2-p1)==1 )
            {
                current2->next=current1;
                current1->next=next2;
                head=current2;
            }else{
                current2->next=next1;
            current1->next=next2;
            head=current2;
            prev2->next=current1;
            }
        }else if(prev2==NULL)
        {
            if( (p1-p2)==1 )
            {
                current1->next=current2;
                current2->next=next1;
                head=current1;
            }else{
                current2->next=next1;
                current1->next=next2;
                prev1->next=current2;
                head=current1;
            }
        }else if( (p1-p2)==1 || (p2-p1)==1 )
        {
            if((p1-p2)==1)
            {
                current1->next=prev1;
                current2->next=next1;
                prev2->next=current1;
            }else{
                current2->next=prev2;
                current1->next=next2;
                prev1->next=current2;
            }
        }else{
            current2->next=next1;
            current1->next=next2;
            prev1->next=current2;
            prev2->next=current1;
        }
        printf("After Swapping:\n");
    }else{
        printf("Entered element (or) elements are not present\n");
    }
}



int main()
{  
    head=NULL;
    int n;
    Insert(3,1);  Printf();
    Insert(2,2);  Printf();
    Insert(5,1);  Printf();
    Insert(7,3); Print_Using_Recursion(head);
    printf("\nHere the node is completely reversed:\n");
    Reverse();
    Printf();
    Print_Using_Recursion(head);
    printf("\n");
    printf("Here the node is just printed from behind:\n");
    Reversing_Using_Recursion(head);
    printf("\nHere the Links are reversed Using Recursion !!!!!\n");
    Reverse_Using_Recursion(head);
    Printf();
    
    return 0;
}

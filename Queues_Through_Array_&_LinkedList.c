#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// FOR QUEUE USING ARRAY
// MAKING FRONT AND REAR AS GLOBAL VARIABLES, SO THAT WE CAN CHANGE BOTH AT A TIME IF NEEDED
// BECAUSE SOMTIMES BOTH FRONT AND REAR ARE UPDATED AND A FUNCTION CANNOT RETURN 2 VALUES 

int front=-1;
int rear=-1;


struct Node* Create_A_Node(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}
struct Node* Enqueue_With_Linked_List(struct Node* tail, int x)
{
    if(tail==NULL)
    {
        tail=Create_A_Node(x);
    }else{
        tail->next=Create_A_Node(x);
        tail=tail->next;
    }
    return tail;
}

struct Node* Dequeue_With_Linked_List(struct Node* head)
{
    if(head==NULL) return NULL;
    else 
    {
        struct Node* temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
}

void Front_Element_With_Linked_List(struct Node* head)
{
    printf("%d\n", head->data);
}

void Enqueue_With_Array(int* arr, int n,int x)
{
    if(front==(rear+1)%n)
    { 
        printf("OVERFLOW.............\n");
    }
    else if(rear==-1 ){        // INTIAL CASE, BOTH FRONT=0 AND REAR=0 NOW
        rear=rear+1; arr[rear]=x;
        front=rear;
    }else {
        rear=(rear+1)%n;
        arr[rear]=x;
    }

}

void Dequeue_With_Array(int* arr, int n)
{
    if(front==-1) printf("Underflow.....\n");
    else if(front==rear){ front=-1;rear=-1;}
    else front=front+1;
}


int main()
{  
    /*
    struct Node* head=NULL;
    struct Node* tail=NULL;
    tail=Enqueue_With_Linked_List(tail,5);
    head=tail;
    tail=Enqueue_With_Linked_List(tail,1);   head=Dequeue_With_Linked_List(head);   
    Front_Element_With_Linked_List(head);
    tail=Enqueue_With_Linked_List(tail,6);   Front_Element_With_Linked_List(head);
    tail=Enqueue_With_Linked_List(tail,7);   Front_Element_With_Linked_List(head);
    tail=Enqueue_With_Linked_List(tail,7);   Front_Element_With_Linked_List(head);    
    head=Dequeue_With_Linked_List(head);     Front_Element_With_Linked_List(head);
    tail=Enqueue_With_Linked_List(tail,1);   Front_Element_With_Linked_List(head);
    tail=Enqueue_With_Linked_List(tail,3);   Front_Element_With_Linked_List(head);

    */

    int n;
    printf("Eenter the size of the QUEUE: ");
    scanf("%d", &n);
    int* arr=(int*)malloc(sizeof(int)*n);
    Dequeue_With_Array(arr, n);
    Enqueue_With_Array(arr, n,1);   Dequeue_With_Array(arr, n);
    Enqueue_With_Array(arr, n,6);   Dequeue_With_Array(arr, n);
    Enqueue_With_Array(arr, n,7);   printf("%d\n", arr[front]);
    Enqueue_With_Array(arr, n,8);   
    Enqueue_With_Array(arr, n,9);   printf("%d\n", arr[front+2]);

    free(arr);
    arr=NULL;
    return 0;
}
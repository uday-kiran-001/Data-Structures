#include<stdio.h>
#include<stdlib.h>

struct Graph_Node{
    int data;
    struct Graph_Node* next;
};

struct Graph_Node*(int x)
{
    struct Graph_Node* temp=(struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

int main()
{
    int n;
    printf("Enter the number of nodes u create: ");
    scanf("%d", &n);
    int* arr=(int*)malloc(sizeof(int)*n);



    free(arr);
    arr=NULL;
    return 0;
}
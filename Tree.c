#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

// CREATING A NEW NODE WITH GIVEN DATA
struct Tree* Create(int x)
{
    struct Tree* temp=(struct Tree*)malloc(sizeof(struct Tree));
    temp->data=x;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

//INSERTING THE DATA ACCORDING TO BINARY SEARCH TREE
struct Tree* Insert(struct Tree* temp, int x)
{
    if(temp==NULL) { temp=Create(x); return temp;  }
    else if(x<=temp->data) temp->left= Insert(temp->left, x);
    else temp->right= Insert(temp->right, x);
    return temp;
}

// SEARCHING FOR AN ELEMENT IN THE BinarySearchTree
int BSearch(struct Tree* temp, int x)
{
    if(temp==NULL) return 0;
    else if(temp->data==x) return 1;
    else if(x<=temp->data) return BSearch(temp->left, x);
    else return BSearch(temp->right, x);
}


// PRINTING USING PREORDER TRAVERSAL ( <root><left><right> )
void Preorder(struct Tree* temp)
{
    if(temp==NULL) return ;
    printf("%d ", temp->data);
    Preorder(temp->left);
    Preorder(temp->right);
}

// PRINTING USING INORDER TRAVERSAL ( <left><root><right> )
void Inorder(struct Tree* temp)
{
    if(temp==NULL)  return;
    Inorder(temp->left);
    printf("%d ", temp->data);
    Inorder(temp->right);
}

// PRINTING USING POSTORDER TRAVERSAL ( <left><right><root> )
void PostOrder(struct Tree* temp)
{
    if(temp==NULL)  return ;
    PostOrder(temp->left);
    PostOrder(temp->right);
    printf("%d ", temp->data);
}

// FINDING THE MINIMUM NUMBER IN THE ENTIRE TREE
void Print_Min(struct Tree* temp)
{
    if(temp->left==NULL) printf("\nMin= %d\n", temp->data);
    else Print_Min(temp->left);
}

// FINDING THE MAXIMUM ELEMENT IN THE ENTIRE BinarySearchTree
void Print_Max(struct Tree* temp)
{
    if(temp->right==NULL) printf("\nMax= %d\n", temp->data);
    else Print_Max(temp->right);
}

// FINDING THE HEIGHT OF THE GIVEN NODE  ( IF U KNOW THE ADDRESS OF ANY NODE, U CAN GET IT'S
//                                          HEIGHT BY SUBSTITUTING ITS ADDRESS IN THE FUNCTION )
int Find_Height_Of_Tree(struct Tree* temp)
{
   if(temp==NULL) return -1;
   int LeftHeight=Find_Height_Of_Tree( temp->left);
   int RightHeight=Find_Height_Of_Tree(temp->right);

   if(LeftHeight >=RightHeight)
   {
       return (LeftHeight+1);
   }else
   { return (RightHeight+1); }
}


int Check_If_Given_Tree_Is_BinarySearchTree(struct Tree* temp, int LowerB,int  UpperB)
{
    if(temp==NULL) return 1;
    else if( temp->data>UpperB || temp->data<LowerB   ) return 0;
    else {
        int x1=  Check_If_Given_Tree_Is_BinarySearchTree(temp->left, LowerB, temp->data);
        int x2=  Check_If_Given_Tree_Is_BinarySearchTree(temp->right, temp->data, UpperB);
        if(x1>=x2) return x2;
        else return x1;
    }

}

int Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__1(struct Tree* temp)
{
    int prev;
    if(temp==NULL) return 1;
    prev= Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__1( temp->left);
    if(temp->left==NULL) prev=temp->data;
    else if( prev>temp->data ) prev=-100;  //  I RANDOMLY KEPT -100, U CAN KEEP ANYTHING OR TRY NEWLY 
    else prev=temp->data; 
    if(temp->right!=NULL && prev!=-100)
    {
        prev= Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__1( temp->right);
    }
    return prev;
}

int Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__2(struct Tree* temp)
{
    static struct Tree* prev=NULL;
    if(temp)
    {
        if(!Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__2(temp->left)) return 0;
        if(prev!=NULL && prev->data>=temp->data) return 0;
        prev=temp;
        return Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__2(temp->right);
    }
    else return 1;
}

/*
struct Tree* Search_For_Address_Of_Above_Node_For_the_Given_Element(struct Tree* temp, int x)
{
    if(temp==NULL) return 0;
    else if(temp->left->data==x || temp->right->data==x ) return temp;
    else if(temp->data==x) return temp;
    else if (x<=temp->data) return Search_For_Address_Of_Above_Node_For_the_Given_Element(temp->left, x);
    else return Search_For_Address_Of_Above_Node_For_the_Given_Element(temp->right, x);
}
*/
struct Tree* Delete_A_Node(struct Tree* temp, int x)
{
    if(temp==NULL) return temp;
    else if( x<temp->data) temp->left=Delete_A_Node(temp->left, x);
    else if( x> temp->data) temp->right=Delete_A_Node(temp->right, x);
    else{
        if(temp->right==NULL && temp->left==NULL)
        {
            free(temp);
            temp=NULL;
        }else if( temp->left==NULL)
        {
            struct Tree* temp1=temp;
            temp=temp->right;
            free(temp1);
            temp1=NULL;
        }else if( temp->right==NULL)
        {
            struct Tree* temp1=temp;
            temp=temp->left;
            free(temp1);
            temp1=NULL;
        }else {
            struct Tree* temp3=temp->left;
            struct Tree* temp1=temp;
            while(temp3->right!=NULL)
            {
                temp3=temp3->right;
            }
            temp3->right=temp->right;
            temp=temp->left;
            free(temp1);
            temp1=NULL;
        }
    }
    return temp;
}

int Inorder_Successor(struct Tree* temp, int x)
{
    if(temp==NULL) return 0;
    else if( temp->left!=NULL && temp->right!=NULL )
    {
        if( (temp->left)->data==x || (temp->right)->data==x ) return temp->data;
        else if( x<= temp->data) return Inorder_Successor(temp->left, x);
        else  return Inorder_Successor(temp->right, x);
       
    }else if( temp->right==NULL && temp->left!=NULL )
    {
        if( (temp->left)->data==x )return temp->data;
        else if( x<= temp->data) return Inorder_Successor(temp->left, x);
        else  return Inorder_Successor(temp->right, x);
    }else if( temp->right!=NULL && temp->left==NULL  )
    {
        if( (temp->right)->data==x )return temp->data;
        else if( x<= temp->data) return Inorder_Successor(temp->left, x);
        else  return Inorder_Successor(temp->right, x);
    }
    else return 0;
}

void Delete_Tree(struct Tree* head)
{
    //struct Tree* temp=head;
    if(head==NULL) return ;
    Delete_Tree((head->left));
    Delete_Tree((head->right));
    //printf("Deleting : %d\n", head->data);
    free(head);
}


 
int main()
{
    struct Tree* head=NULL;
    head=Insert(head, 9);
    head=Insert(head, 5);
    head=Insert(head, 4);
    head=Insert(head, 2);
    head=Insert(head, 3);
    head=Insert(head, 6);
    head=Insert(head, 7);
    head=Insert(head, 10);
    head=Insert(head, 8);

    if(BSearch(head, 1))
    {
        printf("Present SIR !!!!!!\n");
    }else
    {
        printf("No SIR !!!!!!\n");
    } 
    
    Print_Min(head);
    Print_Max(head);

    int height=Find_Height_Of_Tree(head);
    printf("The height of the Binary Search Tree is %d\n", height);

    printf("Printing the Tree Using Preorder Traversal: ");
    Preorder(head);   printf("\n");

    printf("Printing the Tree Using Inorder Traversal: ");
    Inorder(head);    printf("\n");

    printf("Printing the Tree Using PostOrder Traversal: ");
    PostOrder(head);   printf("\n");

    //(head->right)->left=Create(11);  // ADDING SOME NUMBER TO CHECK THE BELOW FUNCTION WORKING OR NOT

    printf("Checking whether the Given Tree is Binary Search Tree or not....\n");
    if(  Check_If_Given_Tree_Is_BinarySearchTree(head, -100, 100)  ) printf("YAYYY\n");
    else printf("No......\n");

    head=Delete_A_Node(head, 6);
    printf("The above given node is deleted succesfully!!!!!!!!!!!!!\n");
    printf("Printing the Tree Using Inorder Traversal: ");
    Inorder(head);    printf("\n");

    printf("Checking whether the Given Tree is Binary Search Tree or not through Inorder Traversal METHOD (1)....\n");
    if (   Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__1(head)!=-100   ) printf("YAYYY\n");
    else printf("No......\n");

    printf("Checking whether the Given Tree is Binary Search Tree or not through Inorder Traversal METHOD (2)....\n");
    if (   Checking_If_Given_Tree_Is_BinarySearchTree___Through_Inorder_Traversal__2(head)==1  ) printf("YAYYY\n");
    else printf("No......\n");

int x=Inorder_Successor(head, 2);
    if(x==0)printf("Element not present   OR   you you had entered head node, which don't have any successor\n");
    else printf("The Inorder Successor of given above element = %d\n", x);

    Delete_Tree(head);  // ONE CALL, DELETES WHOLE LEFT SIDE OF TREE 
                        // YOU CAN CHECK BY CALL IT ONE TIME
                        // AND DONT KEEP HEAD=NULL AND NOW PRINT SOME HEAD->RIGHT->DATA
                        // YOU CAN STILL ACCESS THAT ELEMENT  

                        //  Y DUDE ????????????????

       /// IDIOT !!!!!!!!!!  USE STACK TO DELETE THE TREE !!!!!!!!!!!!   WASTE FELLOW                

    Delete_Tree(head);  // SO USING TWICE, SO NOW ALREADY WHOLE LEFT SIDE IS DELETED SO IT WILL GO TO RIGHT
    head=NULL;

    return 0;
}
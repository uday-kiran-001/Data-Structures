#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct Node{
    char data;
    struct Node* next;
};

struct Node* Create_A_Node(char x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

struct Node* Push(struct Node* temp, char x)
{
    struct Node* temp1=Create_A_Node(x); 
    if(temp==NULL) return temp1;
    else{ temp1->next=temp; return temp1;}
}

struct Node* Pop(struct Node* temp)
{
    if(temp==NULL){    printf("Underflow.......\n"); return 0;   }
    else{ struct Node* temp1=temp;
    temp=temp->next;
    free(temp1);
    temp1=NULL;
    return temp;}
}

char Top(struct Node* temp)
{
    if(temp!=NULL) return temp->data;
}
    

int IsEmpty(struct Node* temp)
{
    if(temp==NULL){ printf("Empty\n"); return 1;}
    else return 0;
}

int Is_Operand(char x)
{
    if( x-'0'>=0 && x-'0'<= 9) return 1;
    else return 0;
}

int Is_Operator(char x)
{
    if( x=='+' || x=='-' || x=='/' || x=='*' || x=='^' || x=='(' || x==')' ) return 1;
    else return 0;
}

int Weight(char x)
{
    switch(x)
    {
        case '(': return 0;
        case ')': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    } 
}

int Has_Higher_Preccedence(char x1, char x2)
{
    int weight1=Weight(x1);
    int weight2=Weight(x2);
    if(weight1>weight2 )return 1;
    else return 0;
}

char Perform_Operation(char ch1,char ch2, char Operator)
{
    int x1=ch1-'0';
    int x2=ch2-'0';
    printf("x1= %d   x2=%d\n", x1, x2);
    switch(Operator)
    {
        case '+': return (x2+x1+'0' );
        case '-': return (x2-x1+'0' );
        case '*': return (x2*x1+'0' );
        case '/': return (x2/x1+'0' );
        case '^': return (pow(x2,x1)+'0');
    }
}

char* Infix_to_Postfix(char* Infix, char* P, struct Node* top)
{
    int i, t=0;
    for(i=0;i<strlen(Infix); ++i)
    {
        if( Is_Operand(Infix[i]))
        {
            int x=Infix[i]-'0';
            if( (i+1)<strlen(Infix) )
            {
                while( !Is_Operator(Infix[i+1])  && (i+1)<strlen(Infix) )
                {
                    P[t++]=Infix[i];
                    i++;
                }
                P[t++]=Infix[i] ;
                P[t++]=' ';
            }else{ 
                P[t++]=x+'0';
            }
        }
        else if( Is_Operator(Infix[i]) )
        {
            if(IsEmpty(top) ) top=Push(top, Infix[i]);
            else if(Infix[i]=='(') top=Push(top, Infix[i]);
            else if(Infix[i]==')') 
            {
                while( !IsEmpty(top) && Top(top)!='(')
                {
                    P[t++]=Top(top);
                    top=Pop(top);
                }
                top=Pop(top);
            }
            else if( !IsEmpty(top) && Has_Higher_Preccedence(Infix[i], Top(top) ) ) top=Push(top,Infix[i]);
            else {
                while( !IsEmpty(top) && Top(top)!='(' && !Has_Higher_Preccedence(Infix[i], Top(top) ))
                {
                    P[t++]=Top(top);
                    top=Pop(top);
                }
                top=Push(top, Infix[i]);
            }
        }
    }
    while( !IsEmpty(top) )
    {
        P[t++]=Top(top);
        top=Pop(top);
    }
    P[t]='\0';
    if( top!=NULL ){ printf("Expression is not balanced\n"); return 0;}
    else return P;
}


int Evaluation_Of_Postfix(char* P, struct Node* top)
{
    int i;
    for(i=0;i<strlen(P);++i)
    {
        if( P[i]==' ' ) continue;
        else if( Is_Operand(P[i]) )
        {
            int x=P[i]-'0';
            while( P[i+1]!=' ' && !Is_Operator(P[i+1]))
            {
                printf("YAY\n");
                i++;
                int y=P[i]-'0';
                x=x*10+ y;
            }
            printf("x= %d\n", x);
            printf("x in C= %c\n", x+'0');
            top=Push(top, x+'0');
        } 
        else if( Is_Operator(P[i]) )
        {
            char ch1, ch2,ch3;
            ch1=Top(top);
            printf("ch1= %c\n", ch1);
            top=Pop(top);
            ch2=Top(top);
            printf("ch2= %c\n", ch2);
            top=Pop(top);
            ch3=Perform_Operation(ch1,ch2, P[i]);
            printf("ch1+ch2 in C = %c\n", ch3);
            top=Push(top, ch3);
        } 
    }
    int Result=( Top(top)-'0');
    return Result;
}


void Delete_LinkedList(struct Node* temp)
{
    while(temp!=NULL)
    {
        struct Node* temp1=temp;
        temp=temp->next;
        free(temp1);
        temp1=NULL;
    }
}

int main()
{
    struct Node* top=NULL;
    char* Infix=(char*)malloc(sizeof(char)*20);
    char* Postfix=NULL;
    Postfix=(char*)malloc(sizeof(char)*20);
    printf("Enter the Infix expression: ");
    scanf("%s", Infix );       /////// Check the function 
    printf("Infix= %s\n", Infix);
    Postfix=Infix_to_Postfix(Infix, Postfix, top);
    printf("Postfix= %s\n", Postfix);

    int Result=Evaluation_Of_Postfix(Postfix, top);
    printf("Result= %d\n", Result);


    free(Infix);    Infix=NULL;
    free(Postfix);  Postfix=NULL;
    Delete_LinkedList(top); top=NULL;

    return 0;
}
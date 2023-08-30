#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

int Max_Seats=2;

struct Departure_Node{
   // char* Flight_Num;
    char* Departure;
    //char* Destination;
    struct  Destination_Node* next; 
};

struct Destination_Node{
    //char* Timing;
    int seats;
    char* Destination;
    struct Passengers* down;
    struct Destination_Node* next;
};

struct Passengers{ 
    char* name;
    char* Date;
    char Cabin;
    int Seat_num;
    ///////////////
    int age;
    int num_of_people;
    int Total_amt;
    //int return_type;
    struct Passengers* down;
};

struct Departure_Node* Create_A_Departure_Node(char* Depart)
{
    ///, char* FlightNum
    struct Departure_Node* temp=(struct Departure_Node*)malloc(sizeof(struct Departure_Node));
    //temp->Flight_Num=FlightNum;
    temp->Departure=Depart;
    temp->next=NULL;
    return temp;
}

struct Destination_Node* Create_A_Destination_Node(char* destination)
{
   // char* Time=Generate_Time();
    struct Destination_Node* temp=(struct Destination_Node*)malloc(sizeof(struct Destination_Node));
    //temp->Timing=Time;
    temp->seats=Max_Seats;
    temp->Destination=destination;
    temp->down=NULL;
    temp->next=NULL;
    return temp;
}

struct Passengers* Create_Passanger_Node(char* Name,char* Date,char Cabin,int Seat_num,int age,int Total)
{  
    struct Passengers* temp=(struct Passengers*)malloc(sizeof(struct Passengers));
    temp->age=age;
    temp->Cabin=Cabin;
    temp->Date=Date;
    temp->name=Name;
    temp->Seat_num=Seat_num;
    temp->Total_amt=Total;
    temp->down=NULL;
    return temp;
}

int Assign_Imaginary_Distance_for_Pricing(char* Start, char* End)
{
    int hs=strcmp(Start,"Hyderabad");       int he=strcmp(End,"Hyderabad");  
    int ms=strcmp(Start,"Mumbai");          int me=strcmp(End,"Mumbai");          
    int ds=strcmp(Start,"Delhi");           int de=strcmp(End,"Delhi");
    int cs=strcmp(End,"Chennai");           int ce=strcmp(End,"Chennai");
    int bs=strcmp(Start,"Banglore");        int be=strcmp(End,"Banglore");

    if(hs==0 || he==0)
    {
        if(cs==0 || ce==0 || bs==0 || be==0) return 1;
        
    }
    if(ms==0 || me==0)
    {
        if(hs==0 || he==0 || ds==0 || de==0) return 2;
    }
    if( ds==0 || de==0)
    {
        if(hs==0 || he==0 ||cs==0 || ce==0 || bs==0 || be==0)
        {
            return 3;
        }
    }
}

int Assign_Price(char* Departure, char* Destination)
{
    int x=Assign_Imaginary_Distance_for_Pricing( Departure ,  Destination );
    int sum;
    srand(time(0));
    if(x==1)
    {
        sum=2500+ ( rand() )%1000; 
    }else if(x==2)
    {
        sum=4500+ ( rand() )%1000; 
    }else{
        sum=7500+ ( rand() )%1000; 
    }
    return sum;
}

int Price_According_to_Cabin(char* Departure, char* Destination, char Cabin)
{
    int price=Assign_Price( Departure,Destination);
    if(Cabin=='B')
    {
        price=price+3000;
    }else if(Cabin=='F')
    {
        price=price+1500;
    }
    return price;
}

char* Assign_Place(int x)
{
    char* Place=(char*)malloc(sizeof(char)*15);
    switch(x)
    {
        case 1:Place="Hyderabad";   break;
        case 2:Place="Chennai";     break;
        case 3:Place="Banglore";    break;
        case 4:Place="Mumbai";      break;
        case 5:Place="Delhi";       break;
        default:Place=NULL;         break;
    }
    return Place;
}

void Print_Ticket(struct Passengers* node)
{
    
    printf("#  NAME                 :  %s\n", node->name);
    printf("#  AGE                  :  %d\n", node->age);
    printf("#  DATE OF DEPARTURE    :  %s\n", node->Date);
    //printf("#  FLIGHT FROM %s  to  %s\n", dep->Departure, desti->Destination);
    printf("#  CABIN                :  %c\n", node->Cabin);
    printf("#  SEAT NUMBER          :  %dAGE\n", node->Seat_num);
 // printf("#  NUMBER OF PEOPLE     :  %d\n", node->num_of_people);
    printf("#  TOTAL AMOUNT PAID    :  %d\n", node->Total_amt);
}

struct Destination_Node* Get_the_main_head_Address_of_Passenger(struct Departure_Node** root, int seat_num )
{
    int x, y;
    char* Destination=NULL;
    x=seat_num/100;
    y=seat_num/10-x*10;
    Destination=Assign_Place(y);
    struct Departure_Node* dep=root[x-1];
   // printf("\n  1   \n");
    if(dep)
    {
       // printf("\n  2   \n");
        struct Destination_Node* desti=dep->next;
        int flag=0;
        while(desti)
        {
           // printf("\n  3   \n");
            if(strcmp(desti->Destination, Destination))
            {
                desti=desti->next;
             //   printf("\n  4   \n");
            }else{
                flag=1;
             //   printf("\n  5   \n");
                break;
            }
        }
      //  printf("\n  6   \n");
        if(flag)
        {
          //  printf("\n  7   \n");
            return desti;
        }else{
            printf("\nYOU HAVE ENTRED WRONG DETAILS !!!!!!\n\n");
            return 0;
        }
    }else{
        printf("\nYOU HAVE ENTRED WRONG DETAILS !!!!!!\n\n");
        return 0;
    }
    printf("\n  Done   \n");

}

void Cancel_the_Ticket(struct Departure_Node** root )
{   
    int s, t, l;
    printf("\nENTER YOUR FIRST 3 NUMERIC DIGITS OF YOUR SEAT NUMBER TO CANCEL THE TICKET: ");
    scanf("%d",&s);
    struct Passengers* node=NULL;
    struct Passengers* prev=NULL;
    struct Destination_Node* desti=Get_the_main_head_Address_of_Passenger(root, s );
    ///printf("\n  Got Desti   \n");
    if(desti)
    {  // printf("\n  Desti not 0   \n");
        l=s/10;
        t=(Max_Seats+1)-(s-l*10);
        if(t>Max_Seats || t<=0) {
            printf("\nYOU HAVE ENTRED WRONG DETAILS !!!!!!\n\n");
            return;
        }
        node=desti->down;
      //  printf("%d\n", node->Seat_num);
        if(node->Seat_num==s) 
        {
        //    printf("\n  1st node  \n");
            desti=node->down;
            free(node);     node=NULL;
            printf("\nSUCCESS !!!! TICKET IS CANCELLED\n70%c OF THE AMOUNT PAID WILL BE CREDITED SOON\n\n", '%');
        }else if(desti->down->down==NULL  && node->Seat_num!=s)
        {
            printf("\nYOU HAVE ENTRED WRONG DETAILS !!!!!!\n\n");
            return;
        }
        else{
          //  printf("\n  some node   \n");
            while(t>0 &&  node->Seat_num!=s)
            {   
                //printf("%d\n", node->Seat_num);
                prev=node;
                node=node->down;
                t--;
            }
            prev->down=node->down;
            free(node);     node=NULL;
            printf("\nSUCCESS !!!! TICKET IS CANCELLED\n70%c OF THE AMOUNT PAID WILL BE CREDITED SOON\n\n", '%');
        }
        
    }

}

struct Departure_Node** Book_Ticket(struct Departure_Node** root)
{
    
    int x, y, t;
    int price;
    int age;
    char* Departure=NULL;
    char* Destination=NULL;
    char* Date=(char*)malloc(sizeof(char)*10);
    char Cabin;
    int Seat_num=0;
    char* name=(char*)malloc(sizeof(char)*15);


    
    printf("\nSELECT THE DEPARTURE PLACE:\n\n");
    printf("1. Hyderabad    -Enter 1\n");
    printf("2. Chennai      -Enter 2\n");
    printf("3. Banglore     -Enter 3\n");
    printf("4. Mumbai       -Enter 4\n");
    printf("5. Delhi        -Enter 5\n");
    scanf("%d", &x);
    Departure=Assign_Place( x);
    if(root[x-1]==NULL)
    {
        printf("NULL\n");
        root[x-1]=Create_A_Departure_Node(Departure);
    }

    printf("\nSELECT THE DESTINATION PLACE:\n\n");
    printf("1. Hyderabad    -Enter 1\n");
    printf("2. Chennai      -Enter 2\n");
    printf("3. Banglore     -Enter 3\n");
    printf("4. Mumbai       -Enter 4\n");
    printf("5. Delhi        -Enter 5\n");
    scanf("%d", &y);
    Destination=Assign_Place( y);
    struct Destination_Node* temp=root[x-1]->next;
    struct Destination_Node* temp1_root=NULL;
    struct Destination_Node* prev=NULL;
    int flag=0;
    if(temp==NULL)
    {
        temp1_root=Create_A_Destination_Node(Destination);
        root[x-1]->next=temp1_root;
    }else{
        while(temp!=NULL )
        {
            if(strcmp(temp->Destination, Destination))
            {
                prev=temp;
                temp=temp->next;
            }else{
                flag=1;
                break;
            }
        }
        if(flag)
        {
            temp1_root=temp;
        }else{
            temp1_root=Create_A_Destination_Node(Destination);
            prev->next=temp1_root;
        }

    }
    int k=Max_Seats-temp1_root->seats+1;
    if(k>Max_Seats)
    {
        printf("\nSORRY........... PLANE IS FILLED\n\n");
        return root;
    }

    
    printf("ENTER THE DATE IN THE FORMAT ( DD/MM/YYYY ): ");
    scanf("%s", Date);

    printf("\n\nSELECT    THE    CABIN:\n\n");
    printf("1. Business     - Enter - B ( USE CAPITAL LETTER )\n");
    printf("2. First        - Enter - F ( USE CAPITAL LETTER )\n");
    printf("3. Economic     - Enter - E ( USE CAPITAL LETTER )\n\n********************************\n");
    printf("NOTE  : USE    CAPITAL    LETTER\n********************************\n");
    scanf(" %c", &Cabin);

    
    price=Price_According_to_Cabin( Departure, Destination, Cabin);
    printf("\nPRICE OF THE TICKET = %d\n\n", price);

    printf("ENTER THE NAME: ");
    scanf(" %[^\n]s", name);
    printf("ENTER YOUR AGE: ");
    scanf("%d", &age);
    

    //printf("FLIGHTS    AVAILABLE    ARE: \n");
    //printf("TIME            : %s\n", temp1_root->Timing);

    printf("\nENTER 1 TO CONFIRM THE BOOKING\nELSE 0 TO CANCEL THE BOOKING: ");
    scanf("%d", &t);
    if(t)
    {   
        Seat_num=(x*10+y)*10+k;
        temp1_root->seats=temp1_root->seats-1;
        struct Passengers* new_node=Create_Passanger_Node(name, Date, Cabin,Seat_num,age, price);
        if(temp1_root->down)
        {
            struct Passengers* first_node=temp1_root->down;
            new_node->down=first_node;
            temp1_root->down=new_node;
        }else{
            temp1_root->down=new_node;
        }
        printf("\nSUCCESSFULLY TICKET BOOKED !!!!!!!!!!!\n\n");
        printf("PLEASE WAIT, PRINTING THE TICKET............\n\n");
        Print_Ticket(new_node);
    }

    Departure=NULL;
    Destination=NULL;
    Date=NULL;
    name=NULL;

    return root;
}

int main()
{
    struct Departure_Node** root=(struct Departure_Node*)malloc(sizeof(struct Departure_Node* )*5); 
    for(int i=0;i<5;++i) root[i]=NULL;

    int a, t=1;

    printf("\t\t\t\t\t\t\tWELCOME");
    while(t)
    {
        printf("\n\nENTER THE NUMBER FOR THE SERVICE YOU NEED:\n");
        printf("1. BOOK A TICKET                - ENTER 1\n");
        printf("2. CANCEL THE TICKET            - ENTER 2\n");
        scanf("%d", &a);

        switch(a)
        {
            case 1:root= Book_Ticket(root);                 break;
            case 2:Cancel_the_Ticket(root );                break;
        }

        printf("\n\nENTER 0 TO EXIT THE CODE\nOR 1 TO CONTINUE TO HOME SCREEN: ");
        scanf(" %d", &t);
    }

    // FOR TESTING WETHER THE REQIURED DATA IS FORMED ACCORDINGLY OR NOT

  /*  printf("\ndept= %s", root[0]->Departure);
    printf("\n 1 ");
    struct Destination_Node* desti=root[0]->next;
    printf("\ndesti= %s", desti->Destination);
    printf("\n 2 ");
    printf("\npass 1= %s", desti->down->name);
    printf("\n 3 ");
    printf("\npass 2= %s\n",desti->down->down->name);

    */
    
    return 0;
}
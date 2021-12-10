#include<stdio.h>
#include<conio.h>

int max=100;
int Q[100];
int FRONT=-1, REAR=-1;
void insert_r(void);
void insert_f(void);
void delete_r(void);
void delete_f(void);
void display(void);

void print()
{
    int i;
    if(FRONT==-1)
    printf("Queue:---EMPTY---\n");
    else
    {
        printf("Queue: ");
        if(FRONT<=REAR)
        {
            for(i=FRONT;i<=REAR;i++)
            printf("%d ",Q[i]);
        }
        else
        {
            for(i=FRONT;i<=max-1;i++)
            printf("%d ",Q[i]);
            
            for(i=0;i<=REAR;i++)
            printf("%d ",Q[i]);
        }
    }
 printf("\n");
}

void showCount()
{
    int i,count=0;
    if(FRONT==-1)
    printf("Queue is EMPTY\n");
    else
    {
        if(FRONT<=REAR)
        {
            for(i=FRONT;i<=REAR;i++)
            count++;
        }
        else
        {
            for(i=FRONT;i<=max-1;i++)
            count++;
            
            for(i=0;i<=REAR;i++)
            count++;
        }
        printf("Count: %d\n",count);
    }
}

//INSERTION THROUGH REAR
void insert_r()
{
    int ele;
    printf("Enter element to be inserted: ");
    scanf("%d",&ele);
    if( (FRONT==0 && REAR==max-1) || (FRONT==REAR+1) )
    printf("Queue is OVERFLOWED!!!\n");
 
    if(FRONT==-1)     
    {
        FRONT=0;
        REAR=0;
    }
    else
    {
        if(REAR==max-1)
        REAR=0;
        else
        REAR++;
    }
    Q[REAR]=ele;
    print();
}


//INSERTION THROUGH FRONT 
void insert_f()
{
    int ele;
    printf("Enter element to be inserted: ");
    scanf("%d",&ele);
    if( (FRONT==0 && REAR==max-1) || (FRONT==REAR+1) )
    printf("Queue is OVERFLOWED!!!\n");
    if(FRONT==-1)        
    {
        FRONT=0;
        REAR=0;
    }
    else
    {
        if(FRONT==0)
        FRONT=max-1;
        else
        FRONT--;
    }
    Q[FRONT]=ele;
    print();
}


//DELETION FROM REAR
void delete_r()
{
    if(FRONT==-1)
    printf("Queue is UNDERFLOWED!!!\n");
    else
    {
        printf("Deleted element: %d\n", Q[REAR]);
        if(FRONT==REAR)         
        {
            FRONT=-1;
            REAR=-1;
        }
        else
        {
            if(REAR==0)
            REAR=max-1;
            else
            REAR--;
        }
        print();
    }  
}


//DELETION FROM FRONT
void delete_f()
{
    if(FRONT==-1)
    printf("Queue is UNDERFLOWED!!!\n");
    else
    {
        printf("Deleted element: %d\n",Q[FRONT]);
        if(FRONT==REAR)   
        {
            FRONT=-1;
            REAR=-1;
        }
        else
        {
            if(FRONT==max-1)
            FRONT=0;
            else
            FRONT++;
        }
        print();
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Insert Rear  2.Delete Rear  3.Insert Front  4.Delete front  5.Show Count\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        insert_r();
        else if(choice==2)
        delete_r();
        else if(choice==3)
        insert_f();
        else if(choice==4)
        delete_f();
        else if(choice==5)
        showCount();
        else
        {
            printf("Operations Completed\n\n");
            break;
        }
    }
}



#include <stdio.h>
int FRONT=-1,REAR=-1;

void print(int Q[])
{
    int i;
    printf("Queue: ");
    for(i=FRONT;i<=REAR;i++)
    printf("%d ",Q[i]);
    printf("\n");
}

void enqueue(int e,int Q[],int max)
{
    if(FRONT==-1)
    FRONT=0;

    REAR++;
    Q[REAR]=e;
    print(Q);
}

void dequeue(int Q[],int max)
{
    if(FRONT>REAR || FRONT==-1)
    printf("Queue is underflowed!!!\n");
    else
    {
        printf("Deleted Element:%d\n",Q[FRONT]);
        FRONT++;
        if(FRONT<=REAR)
        print(Q);
    }     
}

void showCount()
{
    int count=0,i;
    if(FRONT==-1 || FRONT>REAR)
    printf("Queue is Empty!!!\n");
    else
    {
        for(i=FRONT;i<=REAR;i++)
        count++;
        printf("Count: %d\n",count);
    }
}

int main()
{
    int queue[100],max,ele,choice;
    printf("\nEnter Queue size: ");
    scanf("%d",&max);
    while(1)
    {
        printf("\n1.Enqueue or 2.Dequeue  or 3.Show Count\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            if(REAR==max-1)
            printf("Queue is overflowed!!!\n");
            else
            {
                printf("Enter element to be inserted: ");
                scanf("%d",&ele);
                enqueue(ele,queue,max);
            }  
        }
        else if(choice==2)
        dequeue(queue,max);
        else if(choice==3)
        showCount();
        else
        {
            printf("\nOperations Completed\n\n");
            break;
        }
    }
}
#include <stdio.h>
int FRONT=-1,REAR=-1;

void print(int Q[],int max)
{
    int i;
    printf("Queue: ");
    for(i=FRONT;i!=REAR;i=(i+1)%max)
    printf("%d ",Q[i]);
    printf("%d\n",Q[i]);
}

void showCount(int max)
{
    int i,count=1;
    if(FRONT==-1 || REAR==-1)
    printf("Queue is empty!!!\n");
    else
    {
        for(i=FRONT;i!=REAR;i=(i+1)%max)
        count++;
        printf("Count: %d\n",count);
    }
}
void enqueue(int e,int Q[],int max)
{
    if(FRONT==-1 && REAR==-1)
    FRONT=0;

    REAR=(REAR+1)%max;
    Q[REAR]=e;
    print(Q,max);
}

void dequeue(int Q[],int max)
{
    if(FRONT==-1 && REAR==-1)
    printf("Queue is underflowed!!!\n");
    else
    {
        printf("Deleted Element:%d\n",Q[FRONT]);
        if(FRONT==REAR)
        {
            FRONT=-1;
            REAR=-1;
            print(Q,max);
        }
        else
        {
            FRONT=(FRONT+1)%max;
            print(Q,max);
        }
    }
}


int main()
{
    int queue[100],max,ele,choice;
    printf("\nEnter Queue size: ");
    scanf("%d",&max);
    while(1)
    {
        printf("\n1.Enqueue  2.Dequeue  3.Show Count\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            if((REAR+1)%max==FRONT)
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
        showCount(max);
        else
        {
            printf("\nOperations Completed\n");
            break;
        }
    }
}
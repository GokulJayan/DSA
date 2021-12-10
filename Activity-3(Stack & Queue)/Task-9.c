#include <stdio.h>
int top=-1,FRONT=-1,REAR=-1;
#define max 100

void enqueue(int e,int Q[])
{
    if(REAR==-1)
    {
        REAR=max-1;
        FRONT=max;
    }
    FRONT--;
    Q[FRONT]=e;
}

void prints(int S[])
{
    int i;
    for(i=0;i<=top;i++)
    printf("%d ",S[i]);
    printf("\n");
}

void printq(int Q[])
{
    int i;
    for(i=FRONT;i<=REAR;i++)
    printf("%d ",Q[i]);
    printf("\n");
}

void push(int e,int S[])
{
    top++;
    S[top]=e;
}


int main()
{
    int line[100],stack[100],queue[100],size,ele,i;
    printf("\nEnter line size: ");
    scanf("%d",&size);
    printf("Enter year of students: ");
    for(i=0;i<size;i++)
    scanf("%d",&line[i]);
    
    for(i=size-1;i>=0;i--)
    {
        ele=line[i];
        
        if(ele==4)                       
        {
            if(top==max-1)
            printf("Stack is overflowed!!!\n");
            else
            push(ele,stack);
        }
        else
        {
            if(FRONT==0)    //Queue with insertion and deletion from end
            printf("Queue is overflowed!!!\n");
            else
            enqueue(ele,queue);
        }
    }
    printf("Line-1: ");
    printq(queue);
    printf("Line-2: ");
    prints(stack);
    printf("\n");
}
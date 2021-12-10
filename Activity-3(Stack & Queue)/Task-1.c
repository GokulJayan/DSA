#include <stdio.h>
int top=-1;

void showCount(int S[])
{
    int count=0,i;
    for(i=0;i<=top;i++)
    count++;
    printf("Count: %d\n",count);
}

void print(int S[])
{
    int i;
    printf("Stack: ");
    for(i=0;i<=top;i++)
    printf("%d ",S[i]);
    printf("\n");
}

void push(int e,int S[],int max)
{
    top++;
    S[top]=e;
    print(S);
}

void pop(int S[],int max)
{
    if(top==-1)
    printf("Stack is underflowed!!!\n");
    else
    {
        printf("Popped Element:%d\n",S[top]);
        top--;
        print(S);
    }
}

void isempty(int S[])
{
    if(top==-1)
    printf("Stack is empty !!!\n");
    else
    printf("Stack is not empty !!!\n");
}

void isfull(int S[],int max)
{
    if(top==max-1)
    printf("Stack is full !!!\n");
    else
    printf("Stack is not ful !!!\n");
}


int main()
{
    int stack[100],max,ele,choice;
    printf("\nEnter stack size: ");
    scanf("%d",&max);
    while(1)
    {
        printf("\n1.Push  2.Pop  3.Check Stack Empty?  4.Check Stack Full?  5.Show Count\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)                       //Push Operation
        {
            if(top==max-1)
            printf("Stack is overflowed!!!\n");
            else
            {
                printf("Enter element to be pushed: ");
                scanf("%d",&ele);
                push(ele,stack,max);
            }  
        }
        else if(choice==2)                  //Pop Operation
        pop(stack,max);
        
        else if(choice==3)
        isempty(stack);                    //Check whether stack is empty or not

        else if(choice==4)                 //Check whether stack is full or not
        isfull(stack,max);
        
        else if(choice==5)                 //Check whether stack is full or not
        showCount(stack);
        
        else
        {
            printf("\nOperations Completed\n");
            break;
        }

    }
}
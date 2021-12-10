#include<stdio.h>
#include<string.h>
#include<ctype.h>

int top=-1;

int isone(int s[])
{
    if(top==0)
    return 1;
    else
    return 0;
}

void pop(int s[],int max)
{
    top--;
}

void push(int e,int s[],int max)
{
    top++;
    s[top]=e;
}



int main()
{
    char expr[100],ele,first,sec,expression[100];
    int s[100],max,i,stack[100];
    printf("\nEnter the expression: ");
    scanf("%s",expr);
    max=strlen(expr);
    
    //Pushing Each element into the stack
    for(i=0;i<max;i++)
    {
        ele=expr[i];
        if(isdigit(ele))
        push(ele-'0',stack,max);
        else
        {
            sec=stack[top];
            pop(stack,max);
            first=stack[top];
            pop(stack,max);
                
            if(ele=='+')
            push((first+sec),stack,max);
            else if(ele=='-')
            push((first-sec),stack,max);
            else if(ele=='*')
            push((first*sec),stack,max);
            else if(ele=='/')
            push((first/sec),stack,max);
        }
    }
    if(isone(stack))
    printf("Evaluated Result: %d\n\n",stack[top]);
    else
    {
        printf("\nStack: ");
        for(i=0;i<=top;i++)
        printf("%c",stack[i]);
        printf("\n");
        printf("Cannot be evaluated\n");
    }
    return 0;
}
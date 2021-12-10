#include<stdio.h>
#include<string.h>

int top=-1;

int isempty(char s[])
{
    if(top==-1)
    return 1;
    else
    return 0;
}

void pop(char s[],int max)
{
    top--;
}

void push(char e,char s[],int max)
{
    if(e=='}'||e==']'||e==')')
    {
        char prec;
        
        if(e=='}')
        prec='{';
        else if(e==']')
        prec='[';
        else if(e==')')
        prec='(';
    
        if(s[top]==prec)
        pop(s,max);
        else
        {
            top++;
            s[top]=e;
        }
    }
    else
    {
       top++;
       s[top]=e;
    }
}



int main()
{
    char expr[100],stack[100],ele;
    int s[100],max,len,i;
    printf("\nEnter the expression: ");
    scanf("%s",expr);
    max=strlen(expr);
    
    //Pushing Each element into the stack
    for(i=0;i<max;i++)
    {
        ele=expr[i];
        push(ele,stack,max);
    }
    if(isempty(stack))
    {
        printf("Stack is empty\n");
        printf("___Expression is Balanced___\n\n");
    }
    else
    {
        printf("Stack: ");
        for(i=0;i<=top;i++)
        printf("%c",stack[i]);
        printf("\n");
        printf("Expression is Not Balanced!!!\n\n");
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int top=-1;

void push(char e,char s[],int max)
{
    top++;
    s[top]=e;
}

char pop(char s[],int max)
{
    char letter;
    letter=s[top];
    top--;
    return(letter);
}

int main()
{
    char word[100],stack[100];
    int max,ele,len,i;
    printf("Enter a  word: ");
    scanf("%s",word);
    max=strlen(word);
    
    //Pushing Each letter into the stack
    for(i=0;i<=max;i++)
    {
        ele=word[i];
        push(ele,stack,max);
    }
    
    //Popping
    char letter;
    printf("Reversed Word: ");
    for(i=0;i<=max;i++)
    {
        letter=pop(stack,max);
        printf("%c",letter);
    }
    return 0;
}

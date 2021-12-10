#include<stdio.h>
#include<string.h>

int topA=-1; //Operands
int topB=-1; //Operators

int isBempty(char s[])
{
    if(topB==-1)
    return 1;
    else
    return 0;
}

int priority(char op)
{
    if(op=='+'||op=='-')
	return 1;
	else if(op=='*'||op=='/')
	return 2;
}

void pushA(int e,int S[])
{
    topA++;
    S[topA]=e;
}

void popA(int S[])
{
    if(topA!=-1)
    {
        topA--;
    }
}

void pushB(char e,char S[])
{
    topB++;
    S[topB]=e;
}

void popB(char S[])
{
    if(topB!=-1)
    {
        topB--;
    }
}

int calculate(char op, int a , int b)
{
	if(op == '+')
	return a+b;
	else if(op=='-')
	return a-b ;
	else if(op=='*')
	return a*b;
	else if(op == '/')
	return a/b;
}

int main()
{
	char str[100];
	printf("\nEnter an infix expression: ");
	scanf("%s",str);
	int k=0,prece,i;
	char B[100]; //Operators
    int A[100];  //Operands
        
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			int prece = priority(str[i]);
			while(!isBempty(B)  && priority(B[topB])>=prece)
			{
				int b=A[topA];
				popA(A);
				int a=A[topA];
				popA(A);
				int res=calculate(B[topB],a,b);
				pushA(res,A);
                popB(B); 
			}
            pushB(str[i],B);
		}
		else
        pushA((str[i]-'0'),A);
	}
	
	while(!isBempty(B))
	{
		int b=A[topA];
		popA(A);
		int a=A[topA];
		popA(A);
		int res=calculate(B[topB],a,b);
		pushA(res,A);
        popB(B); 
	}
	printf("Result: %d\n",A[topA]);
	return 0;
}
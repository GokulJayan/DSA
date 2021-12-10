#include<stdio.h>
#include<string.h>

int *insert(int A[],int n,int ele,int pos)
{
    int i,j,temp;
    for(i=n-1;i>=pos;i--)
    A[i+1]=A[i];
    A[pos]=ele;
    return(A);
}

int main()
{
    //Taking input from the user
    int i,n,Graduation[100],mark,pos;
    char pos_word[10];
    printf("Enter class size: ");
    scanf("%d",&n);
    printf("Enter marks of %d students: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&Graduation[i]);

    //Insertion
    printf("Enter marks to be inserted: ");
    scanf("%d",&mark);
    printf("Enter the position of new mark in the list: ");
    scanf("%s",pos_word);
    if(strcmp(pos_word,"beg")==0)
    pos=0;
    else if(strcmp(pos_word,"end")==0)
    pos=n;
    else
    {
        printf("Enter the middle position: ");
        scanf("%d",&pos);
    }
    insert(Graduation,n,mark,pos);

    //Printing the list of marks after insertion
    printf("List after insertion: ");
    for(i=0;i<n+1;i++)
    printf("%d ",Graduation[i]);
    return 0;
}
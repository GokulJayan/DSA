#include<stdio.h> 

int *delete(int A[],int n,int pos)
{
  int i;
  if(pos<n)
  {
    for(i=pos;i<n;i++)
    A[i]=A[i+1];
  }
  return(A);
}

int find_index(int A[],int n,int item)
{
    int i,index;
    for(i=0;i<n;i++)
    {
        if(A[i]==item)
        index=i;
    }
    return index;
}

int main()
{
    //Taking input from the user
    int i,n,A[100],del_pos,item;
    char optn;
    printf("Enter no:of elements: ");
    scanf("%d",&n);
    printf("Enter values of %d elements:   ",n);
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);

    //Deletion
    printf("How you want to delete by element or index(e/i): ");
    scanf("%s",&optn);
    if(optn=='i')
    {
        printf("\nEnter position in which element to be deleted: ");
        scanf("%d",&del_pos);
    }
    else if(optn=='e')
    { 
        printf("\nEnter value of element to be deleted: ");
        scanf("%d",&item);
        del_pos=find_index(A,n,item);
    }
    else
    {
        printf("Invalid Option");
        exit();
    }
    delete(A,n,del_pos);
    n--;

    printf("Array after deletion of element at %d: ",del_pos);
    for(i=0;i<n;i++)
    printf("%d ",A[i]);
    return 0;
}
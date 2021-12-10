#include<stdio.h>

int *insert(int A[],int n,int ele,int pos)
{
    int i,j,temp;
    for(i=n-1;i>=pos;i--)
    A[i+1]=A[i];
    A[pos]=ele;
    return(A);
}

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

int main()
{
    //Taking input from the user
    int i,n,vac[100],new,pos,del_pos;
    printf("Enter no:of vaccines: ");
    scanf("%d",&n);
    printf("Enter names of %d vaccines:   ",n);
    for(i=0;i<n;i++)
    scanf("%d",&vac[i]);
    
    //Insertion
    printf("\nEnter the cost of vaccine to be inserted: ");
    scanf("%d",&new);
    printf("Enter the position in which new cost should be inserted: ");
    scanf("%d",&pos);
    insert(vac,n,new,pos);
    n++;
    printf("After insertion: ");
    for(i=0;i<n;i++)
    printf("%d ",vac[i]);  
    
    //Reduction
    printf("\n\nAfter the reduction of Rs.4: ");
    for(i=0;i<n;i++)
    {
      vac[i]=vac[i]-4;    
      printf("%d ",vac[i]);
    }
    printf("\n");
    
    //Deletion
    printf("\nEnter position in which vaccine to be deleted: ");
    scanf("%d",&del_pos);
    delete(vac,n,del_pos);
    n--;
    printf("Vaccine list after deletion of vaccine at index %d: ",del_pos);
    for(i=0;i<n;i++)
    printf("%d ",vac[i]);
    return 0;
}
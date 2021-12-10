#include<stdio.h>
#include<stdlib.h> 
#include<malloc.h>

struct node
{
    int data;
    struct node *next;    
};

struct node*getNode(int ele)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    return temp;
}

struct node *create(int Ar[],int N)
{
    struct node *temp,*ptr,*start=NULL;
    int i;
    for(i=0;i<N;i++)
    {
        temp=getNode(Ar[i]);
        if(start==NULL)
        start=ptr=temp;
        else
        {
            ptr->next=temp;
            ptr=temp;
        }
    }
    return start;
}

void display(struct node *start)
{
    struct node *ptr;
    for(ptr=start;ptr!=NULL;ptr=ptr->next)
    printf("%d ",ptr->data);
}

struct node *merge(struct node *L1, struct node *L2)
{
    struct node *L,*P;
    if(L1==NULL)
    return L2;
    if(L2==NULL)
    return L1;
    if(L1->data < L2->data)
    {
        L=P=L1;
        L1=L1->next;
    }
    else
    {
        L=P=L2;
        L2=L2->next;
    }
    while(L1!=NULL && L2!=NULL)
    {
        if(L1->data<L2->data)
        {
            P->next=L1;
            L1=L1->next;
            P=P->next;
        }
        else
        {
            P->next=L2;
            L2=L2->next;
            P=P->next;
        }
    }
    if(L1!=NULL)
    P->next=L1;
    else
    P->next=L2;
    return L;
}

void main()
{
    printf("\n");
    int A[100],B[100],n1,n2,i;
   
    printf("Enter size of first list: ");
    scanf("%d",&n1);
    printf("Enter elements: ");
    for(i=0;i<n1;i++)
    scanf("%d",&A[i]);

    printf("\nEnter size of second list: ");
    scanf("%d",&n2);
    printf("Enter elements: ");
    for(i=0;i<n2;i++)
    scanf("%d",&B[i]);

    struct node *s1,*s2,*s3;
    s1=create(A,n1);
    printf("\nList1: ");
    display(s1);
    printf("\n");
    
    s2=create(B,n2);
    printf("List2: ");
    display(s2);
    printf("\n\n");
    
    s3=merge(s1,s2);
    printf("Merged List: ");
    display(s3);
    printf("\n\n");
}
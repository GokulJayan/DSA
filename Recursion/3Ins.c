
void insSort(int Ar[], int N)
{
    int i,j,k,key;
    for(i=1;i<N;i++) 
    {
        key=Ar[i];
        j=i-1;
        while(j>=0 && Ar[j]>key) 
        {
            Ar[j+1]=Ar[j];
            j--;
        }
        Ar[j+1]=key;
        printf("    Array after iteration %d: ",i);
        for(k=0;k<N;k++)
        printf("%d ",Ar[k]);
        printf("\n");
    }
    printf("\n");
} 


void insSort()
{
    int i,j,k,key;
    for(i=1;i<N;i++) 
    {
        key=Ar[i];
        j=i-1;
        while(j>=0 && Ar[j]>key) 
        {
            Ar[j+1]=Ar[j];
            j--;
        }
        Ar[j+1]=key;
        printf("    Array after iteration %d: ",i);
        for(k=0;k<N;k++)
        printf("%d ",Ar[k]);
        printf("\n");
    }
    printf("\n");
} 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int count, int n);
void display();

void insert(int count, int n)
{
    if (count < n)
    {
        struct node *new;
        new = (struct node *)malloc(sizeof(struct node));

        printf("Enter element: "); //Element to be inserted
        scanf("%d", &new->data);   //Storing the element in the data part of new node

        if (new == NULL)
            printf("List is Overflowed!!!\n");

        else
        {
            struct node *temp;
            if (head == NULL) //If the list is empty before insertion
            {
                new->rlink = NULL;
                head = new;
            }
            else             //To insert element at the end,
            {                //we need to traverse the entire list till the end
                temp = head; //For traversing head cannot be used so using temp
                while (temp->rlink != NULL)
                {
                    temp = temp->rlink;
                }
                temp->rlink = new;
                new->rlink = NULL;
            }
            insert(++count, n);
        }
    }
}

void display() 
{
    struct node *ptr = head;
    if (ptr == NULL)
        printf("Linked List is underflowed!!!\n");
    else
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr=ptr->rlink;
        }
    }
}

int main()
{
    printf("\n");
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    insert(0, n);
    struct node *ptr;
    ptr = head;
    display(ptr);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


void insert(int pos);
void display();

struct node 
{
    int data;
    struct node* rlink;
};
struct node *head;
 

void reverse()
{
    struct node *prev, *temp, *next;
    temp=head;
    while (temp!= NULL) 
    {
        next = temp->rlink;
        temp->rlink = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}


void insert(int ele)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data=ele;    
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    else
    {
        struct node *temp;
        if (head == NULL) 
        {
            new->rlink = NULL;
            head = new;
        }
        else             
        {                
            temp = head; 
            while (temp->rlink != NULL)
            {
                temp = temp->rlink;
            }
            temp->rlink = new;
            new->rlink = NULL;
        }
    }
}

void display()
{  
    struct node *ptr;  
    ptr=head;   
    if(ptr==NULL)  
    printf("Linked List is underflowed!!!\n");  
    else  
    {  
        printf("List: ");   
        while (ptr!=NULL)  
        {  
            printf("%d ",ptr->data);  
            ptr=ptr->rlink;  
        }  
    }  
    printf("\n");
} 

int main()
{
    printf("\n");
    int Ar[100],i,n;
    printf("Enter no:of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&Ar[i]);

    for(i=0;i<n;i++)
    insert(Ar[i]);
    
    printf("\n");
    display();
    reverse();
    printf("Reversed ");
    display();
    printf("\n");
    return 0;
}
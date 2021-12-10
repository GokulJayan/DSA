#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int pos);
void delete (int pos);
void display();

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

void delete (int pos)
{
    struct node *delptr; //To store node to be deleted
    if (head == NULL)
        printf("List is Underflowed!!!\n");
    else
    {
        if (pos == 1) //Delete from beginning
        {
            delptr = head;        //Head is stored in delptr
            head = delptr->rlink; //Link part of delptr is stored as new head
            free(delptr);         //Deleting the delptr
        }
        else if (pos == 2) //Delete from random location
        {
            int position, i;
            struct node *temp, *prev_ptr;
            printf("Enter the position where you want to delete: ");
            scanf("%d", &position);
            position--; //For getting index of the node
            temp = head;
            for (i = 0; i < position; i++)
            {
                prev_ptr = temp;
                temp = temp->rlink;
                if (temp == NULL)
                {
                    printf("Deletion can't be performed\n");
                    break;
                }
            }
            prev_ptr->rlink = temp->rlink;
            free(temp);
        }
        else if (pos == 3) //Delete from the end
        {
            struct node *temp, *prev_ptr;
            if (head->rlink == NULL) //If only one element is there in list
            {
                head = NULL;
                free(head);
            }
            else
            {
                temp = head;
                while (temp->rlink != NULL) //Travarse till before last node
                {
                    prev_ptr = temp; //prev_ptr will point out the last node after deletion
                    temp = temp->rlink;
                }
                prev_ptr->rlink = NULL; //Making the previous node(before deletion) as last node after deletion
                free(temp);             //Deleting last node
            }
        }
    }
    display();
}

void display() //For printing the list
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
        printf("Linked List is underflowed!!!\n");
    else
    {
        printf("List: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->rlink;
        }
    }
    printf("\n\n");
}

int main()
{
    printf("\n");
    int Ar[]={2,6,8,9,7,1,4},i,n=7;
    for(i=0;i<n;i++)
    insert(Ar[i]);
    display();
    int choice;
    while (1)
    {
        printf("1.Delete 2.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int pos;
            printf("1.beg 2.random 3.end\n");
            printf("Enter position: ");
            scanf("%d", &pos);
            delete (pos);
        }
        else
            break;
    }
    printf("\n");
    return 0;
}
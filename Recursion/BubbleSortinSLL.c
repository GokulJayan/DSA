#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int ele);
void display();
void swap(struct node *a, struct node *b);
void bubbleSort();

void insert(int ele)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data=ele;   //Storing the element in the data part of new node
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    else
    {
        // if(pos==1)            //Insertion at the beginning
        // {
        //     new->rlink=head;  //Storing the old head to the link part of new node
        //     head=new;         //Storing address of new node as the new head
        // }

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
    }
}

void display()
{
    struct node *ptr = head;
    if (ptr == NULL)
        printf("Linked List is underflowed!!!\n");
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->rlink;
        }
    }
}

int main()
{
    printf("\n");
    int n, i,A[100];
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
        insert(A[i]);
    }
    printf("Before Sorting: ");
    display();
    printf("\n");
    printf("After Sorting: ");
    bubbleSort();
    display();
    return 0;
}

void bubbleSort()
{
    int swapped, i;
    struct node *ptr;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = head;

        while (ptr->rlink != NULL)
        {
            if (ptr->data > ptr->rlink->data)
            {
                swap(ptr, ptr->rlink);
                swapped = 1;
            }
            ptr = ptr->rlink;
        }
    } while (swapped);
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
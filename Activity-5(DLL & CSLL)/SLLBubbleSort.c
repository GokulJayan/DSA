#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int ele);
void bubbleSort();
void swap(struct node *a, struct node *b);
void display();


void insert(int data)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->rlink = head;
    head = ptr1;
}


void display() // For printing the list
{
    struct node *ptr;
    ptr = head;
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
    printf("\n\n");
}

void bubbleSort()
{
    int flag, i;
    struct node *ptr;
    struct node *ptr1 = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;
    else
    {
        do
        {
            flag = 0;
            ptr = head;
            while (ptr->rlink != ptr1)
            {
                if (ptr->data > ptr->rlink->data)
                {
                    swap(ptr, ptr->rlink);
                    flag = 1;
                }
                ptr = ptr->rlink;
            }
            ptr1 = ptr;
        } while (flag);
    }
}


void swap(struct node *n1, struct node *n2)
{
    int temp;
    temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

int main()
{
    int A[100],n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    
    for (i = 0; i < n; i++)
    insert(A[i]);

    bubbleSort();
    printf("\n Linked list after sorting: ");
    display();

    return 0;
}
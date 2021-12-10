#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int ele, int pos);
int search(int ele);
void display();

void insert(int ele, int pos)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = ele;
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    
    if (pos == 1)
    {
        new->rlink = head;
        head = new;
    }
    else if (pos == 2)
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
    int Ar[100], i, n, x, index;
    printf("Enter no:of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &Ar[i]);
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        if (Ar[i] == x)
        {
            insert(Ar[i], 1);
            index = i;
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i!= index)
        {
            if (Ar[i] < x)
                insert(Ar[i], 1);
            else
                insert(Ar[i], 2);
        }
    }
    display();

    printf("\n");
    return 0;
}

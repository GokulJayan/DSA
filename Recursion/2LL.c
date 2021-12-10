#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int count, int n);
void display(struct node* ptr);

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

void display(struct node* ptr) //For printing the list
{
    if (ptr == NULL)
        printf("Linked List is underflowed!!!\n");
    else
    {
        if (ptr != NULL)
        {
            printf("%d ", ptr->data);
            display(ptr->rlink);
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
    struct node* ptr = head;
    display(ptr);
    printf("\n");
    return 0;
}
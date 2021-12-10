#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert();
void delete ();
void display();
int search(int ele);
void insertfirst(int ele);

void insert()
{
    int ele;
    printf("Enter element after which new element should be inserted: "); //Element to be inserted
    scanf("%d", &ele);
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: "); //Element to be inserted
    scanf("%d", &new->data);   //Storing the element in the data part of new node
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    else
    {
        int position, i, c;
        struct node *temp;
        position = search(ele);
        position--; //For getting index
        temp = head;
        for (i = 0; i < position; i++)
        {
            temp = temp->rlink;
            if (temp == NULL)
            {
                printf("Insertion cannot be performed\n");
                return;
            }
        }
        new->rlink = temp->rlink;
        temp->rlink = new;
    }
    display();
}

void delete ()
{
    struct node *delptr; //To store node to be deleted
    if (head == NULL)
        printf("List is Underflowed!!!\n");
    else
    {
        int position, i,ele;
        struct node *temp, *prev_ptr;
        printf("Enter the element whose successor to be deleted: ");
        scanf("%d", &ele);
        position=search(ele);
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

void insertfirst(int ele)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = ele;
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

int search(int ele) //For searching a particular element
{
    struct node *temp;
    int i = 0, flag;
    temp = head;
    if (temp == NULL)
        printf("List is empty!!!\n");
    else
    {
        while (temp != NULL)
        {
            if (temp->data == ele)
            {
                flag = 1;
                break;
            }
            else
                flag = 0;

            i++;
            temp = temp->rlink;
        }
        if (flag == 0)
            printf("Element is not in this list\n");
    }
    return (i + 1);
}

int main()
{
    printf("\n");
    int Ar[] = {5, 1, 4, 8, 6, 2, 9}, i, n = 7;
    for (i = 0; i < n; i++)
        insertfirst(Ar[i]);
    display();
    int choice;
    while (1)
    {
        printf("1.Insert  2.Delete  3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            delete ();
        }
        else
            break;
    }
    printf("\n");
    return 0;
}

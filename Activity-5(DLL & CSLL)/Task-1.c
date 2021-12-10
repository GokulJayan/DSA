#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *head;

void insert(int pos);
void search(int ele);
void display();

void insert(int ele)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    else
    {
        new->data = ele;
        new->llink = NULL;
        if (head == NULL)
        {
            new->rlink = NULL;
        }
        else
        {
            new->rlink = head;
            head->llink = new;
        }
        head = new;
    }
}

void search(int ele) //For searching a particular element
{
    struct node *temp;
    int i = 0, flag;
    temp = head;
    if (temp == NULL)
        printf("List is empty!!!\n\n");
    else
    {
        while (temp != NULL)
        {
            if (temp->data == ele)
            {
                printf("Element found at position: %d\n\n", i + 1); //Prints the location of the searched element in the list
                flag = 1;
                break;
            }
            else
                flag = 0;

            i++;
            temp = temp->rlink;
        }
        if (flag == 0)
            printf("Element is not in this list\n\n");
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
    int choice;
    int Ar[] = {2, 6, 8, 9, 7, 1, 4}, i, n = 7;
    for (i = 0; i < n; i++)
        insert(Ar[i]);
    display();
    while (1)
    {
        printf("1.Search   2.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int ele;
            printf("Enter element to be searched: ");
            scanf("%d", &ele);
            search(ele);
        }
        else
            break;
    }
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
};
struct node *head;

void insert(int pos);
void display();

void insert(int pos)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: "); //Element to be inserted
    scanf("%d", &new->data);   //Storing the element in the data part of new node
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    else
    {

        if (pos == 1) //Insertion at the beginning
        {
            new->rlink = head; //Storing the old head to the link part of new node
            head = new;        //Storing address of new node as the new head
        }

        else if (pos == 2) //Insertion at random location
        {
            int position, i, c;
            struct node *temp;
            printf("1.Before  2.After\n");
            printf("Enter your choice: ");
            scanf("%d", &c);
            if (c == 1)   //Before a given location
            {
                printf("Enter the location where before you want to insert: ");
                scanf("%d", &position);
                position--; //For getting index
                position--; //For getting the previous node
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

            else if (c == 2)  //After a given location
            {
                printf("Enter the location where after you want to insert: ");
                scanf("%d", &position);
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
        }

        else if (pos == 3) //Insertion at the end
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
    int choice;
    while (1)
    {
        printf("1.Insert  2.Display 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int pos;
            printf("1.beg 2.random 3.end\n");
            printf("Enter position: ");
            scanf("%d", &pos);
            insert(pos);
        }
        else if (choice == 2)
            display();
        else
            break;
    }
    printf("\n");
    return 0;
}
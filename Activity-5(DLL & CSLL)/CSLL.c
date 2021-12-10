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
void search(int ele);
void count();
void display();

void insert(int pos)
{
    struct node *new, *temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: "); //Element to be inserted
    scanf("%d", &new->data);   //Storing the element in the data part of new node
    if (new == NULL)
        printf("List is Overflowed!!!\n");
    else
    {
        if (pos == 1) //Insertion at the beginning
        {
            if (head == NULL)
            {
                head = new;
                new->rlink = head;
            }
            else
            {
                temp = head;
                while (temp->rlink != head)
                {
                    temp = temp->rlink;
                }
                new->rlink = head; //Storing the old head to the link part of new node
                head = new;        //Storing address of new node as the new head
                temp->rlink = new;
            }
        }
        else if (pos == 2) //Insertion at random location
        {
            int position, i;
            printf("Enter the position where you want to insert: ");
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
        else if (pos == 3) //Insertion at the end
        {
            if (head == NULL) //If the list is empty before insertion
            {
                head = new;
                new->rlink = head;
            }
            else             //To insert element at the end,
            {                //we need to traverse the entire list till the end
                temp = head; //For traversing head cannot be used so using temp
                while (temp->rlink != head)
                {
                    temp = temp->rlink;
                }
                temp->rlink = new;
                new->rlink = head;
            }
        }
    }
    display();
}

void delete (int pos)
{
    struct node *ptr,*prev_ptr; //To store node to be deleted
    if (head == NULL)
        printf("List is Underflowed!!!\n");
    else
    {
        if (pos == 1) //Delete from beginning
        {
            if (head->rlink == head)
            {
                head = NULL;
                free(head);
            }
            else
            {
                ptr = head;        //Head is stored in delptr
                while (ptr->rlink!=head)
                {
                    ptr=ptr->rlink;                    
                }
                ptr->rlink=head->rlink;                
                free(head);         //Deleting the delptr
                head = ptr->rlink; //Link part of delptr is stored as new head
            }
        }
        else if (pos == 2) //Delete from random location
        {
            int position, i;
            printf("Enter the position where you want to delete: ");
            scanf("%d", &position);
            position--; //For getting index of the node
            ptr = head;
            for (i = 0; i < position; i++)
            {
                prev_ptr = ptr;
                ptr = ptr->rlink;
                if (ptr == NULL)
                {
                    printf("Deletion can't be performed\n");
                    break;
                }
            }
            prev_ptr->rlink = ptr->rlink;
            free(ptr);
        }
        else if (pos == 3) //Delete from the end
        {
            if (head->rlink == head) //If only one element is there in list
            {
                head = NULL;
                free(head);
            }
            else
            {
                ptr = head;
                while (ptr->rlink != head) //Travarse till before last node
                {
                    prev_ptr =ptr; //prev_ptr will point out the last node after deletion
                    ptr = ptr->rlink;
                }
                prev_ptr->rlink = ptr->rlink; //Making the previous node(before deletion) as last node after deletion
                free(ptr);             //Deleting last node
            }
        }
    }
    display();
}

void search(int ele) //For searching a particular element
{
    struct node *temp;
    int i = 0, flag;
    temp = head;
    if (temp == NULL)
        printf("List is empty!!!\n");
    else
    {
        while (temp->rlink !=head)
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
            printf("Element is not in this list\n\n");
        else
            printf("Element found at location: %d\n\n", i + 1);
    }
}

void count()
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->rlink;
        count++;
    }
    printf("No: of elements in the list: %d\n\n", count);
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
        while (ptr->rlink != head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->rlink;
        }
        printf("%d ", ptr->data);
    }
    printf("\n\n");
}

int main()
{
    printf("\n");
    int choice;
    while (1)
    {
        printf("1.Insert  2.Delete  3.Search  4.Show Count  5.Exit\n");
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
        {
            int pos;
            printf("1.beg 2.random 3.end\n");
            printf("Enter position: ");
            scanf("%d", &pos);
            delete (pos);
        }
        else if (choice == 3)
        {
            int element;
            printf("Enter element to be searched: ");
            scanf("%d", &element);
            search(element);
        }
        else if (choice == 4)
            count();
        else
            break;
    }
    printf("\n");
    return 0;
}
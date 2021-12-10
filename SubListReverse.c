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
void count();
void display();
void reverse(struct node *start, int count);

void insert(int ele)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = ele; //Storing the element in the data part of new node
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
    }
}

void checkEven()
{
    int c;
    struct node *ptr, *ptr1, *ptr2;
    ptr = head;
    while (ptr != NULL)
    {
        c=-1;
        if((ptr->data)%2 == 0) 
        {
          ptr1=ptr;
          while(ptr->data %2 ==0)
          {
              c++;
              ptr=ptr->rlink;
              if(ptr == NULL)
              break;
          }
          if(c>=1)
          reverse(ptr1,c);
        }
        else
        {
            ptr=ptr->rlink;  
        }
    }
}

void reverse(struct node *start, int count)
{
    struct node *prev, *temp, *next;
    temp=start;
    while (count>=0) 
    {
        next = temp->rlink;
        temp->rlink = prev;
        prev = temp;
        temp = next;
        count--;
    }
    start = prev;
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
}

int main()
{
    int n, A[100], i;
    int choice;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < n; i++)
        insert(A[i]);
    checkEven();
    display();
    printf("\nFinished");
    return 0;
}

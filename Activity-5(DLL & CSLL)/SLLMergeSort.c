#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* rlink;
};
struct node* head;

void insert(int data)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->rlink = head;
    head = ptr1;
}

void display()
{
    struct node* temp=head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
}

void mergeSort(struct node** headRef);
struct node* Merge(struct node* a, struct node* b);
void middle(struct node* source,struct node** frontRef, struct node** backRef);


void mergeSort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a;
    struct node* b;

    if ((head == NULL) || (head->rlink == NULL)) 
    return;
    middle(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = Merge(a, b);
}

struct node* Merge(struct node* a, struct node* b)
{
    struct node* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (a->data <= b->data) 
    {
        result = a;
        result->rlink = Merge(a->rlink, b);
    }
    else 
    {
        result = b;
        result->rlink = Merge(a, b->rlink);
    }
    return (result);
}


void middle(struct node* source,struct node** frontRef, struct node** backRef)
{
    struct node* fast;
    struct node* slow;
    slow = source;
    fast = source->rlink;

    while (fast != NULL) 
    {
        fast = fast->rlink;
        if (fast != NULL) 
        {
            slow = slow->rlink;
            fast = fast->rlink;
        }
    }
    *frontRef = source;
    *backRef = slow->rlink;
    slow->rlink = NULL;
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

    mergeSort(&head);
    printf("Linked List after Sorting : ");
    display();

    return 0;
}
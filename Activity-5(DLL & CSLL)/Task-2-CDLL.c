#include<stdio.h>
#include<stdlib.h> 

struct node
{
    int data;
    struct node *llink;  
    struct node *rlink;      
};
struct node *head;

void insert(int pos);
void delete(int pos);
void display();

void insert(int pos)
{
    struct node*new,*temp;
    new=(struct node*)malloc(sizeof(struct node));     
    if(new==NULL)
    printf("List is Overflowed!!!\n");
    else
    {
        printf("Enter element: ");                     //Element to be inserted
        scanf("%d",&new->data);                        //Storing the element in the data part of new node
    
        if(pos==1)            //Insertion at the beginning
        {
            if(head==NULL)
            {
                head=new;
                new->rlink=head; 
                new->llink=head;
            }
            else
            {
                temp=head;
                while(temp->rlink!=head)
                {
                    temp=temp->rlink;
                }
                temp->rlink=new;
                new->llink=temp;
                head->llink=new; 
                new->rlink=head; //Storing the old head to the right-link part of new node
                head=new;
            } 
        }
        else if(pos==2)       //Insertion at random location
        {
            int position,i;
            struct node *temp;            
            printf("Enter the position where you want to insert: ");
            scanf("%d",&position);
            position--; //For getting index
            position--; //For getting the previous node
            temp=head;
            for(i=0;i<position;i++)
            {
                temp=temp->rlink;
                if(temp==NULL)
                {
                    printf("Insertion cannot be performed\n");
                    return;                    
                }
            }
            new->rlink=temp->rlink;
            new->llink=temp;
            temp->rlink=new;
        }
        else if(pos==3)        //Insertion at the end
        {
            if(head==NULL)     //If the list is empty before insertion
            {
                head=new;
                new->rlink=head;
                new->llink=head;
            }
            else                           //To insert element at the end,
            {                              //we need to traverse the entire list till the end
                temp=head;                 //For traversing head cannot be used so using temp
                while(temp->rlink!=head)  
                {                        
                    temp=temp->rlink;
                }
                temp->rlink=new;
                new->llink=temp;
                head->llink=new;
                new->rlink=head;
            }
        }
    }
    display();  
}

void delete(int pos)
{
    struct node*temp;  //To store node to be deleted
    if(head==NULL)
    printf("List is Underflowed!!!\n");
    else
    {
        if(pos==1)              //Delete from beginning
        {
            if(head->rlink==head)
            {
                head=NULL;
                free(head);
            }
            else
            {
                
                temp=head;        //Head is stored in delptr
                while(temp->rlink!=head)
                {
                    temp=temp->rlink;
                }
                temp->rlink=head->rlink;
                head->rlink->llink=temp;
                free(head);
                head=temp->rlink; //Link part of delptr is stored as new head
            }
        } 
        else if(pos==2)         //Delete from random location
        {
            int position,i;
            struct node *temp,*ptr;            
            printf("Enter the position where you want to delete: ");
            scanf("%d",&position);
            position--; //For getting index of the node
            position--;
            temp=head;
            for(i=0;i<position;i++)
            {
                temp=temp->rlink;
            }
                if(temp->rlink==head)
                {
                    printf("Deletion can't be performed\n");
                }
                // else if(temp->rlink->rlink==head)
                // {
                //     temp->llink->rlink=temp->rlink;
                //     head->llink=temp->rlink;
                // }
                else
                {
                    ptr=temp->rlink;
                    temp ->rlink= ptr -> rlink;  
                    temp->rlink->llink=temp;
                    free(ptr);
                }
            
        }
        else if(pos==3)        //Delete from the end
        {
            if(head->rlink==head)  //If only one element is there in list
            {
                head=NULL;
                free(head);
            }  
            else
            {
                temp=head;
                while(temp->rlink!=head) //Travarse till before last node
                {
                    temp=temp->rlink;   
                }
                temp->llink->rlink=head;    //Making the previous node(before deletion) as last node after deletion
                head->llink=temp->llink;
                free(temp);              //Deleting last node
            }          
        }
    }
    display();    
}

void display()   //For printing the list
{  
    struct node *ptr;  
    ptr=head;   
    if(ptr==NULL)  
    printf("Linked List is underflowed!!!\n");  
    else  
    {  
        printf("List: ");   
        while (ptr->rlink!=head)  
        {  
            printf("%d ",ptr->data);  
            ptr=ptr->rlink;  
        }  
        printf("%d ",ptr->data);  
    }  
    printf("\n\n");
}     

int main()
{
    printf("\n");
    int choice;
    while(1)
    {
        printf("1.Insert   2.Delete   3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int pos;
            printf("1.beg 2.random 3.end\n");
            printf("Enter position: ");
            scanf("%d",&pos);
            insert(pos);
        }
        else if(choice==2)
        {
            int pos;
            printf("1.beg 2.random 3.end\n");
            printf("Enter position: ");
            scanf("%d",&pos);
            delete(pos);
        }
        else
        break;
    }
    printf("\n");
    return 0;
}
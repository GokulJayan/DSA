#include <stdio.h>
#include <stdlib.h>

int count = 1;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    struct node *new;
    printf("Enter data:");
    new = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new->data);
    new->left = new->right = NULL;
    return new;
}

void insert(struct node *root, struct node *temp)
{
    if (root->left == NULL)
        root->left = temp;
    else if (root->right == NULL)
        root->right = temp;
    else if (root->left != NULL && (root->left->left == NULL || root->left->right == NULL))
        insert(root->left, temp);
    else if (root->right != NULL && (root->right->left == NULL || root->right->right == NULL))
        insert(root->right, temp);
    else
        insert(root->left->left, temp);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node *root, int val)
{
    if (root != NULL)
    {
        if (root->data == val)
            return 1;
        else if (root->left != NULL)
            search(root->left, val);
        else if (root->right != NULL)
            search(root->right, val);
    }
}

void deleteTree(struct node *root)
{
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    printf("Node Deleted: %d\n", root->data);
    free(root);
    return;
}

int main()
{
    int choice;
    struct node *root = NULL, *temp;
    while (1)
    {
        printf("\n1.Insert  2.Traversal  3.Search  4.DeleteTree  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            temp = create();
            if (root == NULL)
                root = temp;
            else
                insert(root, temp);
        }
        else if (choice == 2)
        {
            printf("\nInorder Traversal: ");
            inorder(root);

            printf("\nPreorder Traversal: ");
            preorder(root);

            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
        }
        else if (choice == 3)
        {
            int val;
            printf("Enter element to be searched: ");
            scanf("%d", &val);
            int tmp = search(root, val);
            if (tmp == 1)
                printf("Data found\n");
            else
                printf("Data Not found in tree.\n");
        }
        else if(choice==4)
        deleteTree(root);
        else
            break;
    }
    printf("\n");
    return 0;
}
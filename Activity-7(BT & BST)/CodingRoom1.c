#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node *, struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *delete (struct node *root, int data);
struct node *min_value(struct node *node);
struct node *max_value(struct node *node);
void predecessor(struct node *root, int item);
void successor(struct node *root, int item);

int A[] = {50, 29, 41, 82, 12, 74, 20, 92, 8, 25};
int i = 0;

struct node *create()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = A[i++];
    new->left = new->right = NULL;
    return new;
}

void insert(struct node *root, struct node *new)
{
    if (new->data < root->data)
    {
        if (root->left != NULL)
            insert(root->left, new);
        else
            root->left = new;
    }
    else if (new->data > root->data)
    {
        if (root->right != NULL)
            insert(root->right, new);
        else
            root->right = new;
    }
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
    if (!(root))
        return 0;

    if (val < root->data)
        search(((root)->left), val);

    else if (val > (root)->data)
        search(((root)->right), val);

    else if (val == (root)->data)
        return 1;
}

void deltree(struct node *root)
{
    if (root != NULL)
    {

        deltree(root->left);
        deltree(root->right);
        free(root);
    }
}

struct node *delete (struct node *root, int data)
{
    if (root == NULL)
        return root;
    // If the key to be deleted is smaller than the root's key,
    if (data < root->data)
        root->left = delete (root->left, data);
    // If the key to be deleted is greater than the root's key,
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children:
        struct node *temp = min_value(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = delete (root->right, temp->data);
    }
    return root;
}

struct node *min_value(struct node *root)
{
    struct node *current = root;
    while (current->left != NULL)
        current = current->left;
    //printf("Min Value: %d\n", current->data);
    return current;
}

struct node *max_value(struct node *root)
{
    struct node *current = root;
    while (current->right != NULL)
        current = current->right;
    //printf("Max Value: %d\n", current->data);
    return current;
}

void predecessor(struct node *root, int item)
{
    struct node *predecessor = NULL;
    struct node *current = root;
    while (current != NULL)
    {
        if (item > current->data)
        {
            predecessor = current;
            current = current->right;
        }
        else if (item <= current->data)
        {
            current = current->left;
            if (current->right == NULL)
            {
                printf("No predecessor for %d\n", item);
                continue;
            }
        }
    }
    printf("Predecessor of %d: %d\n", item, predecessor->data);
}

void successor(struct node *root, int item)
{
    struct node *successor = NULL;
    struct node *current = root;
    while (current != NULL)
    {
        if (item >= current->data)
        {
            current = current->right;
            if (current->right == NULL)
            {
                printf("No successor for %d\n", item);
                continue;
            }
        }

        else if (item < current->data)
        {
            successor = current;
            current = current->left;
        }
    }
    printf("Successor of %d: %d\n", item, successor->data);
}

int main()
{
    int i;
    struct node *root = NULL, *newnode;
    for (i = 0; i < 10; i++)
    {
        newnode = create();
        if (root == NULL)
            root = newnode;
        else
            insert(root, newnode);
    }
    if (root == NULL)
        printf("Tree is empty!!!\n");
    else
    {
        printf("\nPreorder Traversal: ");
        preorder(root);

        printf("\nInorder Traversal: ");
        inorder(root);

        printf("\nPostorder Traversal: ");
        postorder(root);
        printf("\n");
    }

    int ele = 12;
    delete (root, ele);
    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    int val = 20;
    int tmp = search(root, val);
    printf("%d\n", tmp);

    printf("%d\n",min_value(root)->data);
    printf("%d\n",max_value(root)->data);
}
// else if (choice == 2)
// {

// }
// else if (choice == 3)
// {
//     int val;
//     printf("Enter element to be searched: ");
//     scanf("%d", &val);
//     int tmp = search(root, val);
//     if (tmp == 1)
//         printf("Data found\n");
//     else
//         printf("Data Not found in tree.\n");
// }
//
// else if (choice == 5)
//     deltree(root);
// else if (choice == 6)
//     min_value(root);
// else if (choice == 7)
//     max_value(root);
// else if (choice == 8)
// {
//     int val;
//     printf("Enter element: ");
//     scanf("%d", &val);
//     predecessor(root, val);
// }
// else if (choice == 9)
// {
//     int val;
//     printf("Enter element: ");
//     scanf("%d", &val);
//     successor(root, val);
// }
// else break;
// printf("\n");
// return 0;
// }
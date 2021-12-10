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

int A[] = {10, 5, 1, 7, 40, 50};
int n = 6, i = 0, c = 0;

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
        if (c == 0)
        {
            printf("%d", root->data);
            c++;
        }
        else
            printf(" %d", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        if (c == 0)
        {
            printf("%d", root->data);
            c++;
        }
        else
            printf(" %d", root->data);
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
        if (c == 0)
        {
            printf("%d", root->data);
            c++;
        }
        else
            printf(" %d", root->data);
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

struct node *delete (struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
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
        struct node *temp = min_value(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

struct node *min_value(struct node *root)
{
    struct node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *max_value(struct node *root)
{
    struct node *current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

int main()
{
    int i;
    struct node *root = NULL, *newnode;
    for (i = 0; i < n; i++)
    {
        newnode = create();
        if (root == NULL)
            root = newnode;
        else
            insert(root, newnode);
    }
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    c = 0;
    printf("Postorder: ");
    postorder(root);
    printf("\n");
}
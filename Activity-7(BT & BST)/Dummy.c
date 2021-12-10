#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) 
{
  if (root == NULL) 
  return;
  else
  {
      inorderTraversal(root->left);
      //if(root==NULL)
      //printf("%d", root->data);
      //else
      printf("%d ->", root->data);
      inorderTraversal(root->right);
  }
}

// Preorder traversal
void preorderTraversal(struct node* root) 
{
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) 
{
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->data);
}


struct node* createNode() 
{
  int data; 
  struct node* newNode = malloc(sizeof(struct node));
  printf("Enter element: ");
  scanf("%d",&data);
  if(data==-1)
  return 0;
  newNode->data = data;
  printf("Left Child ");
  newNode->left =createNode();
  printf("Right Child ");
  newNode->right =createNode();
  return newNode;
}

// struct node* insertLeft(struct node* root, int value) 
// {
//   root->left = createNode(value);
//   return root->left;
// }


// struct node* insertRight(struct node* root, int value) 
// {
//   root->right = createNode(value);
//   return root->right;
// }

int main() 
{
    printf("\n");
    struct node* root = createNode();
//   insertLeft(root, 2);
//   insertRight(root, 3);
//   insertLeft(root->left, 4);
//   insertRight(root->left, 5);

  printf("\nInorder traversal  : ");
  inorderTraversal(root);

  printf("\n\nPreorder traversal : ");
  preorderTraversal(root);

  printf("\n\nPostorder traversal: ");
  postorderTraversal(root);
  printf("\n\n");
}
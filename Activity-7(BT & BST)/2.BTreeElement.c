#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int data;
  struct node* left;
  struct node* right;
};


struct node* createNode(int value) 
{
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}


struct node* insertLeft(struct node* root, int value) 
{
  root->left = createNode(value);
  return root->left;
}


struct node* insertRight(struct node* root, int value) 
{
  root->right = createNode(value);
  return root->right;
}


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
      printf("%d -> ", root->data);
      inorderTraversal(root->right);
  }
}

void preTraversal(struct node* root) 
{
  if (root == NULL) 
  return;
  else
  {
      printf("%d -> ", root->data);
      preTraversal(root->left);
      preTraversal(root->right);
  }
}

void postTraversal(struct node* root) 
{
  if (root == NULL) 
  return;
  else
  {
      postTraversal(root->left);
      postTraversal(root->right);
      printf("%d -> ", root->data);
  }
}

int search(int item,struct node* root)
{
  if(root==NULL)
  return -1;
  if(root->data==item)
  return 1;
  if(root->left!=NULL)
  search(item, root->left);
  if(root->right!=NULL)
  search(item, root->right);
}

int main() 
{
  struct node* root = createNode(12);
  insertLeft(root, 45);
  insertRight(root, 23);
  insertLeft(root->left, 8);
  insertRight(root->left, 11);
  insertLeft(root->right, 9);

  printf("\nInorder traversal: ");
  inorderTraversal(root);

  printf("\nPreorder traversal: ");
  preTraversal(root);

  printf("\nPostorder traversal: ");
  postTraversal(root);
  
  // int item;
  // printf("\n\nEnter item to be searched: ");
  // scanf("%d",&item);
  // int f=search(item,root);
  // if(f==1)
  // printf("%d is found",item);
  // else
  // printf("%d is not found",item);
  printf("\n\n");
}
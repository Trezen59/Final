#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node* lptr;
  struct node* rptr;
};


void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->lptr);
  printf("%d ", root->info);
  inorderTraversal(root->rptr);
}


void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ", root->info);
  preorderTraversal(root->lptr);
  preorderTraversal(root->rptr);
}


void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->lptr);
  postorderTraversal(root->rptr);
  printf("%d ", root->info);
}


struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->info = value;
  newNode->lptr = NULL;
  newNode->rptr = NULL;

  return newNode;
}


struct node* insertLeft(struct node* root, int value) {
  root->lptr = createNode(value);
  return root->lptr;
}


struct node* insertRight(struct node* root, int value) {
  root->rptr = createNode(value);
  return root->rptr;
}

int main() {
  struct node* root = createNode(10);
  
  insertLeft(root, 11);
  insertRight(root, 8);

  insertLeft(root->lptr, 9);
  insertRight(root->lptr, 6);
  
  insertLeft(root->lptr->lptr, 5);
  insertRight(root->lptr->lptr, 3);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
  printf("\n");
}

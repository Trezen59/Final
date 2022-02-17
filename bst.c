#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *lptr, *rptr;
};

struct node *new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	temp->lptr = temp->rptr = NULL;
	return temp;
}

void inorder(struct node *root){
	if(root != NULL){
		inorder(root->lptr);
		printf("%d ", root->info);
		inorder(root->rptr);
	}
}

struct node *insert(struct node *node, int data){

	if(node == NULL) return new_node(data);
	if(data < node->info)
		node->lptr = insert(node->lptr, data);
	else
		node->rptr = insert(node->rptr, data);
	return node;
}

struct node *minValueNode(struct node *node){
	struct node *current = node;
	while(current && current->lptr != NULL)
		current = current->lptr;
	
	return current;
}

struct node *delete(struct node *root, int data){
	if(root == NULL) return root;
	
	if (data < root->info)
		root->lptr = delete(root->lptr, data);
	else if (data >root->info)
		root->rptr = delete(root->rptr, data);
	
	else{
		if(root->lptr == NULL){
			struct node *temp = root->rptr;
			free(root);
			return temp;
		}
		else if(root->rptr == NULL){
			struct node *temp = root->lptr;
			free(root);
			return temp;
		}
		struct node *temp = minValueNode(root->rptr);
		root->info = temp->info;
		root->rptr = delete(root->rptr, temp->info);
	}
	
	return root;
}


int main(){
	
	struct node *root = NULL;
	
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 9);
	root = insert(root, 10);
	root = insert(root, 9);
	root = insert(root, 7);
	
	printf("Inorder transversal : ");
	inorder(root);
	
	printf("\nAfter deleting 10\n");
	root = delete(root, 10);
	printf("Inorder transversal : ");
	inorder(root);
	printf("\n");
	
return 0;
}

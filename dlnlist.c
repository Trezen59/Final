#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *lptr;
	struct node *rptr;
};

void insert(struct node **first_ref, int data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->info = data;
	new_node->rptr = *first_ref;
	new_node->lptr = NULL;
	if((*first_ref) != NULL){
		(*first_ref)->lptr = new_node;
	}
	
	(*first_ref) = new_node;
}

void delete(struct node **first_ref, struct node *key){
	if((*first_ref) == NULL || key == NULL){
		return;
	}
	if((*first_ref) == key){
		(*first_ref) = key->rptr;
	}
	if(key->rptr != NULL){
		key->rptr->lptr = key->lptr;
	}
	if(key->lptr != NULL){
		key->lptr->rptr = key->rptr;
	}
	free(key);
}

void display(struct node *node1){
	struct node *last;
	while(node1 != NULL){
		printf("%d ", node1->info);
		last = node1;
		node1 = node1->rptr;
	}
	printf("\n");
}


int main(){
	struct node *head = NULL;
	
	insert(&head, 10);
	insert(&head, 20);
	insert(&head, 30);
	delete(&head, head->rptr);
	display(head);
	
return 0;

}

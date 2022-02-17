#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

void insertFirst(int data,struct node **first_ref,struct node **last_ref){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->info = data;
	if((*first_ref) == NULL){
		new_node->link = new_node;
		*first_ref = *last_ref = new_node;
	}
	else{
		new_node->link = *first_ref;
		(*last_ref)->link = new_node;
		*first_ref = new_node;
	}
	return;
}

void insertLast(int data, struct node **first_ref, struct node **last_ref){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->info = data;
	if((*first_ref) == NULL){
		new_node->link = new_node;
	}	
	else{
		new_node->link = *first_ref;
		(*last_ref)->link = new_node;
		*last_ref = new_node;
	}
	return;
}

void insertSorted(int data, struct node **first_ref, struct node **last_ref){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->info = data;
	if((*first_ref) == NULL){
		new_node->link = new_node;
		*first_ref = *last_ref = NULL;
		return;
	}
	if(new_node->info <= (*first_ref)->info){
		new_node->link = *first_ref;
		(*last_ref)->link = new_node;
		*first_ref = new_node;
		return;
	}
	struct node *temp = *first_ref;
	
	while(temp != (*last_ref) && new_node->info >= temp->link->info){
		temp = temp->link;
	}
	new_node->link = temp->link;
	temp->link = new_node;
	if(temp == (*last_ref)){
		*last_ref = new_node;
	}
	return;
}

void delete(struct node *ref, struct node **first_ref, struct node **last_ref){
	if((*first_ref) == NULL){
		printf("empty list\n");
		return;
	}
	struct node *temp = *first_ref;
	struct node *pred;
	while(temp != (ref) && temp != (*last_ref)){
		pred = temp;
		temp = temp->link;
	}
	if(temp != (ref)){
		printf("node not found\n");
		return;
	}
	if((ref) == (*first_ref)){
		*first_ref = (*first_ref)->link;
		(*last_ref)->link = *first_ref;
	}
	else{
		pred->link = (ref)->link;
	} 
	if((ref) == (*last_ref)){
		*last_ref = pred;
	}
	free(ref);
}

void display(struct node **first_ref){
	struct node *temp = *first_ref;

	if((*first_ref) == NULL){
		printf("empty list \n");
	}
	else{
		printf("List : ");
		do{
			printf("%d ", temp->info);
			temp = temp->link;
		}while(temp != (*first_ref));
		printf("\n");
	}
}


int main(){

	struct node *first = NULL;
	struct node *last = NULL;
	
	insertFirst(40, &first, &last);
	insertFirst(30, &first, &last);
	insertFirst(20, &first, &last);
/*	insertSorted(41, &first, &last);*/
	insertFirst(10, &first, &last);
/*	insertSorted(35, &first, &last);*/
/*	insertLast(50, &first, &last);*/
/*	insertSorted(39, &first, &last);*/
	delete(first->link, &first, &last);   // delete second element 20
	
	display(&first);

return 0;
}

#include<stdio.h>
#include<stdlib.h>


struct node{
	int info;
	struct node *link;
};


void insert(struct node ** first_ref, int new_info){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->info = new_info;
	new_node->link = (*first_ref);
	(*first_ref) = new_node;
	
}

void insertLast(struct node ** first_ref, int new_info){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *last = *first_ref;
	
	new_node->info = new_info;
	new_node->link = NULL;
	
	if(*first_ref == NULL){
		*first_ref = new_node;
		return;
	}
	
	while(last->link != NULL){
		last = last->link;
	}
	last->link = new_node;
	return;
}

void insertBefore(struct node **first_ref, int val, int before){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	new_node->info = val;
	new_node->link = NULL;
	if((*first_ref) == NULL){
		*first_ref = new_node;
	}
	else{
		struct node *ptr, *temp;
		ptr = *first_ref;
		
		while(ptr->info != before){
			temp = ptr;
			ptr = ptr->link;
		}
		new_node->link = ptr;
		temp->link = new_node;
	}
}

void insertAfter(struct node **first_ref, int val, int after){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	
	if((*first_ref) == NULL){
		printf("Error");
		return;
	}
	new_node->info = val;
	new_node->link = (*first_ref)->link;
	(*first_ref)->link = new_node;
}

void insertSorted(struct node ** first_ref, int new_info){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *save = *first_ref;
	new_node->info = new_info;
	if(*first_ref == NULL){
		new_node->link = NULL;
		return;
	}
	if(new_node->info <= (*first_ref)->info){
		new_node->link = *first_ref;
	}
	while(save->link != NULL && new_node->info >= save->link->info){
		save = save->link;
	}
	new_node->link = save->link;
	save->link = new_node;
	return;
}

int countNodes(struct node **first_ref){
	struct node *save = *first_ref;
	int count = 0;
	if(*first_ref == NULL){
		count = 0;
	}
	while(save != NULL){
		count = count + 1;
		save = save->link;
		
	}
	return count;
}

void display(struct node *node1){
	while(node1 != NULL){
		printf(" %d ", node1->info);
		node1 = node1->link;
	}
}

void delete(struct node **first_ref, int key){
	struct node *temp = *first_ref, *prev;
	
	if(temp != NULL && temp->info == key){
		*first_ref = temp->link;
		free(temp);
		return;
	}
	while(temp != NULL && temp->info != key){
		prev = temp;
		temp = temp->link;
	}
	if(temp == NULL){
		return;
	}
	prev->link = temp->link;
	free(temp);
}

int main(){

	struct node *head = NULL;
	
	while(1){
	
		int choice;
		
		printf("1. Insert\n2. Insert Last\n3. Insert Before\n4. Insert After\n5. Insert Sorted\n6. Count Nodes\n7. Delete\n8. Display\n9. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		
		if(choice<=9){
			switch(choice){
				int info1, info2, info3, info4, info5, after, before, del, count6;
				
				case 1:
					printf("enter the value to enter : ");
					scanf("%d",&info1);
					insert(&head, info1);
					break;
					
				case 2:
					
					printf("enter the value to insert Last : ");
					scanf("%d",&info2);
					insertLast(&head, info2);
					break;
					
				case 3:
					
					printf("enter the value to insert before : ");
					scanf("%d",&info3);
					printf("before : ");
					scanf("%d",&before);				
					insertBefore(&head, info3, before);
					break;
					
				case 4:
					
					printf("enter the value to insert after : ");
					scanf("%d",&info4);
					printf("after : ");
					scanf("%d",&after);
					insertAfter(&head, info4, after);
					break;
					
				case 5:
					
					printf("enter the value to insert sorted : ");
					scanf("%d",&info5);
					insertSorted(&head, info5);
					break;
					
				case 6:
					
					count6 = countNodes(&head);
					printf("count of nodes : %d\n", count6);
					break;
					
				case 7:
					
					printf("Enter the value to delete : ");
					scanf("%d", &del);
					delete(&head, del);
					break;
				
				case 8:
					display(head);
					printf("\n");
					break;
					
				case 9:
					exit(1);
					break;
			}
		}
	}
	
	
return 0;
}

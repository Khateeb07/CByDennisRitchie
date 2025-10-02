#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
};
void createList();
void insertNode(struct node**hpointer, int pos);
void deleteNode(struct node**hpointer, int pos);
void traverseList();
int main(int argc, char* argv[]){
	struct node *head=NULL;
	int option;
	while(1){
		printf("\n1. Create List\n");
		printf("2. Traverse List\n");
		printf("3. Insert Node???\n");
		printf("4. Delete Node???\n");
		printf("10. Exit\n");
		printf("Enter the option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("List Creation started: \n");
				createList(&head);
				printf("List Created\n");
				break;
			case 2:
				traverseList(&head);
				printf("List Traversed\n");
				break;
			case 3:
				int pos1;
				printf("Enter the position: \n");
				scanf("%d",&pos1);
				insertNode(&head, pos1);
				printf("Node Inserted\n");
				break;
			case 4:
				int pos;
				printf("Enter the position: \n");
				scanf("%d",&pos);
				deleteNode(&head, pos);
				printf("Node Deleted\n");
				break;
			case 10:
				exit(0);
			default:
				printf("Wrong option\n");
		}
	}
	return 0;
}

void createList(struct node** hpointer){
	int non;
	printf("Enter number of nodes to be created: ");
	scanf("%d",&non);
	struct node* p;
	for(int i=1; i<=non; i++){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		printf("\nEnter node %d's data: ", i);
		scanf("%d",&temp->data);
		if(i==1){
			*hpointer=temp;
			p=*hpointer;
		}
		else{
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
}
void insertNode(struct node** hpointer, int pos){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	printf("Enter data of the node: ");
	scanf("%d",&temp->data);
	if(pos==1){
		temp->next=*hpointer;
		*hpointer=temp;
	}
	else{
		struct node* p=*hpointer;
		int count=1;
		while(p->next!=NULL && count<pos-1){
			p=p->next;
			count++;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
void deleteNode(struct node** hpointer, int pos){
	struct node*p=*hpointer;
	struct node*q=*hpointer;
	if(pos==1){
		*hpointer=p->next;
		p->next=NULL;
		free(p);
	}
	else{
		int count=1;
		while(p->next!=NULL && count<pos){
			q=p;
			p=p->next;
			count++;
		}
		q->next=p->next;
		p->next=NULL;
		free(p);
	}
}
void traverseList(struct node** hpointer){
	struct node* p=*hpointer;
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}


#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node** new();
void add(struct node**, int);
void traversal(struct node**);
void deleteNode(struct node**, int);
void insertNode(struct node**, int, int);
int main(int argc, char* argv[]) {
	int option;
	while(2) {
		printf("Please enter an option\n");
		printf("1. To create new Linked List\n");
		printf("2. To add node at last\n");
		printf("3. To traverse\n");
		printf("4. To delete a node at a particular position\n");
		printf("5. To add node at desired position\n");
		printf("6. Exit\n");
		scanf("%d", &option);
		switch(option) {
			case 1:
				struct node** head=new();
				break;
			case 2:
				printf("Enter value for the node:\n");
				int val;
				scanf("%d", &val);
				add(head, val);
				break;
			case 3:
				traversal(head);
				break;
			case 4:
				printf("Enter position:\n");
				int p;
				scanf("%d", &p);
				deleteNode(head, p);
				break;
			case 5:
				printf("Enter position:\n");
				int pos;
				scanf("%d", &pos);
				printf("\nEnter value:\n");
				int value;
				scanf("%d", &value);
				insertNode(head, pos, value);
			case 6:
				exit(0);
			default:
				printf("Invalid operation\n");
				break;
		}
	}
}
struct node** new() {
	struct node** temp=(struct node**)malloc(sizeof(struct node));
	*temp=NULL;
	return temp;
}
void add(struct node** temp, int data) {
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->next=NULL;
	if(*temp==NULL)
		*temp=p;
	else {
		struct node* q=*temp;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
	}
}
void traversal(struct node** temp) {
	struct node* q=*temp;
	while(q!=NULL) {
		printf("%d\t", q->data);
		q=q->next;
	}
	printf("\n");

}
void deleteNode(struct node** temp, int pos) {
	struct node* q=*temp;
	struct node* p=*temp;
	if(p==NULL) {
		printf("Linked list is empty\n");
		return;
	}
	if(pos==1) {
		*temp=p->next;
		p->next=NULL;
		free(p);
	} else {
		int i=1;
		while(i<pos && p->next!=NULL) {
			i++;
			q=p;
			p=p->next;
		}
		if(pos==i) {
			q->next=p->next;
			p->next=NULL;
			free(p);
		}
	}
}
void insertNode(struct node** head, int pos, int val) {
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	struct node* p=*head;
	struct node* q=*head;
	if(pos==1) {
		temp->next=p;
		*head=temp;
	} else {
		int i=1;
		while(i<pos && q->next!=NULL) {
			i++;
			q=q->next;
		}
		p=q->next;
		temp->next=p;
		q->next=temp;
	}
}

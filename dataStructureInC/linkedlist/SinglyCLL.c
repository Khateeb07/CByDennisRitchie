#include <stdio.h>
#include <stdlib.h>
#include "SCLL.h"
t create(int);
void deleteNode(t*, int);
void insert(t*, int, int);
void traverse(t);
int main(int argc, char* argv[]) {
        int option, data, pos, result, size;
	while(1){
		printf("\n1. Create linked list\n");
		printf("2. Traverse List\n");
		printf("3. Insert Node\n");
		printf("4. Delete Node\n");
		printf("5. Exit\n");
		printf("Enter the option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter size of linked list: ");
				scanf("%d",&size);
				t head=create(size);
				break;
			case 2:
				traverse(head);
				printf("\nList Traversed\n");
				break;
			case 3:
				printf("Enter position: \n");
				scanf("%d", &pos);
				printf("Enter data: \n");
				scanf("%d", &data);
				insert(&head, pos, data);
				break;
			case 4:
				printf("Enter position: \n");
				scanf("%d", &pos);
				deleteNode(&head, pos);
				break;
			case 5:
				exit(0);
			default:
				printf("Wrong option\n");
		}
	}
	return 0;
}
void deleteNode(t* head, int pos) {
	t p=*head;
	t q=*head;
	if(*head==NULL && pos>=1)
		printf("Invalid position\n");
	else if(*head!=NULL && pos==1) {
		while(q->next!=*head)
			q=q->next;
		*head=p->next;
		p->next=NULL;
		q->next=*head;
		free(p);
	} else if(*head!=NULL && pos>1) {
		int count=1;
		while(p->next!=*head && count<pos) {
			count++;
			q=p;
			p=p->next;
		}
		q->next=p->next;
		p->next=NULL;
		free(p);
	}
}
void insert(t* p, int pos, int data) {
	t temp=(t)malloc(sizeof(node));
	temp->data=data;
	if(*p==NULL && pos>1)
		printf("Invalid position\n");
	else if(*p==NULL && pos==1) {
		temp->next=temp;
		*p=temp;
	} else if(*p!=NULL && pos==1) {
		temp->next=*p;
		*p=temp;
		temp->next->next=*p;
	} else if(p!=NULL && pos>1) {
		t q=*p;
		int count=1;
		while(q->next!=*p && count<pos-1) {
			count++;
			q=q->next;
		}
		if(count==pos-1) {
			q->next=temp;
			temp->next=*p;
		} else
			printf("Invalid position\n");
	}
}
t create(int num) {
	t temp, head=NULL;
	for(int i=1; i<=num; i++) {
		temp=(t)malloc(sizeof(node));
		temp->next=temp;
		printf("Enter data\n");
		scanf("%d", &temp->data);
		if(head==NULL) {
			head=temp;
		} else {
			t p=head;
			while(p->next!=head) {
				p=p->next;
			}
			p->next=temp;
			temp->next=head;
		}
	}
	return head;
}
void traverse(t head) {
	t p=head;
	if(p!=NULL) {
		do {
			printf("%d\t", p->data);
			p=p->next;
		} while(p!=head);
		printf("\n");
	} else {
		printf("Empty List\n");
	}
}

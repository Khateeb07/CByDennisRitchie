#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* next;
}*front=NULL;
struct node* rear=NULL;
int enqueue(int);
int dequeue();
int main(int argc, char* argv[]) {
	int option, data, enq, deq;
	while(1) {
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("10. Exit\n");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("Enter data for enqueue: ");
				scanf("%d", &data);
				enq=enqueue(data);
				if(enq==0)
					printf("Queue is full\n");
				else
					printf("Data pushed successfully\n");
				break;
			case 2:
				deq=dequeue();
				if(deq==-1)
					printf("Queue is empty\n");
				else
					printf("Dequeued: %d\n", deq);
				break;
			case 10:
				exit(0);
			default:
				printf("Wrong choice\n");
				break;
		}
	}
	return 0;
}
int enqueue(int data) {
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(temp!=NULL) {
		temp->data=data;
		temp->next=NULL;
		if(front==NULL && rear==NULL) {
			front=temp;
			rear=temp;
		} else if(front!=NULL && rear!=NULL) {
			rear->next=temp;
			rear=temp;
		}
		return 1;
	} else
		return 0;
}
int dequeue() {
	int data, flag=0;
	if(front==NULL && rear==NULL) {
		return -1;
	} else {
		struct node* p=front;
		if(front->next!=NULL)
			front=front->next;
		else
			flag=1;
		p->next=NULL;
		data=p->data;
		free(p);
		if(flag==1) {
			front=NULL;
			rear=NULL;
		}
	}
	return data;
}

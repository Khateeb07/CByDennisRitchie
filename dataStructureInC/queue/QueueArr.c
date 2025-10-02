#include <stdio.h>
#include <stdlib.h>
#define LEN 10
int queue[LEN];
int front=-1;
int rear=-1;
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
	if(rear==LEN-1)
		return 0;
	queue[++rear]=data;
	if(front==-1) {
		front=rear;
	}
	return 1;
}
int dequeue() {
	if((front>rear) || (front==-1 && rear==-1)) {
		front=-1;
		rear=-1;
		return -1;
	}
	return queue[front++];
}

#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
}*front=NULL, *rear=NULL;
int enqueue(int);
int dequeue();
int main(int argc, char* argv[]){
	int option, data, result;
	while(1){
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:	printf("Enter data:\n");
				scanf("%d",&data);
				result=enqueue(data);
				if(result==0)
					printf("Oi!!! I'm all full.. I can't take it anymore :(\n");
				break;
			case 2: result=dequeue();
				if(result==-1)
					printf("I'm Hungry... Feed me some!!\n");
				else
					printf("%d\n", result);
				break;
			case 3: printf("See you later...\n");
				exit(0);
			default: printf("Sorry :<\nCan't understand your Command...\n");
		}
	}
	return 0;
}
int enqueue(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
		return 0;
	temp->data=data;
	temp->next=NULL;
	if(front==NULL && rear==NULL){
		front=temp;
		rear=temp;
		return 1;
	}
	rear->next=temp;
	rear=temp;
	return 1;
}
int dequeue(){
	if(front==NULL && rear==NULL)
		return -1;
	struct node* temp=front;
	front=temp->next;
	temp->next=NULL;
	int x=temp->data;
	free(temp);
	if(front==NULL)
		rear=NULL;
	return x;
}

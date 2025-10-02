#include <stdio.h>
#include <stdlib.h>
int enqueue(int);
int dequeue();
int queue[10];
int front=-1;
int rear=-1;
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
	int len=sizeof(queue)/sizeof(queue[0]);
	if(rear==len-1)
		return 0;
	queue[++rear]=data;
	if(front==-1)
		front=rear;
	return 1;
}
int dequeue(){
	if((front>rear)||(front==-1 && rear==-1)){
		front=-1;
		rear=-1;
		return -1;
	}
	return queue[front++];
}

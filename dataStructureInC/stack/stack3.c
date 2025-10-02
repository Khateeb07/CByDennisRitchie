//When array is declared inside main using calloc//
#include <stdio.h>
#include <stdlib.h>
int push(int, int*);
int pop(int*);
int peek(int*);
int len=5;
int top=-1;
int main(int argc, char* argv[]){
	int option, data, result;
	int *stack=(int*)calloc(len, sizeof(int));
	while(1){
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter data\n");
				scanf("%d",&data);
				result=push(data, &stack[0]);
				if(result==0)
					printf("Can't push :<o\n");
				break;
			case 2:
				result=pop(&stack[0]);
				if(result==-1)
					printf("Stack is empty\n");
				else
					printf("%d\n", result);
				break;
			case 3:
				result=peek(&stack[0]);
				if(result==-1)
					printf("Stack is empty\n");
				else
					printf("%d\n", result);
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong Choice\n");
		}
	}
	return 0;
}
int push(int d, int* sp){
	if(top==len-1){
		return 0;
	}
	sp[++top]=d;
	return 1;
}
int pop(int *sp){
	if(top==-1)
		return -1;
	return sp[top--];
}
int peek(int* sp){
	if(top==-1)
		return -1;
	return sp[top];
}


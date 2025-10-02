//When array is declared globally//
#include <stdio.h>
#include <stdlib.h>
int push(int);
int pop();
int peek();
int stack[5]={0};
int top=-1;
int main(int argc, char* argv[]){
	int option, data, result;
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
				result=push(data);
				if(result==0)
					printf("Can't push :<o\n");
				break;
			case 2:
				result=pop();
				if(result==-1)
					printf("Stack is empty\n");
				else
					printf("%d\n", result);
				break;
			case 3:
				result=peek();
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
int push(int d){
	int len=sizeof(stack)/sizeof(stack[0]);
	if(top==len-1){
		return 0;
	}
	stack[++top]=d;
	return 1;
}
int pop(){
	if(top==-1)
		return -1;
	return stack[top--];
}
int peek(){
	if(top==-1)
		return -1;
	return stack[top];
}

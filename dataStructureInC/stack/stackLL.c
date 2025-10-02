#include <stdio.h>
#include <stdlib.h>
int push(int);
int pop();
int main(int argc, char* argv[]) {
	int option, data, pu, po;
	while(1) {
		printf("1. Push operation\n");
		printf("2. Pop operation\n");
		printf("10. Exit\n");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("Enter data to be pushed: ");
				scanf("%d", &data);
				pu=push(data);
				if(pu==0)
					printf("Stack Overflow\n");
				else
					printf("Data pushed successfully\n");
				break;
			case 2:
				po=pop();
				if(po==-1)
					printf("Stack Underflow\n");
				else
					printf("Popped: %d\n", po);
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

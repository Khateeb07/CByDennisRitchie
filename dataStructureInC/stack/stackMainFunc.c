#include <stdio.h>
#include <stdlib.h>
int pop();
int push(int);
int topf();
int main(int argc, char* argv[]) {
	int option, data, result, top;
	while(1) {
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Top\n");
		printf("10. Exit\n");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("Enter data to be pushed: ");
				scanf("%d", &data);
				data=push(data);
				if(data==-1)
					printf("Stack Overflow\n");
				else
					printf("Data pushed successfully\n");
				break;
			case 2:
				result=pop();
				if(result==-1)
					printf("Stack Underflow\n");
				else
					printf("Popped: %d\n", result);
				break;
			case 3:
				top=topf();
				if(top==-1)
					printf("Stack Underflow\n");
				else
					printf("Top of Stack: %d\n", top);
				break;
			case 10:
				exit(0);
			default:
				printf("\nWrong choice\n");
		}
	}
	return 0;
}

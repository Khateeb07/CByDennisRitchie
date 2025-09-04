#include <stdio.h>
int main(){
	int option;
	printf("Enter option's value\n");
	scanf("%d", &option);
	switch(option){
		case 'a':
			printf("Case a\n");
			break;
		case 2+3:
			printf("Case 2+3\n");
			break;
		case 10&2:
			printf("Case 10&2\n");
			break;
		default:
			printf("Default case\n");
			break;
		case 'c':
			printf("Case c\n");
			break;
	}
	return 0;
}

#include <stdio.h>
int main(int argc, char* argv[]) {
	char name[50];
	printf("Enter a string: ");
	scanf("%s", name);
	int length=0;
	while(name[length]!='\0'){
		length++;
	}
	printf("Length of string=%d\n",length);
	return 0;
}

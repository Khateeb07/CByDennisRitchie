#include <stdio.h>
int main() {
	char name[50];
	printf("Enter a name\n");
	scanf("%[^\n]s", &name[0]);	// Takes input string until \n is encountered.
//	scanf("%s", &name);	// Takes input string until ' ' is encountered.
	printf("name is %s\n", name);
	char name2[50];
	scanf("%[^\t]s", &name2);	// Takes input string until tabstop '\t' is encountered.
	printf("name is %s\n%ld\n", name2, sizeof(name));
	return 0;
}

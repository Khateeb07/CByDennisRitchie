#include <stdio.h>
int main() {
	int x;
	int y;
	printf("Enter 2 numbers:\n");
	scanf("%d%d", &x, &y);
	int z = x+y;
	printf("Result = %d\n", z);
	return 0;
}

#include <stdio.h>
int main(){
	int x=10;
	const int *p=&x;
//	*p=20;		// Error: Bcoz p is a pointer to const int, so value at location pointed by p can't be changed with p
	printf("x=%d\n", x);
	x=20;
	printf("x=%d\n", x);
	const int y;
//	y=34;		// Error: Bcoz y is an uninitialized const variable and has a garbage value in it. Value of y can't be updated.
	printf("y=%d\n", y);
	return 0;
}

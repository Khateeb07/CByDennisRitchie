#include <stdio.h>
void counter(int);
int main(int argc, char* argv[]) {
	register int x=10;
	printf("x=%d\n", x);
//	int* p=&x;	// x's addess cannot be stored bcoz it is stored in a register and may not have a memory address.
	counter(x);
	return 0;
}
void counter(int a) {
	for(int i=0; i<5; i++) {
		printf("%d\t", ++a);
	} printf("\n");
}

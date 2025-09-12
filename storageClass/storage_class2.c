#include <stdio.h>
int main(int argc, char* argv[]) {
	int x=10;
	printf("x=%d\n", x);
	if(1) {
		int x=20;
		printf("x=%d\n", x);
	}
	printf("x=%d\n", x);
	return 0;
}

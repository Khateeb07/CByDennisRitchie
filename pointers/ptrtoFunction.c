#include <stdio.h>
int add(int x, int y) {
	return x+y;
}
int diff(int x, int y) {
	return x-y;
}
int main(int argc, char* argv[]) {
	int (*fp)(int, int);
	fp=add;
	int x=5, y=2;
	printf("x=%d\ty=%d\n", x, y);
	printf("Addition: %d\n", fp(x, y));
	fp=diff;
	printf("Subtraction: %d\n", fp(x, y));
	return 0;
}

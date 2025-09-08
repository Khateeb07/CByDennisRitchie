#include <stdio.h>
int add(int x, int y) {
	return x+y;
}
int diff(int x, int y) {
	return x-y;
}
int caller(int (*fp)(int, int), int x, int y) {
	return fp(x, y);
}
int main(int argc, char* argv[]) {
	int x=10, y=3, (*fp)(int, int);
	printf("x=%d\ty=%d\n", x, y);
	printf("Addition: %d\n", caller(add, x, y));		// caller(&add, x, y) this is also correct
	printf("Subtraction: %d\n", caller(&diff, x, y));	// caller(&diff, x, y) this is also correct
	return 0;
}

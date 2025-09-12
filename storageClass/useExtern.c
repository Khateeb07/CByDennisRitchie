#include <stdio.h>
void printer();
extern int x;
int main(int argc, char* argv[]) {
	x=200;
	printf("x=%d\n", x);
	printer();
	return 0;
}
void printer() {
	x=100;
	printf("x of printer: %d\n", x);
}

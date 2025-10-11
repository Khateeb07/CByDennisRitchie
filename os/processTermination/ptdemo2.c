#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void e1();
void e2();
int x=10;
int main(int argc, char* argv[]) {
	atexit(e1);
	atexit(e1);
	atexit(e2);
	printf("Exit handlers registered completely\n");
	printf("main function is about to complete\n");
	exit(1);
}
void e1() {
	printf("Exit handler 1\n");
	printf("x=%d\n", x);
}
void e2() {
	printf("Exit handler 2\n");
	printf("x=%d\n", x);
}


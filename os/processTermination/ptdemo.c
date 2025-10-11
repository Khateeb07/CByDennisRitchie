#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void e1(int, void*);
void e2(int, void*);
int x=10;
int main(int argc, char* argv[]) {
	on_exit(e1, (void*)&x);
	on_exit(e1, (void*)&x);
	on_exit(e2, (void*)&x);
	printf("Exit handlers registered completely\n");
	printf("main function is about to complete\n");
	exit(1);
}
void e1(int exitStatus, void* args) {
	printf("Exit status=%d\targ=%d\n", exitStatus, *((int*)args));
	printf("x=%d\n", x);
}
void e2(int exitStatus, void* args) {
	printf("Exit status=%d\targ=%d\n", exitStatus, *((int*)args));
	printf("x=%d\n", x);
}


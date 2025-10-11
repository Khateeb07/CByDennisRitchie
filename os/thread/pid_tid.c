#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char* argv[]) {
	printf("pid=%d\n", (int)getpid());
	printf("tid=%ld\n", (long)pthread_self());
	return 0;
}

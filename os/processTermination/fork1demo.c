#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
//	printf("I am in Lucnow\n");
	write(STDOUT_FILENO, "Hello Lucknow\n", 14);
	fork();
	return 0;
}

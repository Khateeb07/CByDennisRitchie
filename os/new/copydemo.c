#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {
	static int a=10;
	printf("Original process\n");
	pid_t pid;
	int* p=(int*)malloc(sizeof(int));
	*p=25;
	pid=fork();
	switch(pid) {
		case -1:
			printf("Could not fork\n");
			break;
		case 0:
			printf("Inside child\n");
			printf("%d\t%d\n", a, *p);
			printf("End of child\n");
			break;
		default:
			int q;
			wait(&q);
			printf("Inside parent\n");
			printf("%d\t%d\n", a, *p);
			printf("q=%d\n", q);
	}
	return 0;
}

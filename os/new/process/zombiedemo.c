#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char* argv[]) {
	printf("Process started\n");
	printf("PID=%d\n", (int)getpid());
	printf("PPID=%d\n", (int)getppid());
	pid_t pid;
	switch(pid=fork()) {
		case -1:
			printf("Did not fork\n");
			exit(EXIT_SUCCESS);
		case 0:
			printf("PID of child=%d\n", (int)getpid());
			printf("PPID of child=%d\n", (int)getppid());
			break;
		default:
			sleep(5);
			printf("Parent process terminated\n");
	}
	return 0;
}

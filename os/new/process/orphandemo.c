#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char* argv[]) {
	printf("PID=%d\n", (int)getpid());
	printf("PPID=%d\n", (int)getppid());
	pid_t pid=fork();
	if(pid==-1)
		printf("Fork did not work\n");
	else if(pid==0) {
		sleep(1);
		printf("PID of child=%d\n", (int)getpid());
		printf("PPID of child=%d\n", (int)getppid());
	} else {
		printf("PID of parent=%d\n", (int)getpid());
		printf("Parent process\n");
	}
	return 0;
}

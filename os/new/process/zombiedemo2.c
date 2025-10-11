#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <libgen.h>
#include <errno.h>

#define CMD_SIZE 200

int main(int argc, char* argv[]) {
	char cmd[CMD_SIZE];
	pid_t childPid;
	setbuf(stdout, NULL);
	printf("Parent PID=%d\n", (int)getpid());
	switch(childPid=fork()) {
		case -1:
			printf("fork\n");
		case 0:
			printf("Child (PID=%d) exiting\n", (int)getpid());
			_exit(EXIT_SUCCESS);
		default:
			sleep(3);
			snprintf(cmd, CMD_SIZE, "ps | grep %s", basename(argv[0]));
			system(cmd);
			if(kill(childPid, SIGKILL)==-1)
				printf("kill");
			sleep(3);
			printf("After sending SIGKILL to zombie (PID=%d):\n", (int)childPid);
			system(cmd);
			exit(EXIT_SUCCESS);
	}
	return 0;
}

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sigHandler(int);
int main(int argc, char* argv[]){
	if(signal(SIGINT, sigHandler)==SIG_ERR){
		printf("Can not call handler for SIGINT\n");
	}
	if(signal(SIGQUIT, sigHandler)==SIG_ERR){
		printf("Can not call handler for SIGQUIT\n");
	}
	while(1){
		static int x=0;
		x++;
		if(kill(getpid(), SIGINT)==-1)
			printf("kill not called\n");
		sleep(2);
		printf("x=%d\n", x);
	}
	return 0;
}
void sigHandler(int sig){
	if(sig==SIGINT){
		printf("SIGINT signal\n");
	}
	if(sig==SIGQUIT){
		printf("SIGQUIT signal\n");
	}
}

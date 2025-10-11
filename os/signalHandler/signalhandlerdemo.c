#include <stdio.h>
#include <signal.h>
#include<unistd.h>               //sleep() is defined in here...
static void sigHandler(int sig){
	printf("\nSignal handler called\n");
}

int main(int argc, char* argv[]){
	int j=0;
	signal(SIGINT, sigHandler);
	while(1){
		printf("%d\n", j);
		j++;
		sleep(3);
	}
	return 0;
}

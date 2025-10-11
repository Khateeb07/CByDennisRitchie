#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
	char command[50];
	int status;
	while(1){
		printf(">");
		scanf("%s", command);
		pid_t pid=fork();
		if(pid>0){
			wait(&status);
		}else{
			execl(command,"",(char*)NULL);
			exit(0);
		}
	}
	return 0;
}

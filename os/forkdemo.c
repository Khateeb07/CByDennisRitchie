#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[]){
	printf("Main begins from here...\n");
	pid_t pid=fork();
	if(pid==0){
		printf("Pid=%d\n", (int)pid);
		printf("getPid=%d\n", (int)getpid());
		printf("PPid=%d\n", (int)getppid());
//		execl("/bin/ls","-l");
	}else{
		printf("I am parent\n");
		printf("pid=%d\n", (int)pid);
		printf("process id=%d\n", (int)getpid());
		printf("PPid=%d\n", (int)getppid());
	}
	printf("End of main\n");
	return 0;
}

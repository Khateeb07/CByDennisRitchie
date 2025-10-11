#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* threadfn(void);

int main(int argc,char* arvg){
	pthread_t thr;
	int s;
	void* res;
	printf("pid main=%d\n", (int)getpid());
	s=pthread_create(&thr, NULL, threadfn(), NULL);
	if(s!=0){
		printf("Could not create thread\n");
		return 0;
	}
	return 0;
}

void* threadfn(void){
	printf("New Thread Started\n");
	pid_t pid=fork();
	if(pid==-1)
		printf("Fork not done\n");
	else if(pid==0) {
		printf("pid child=%d\n", (int)getpid());
		printf("tid child=%ld\n", (long)pthread_self());
	} else {
		printf("pid=%d\n", (int)getpid());
		printf("tid=%ld\n", (long)pthread_self());
	}
}

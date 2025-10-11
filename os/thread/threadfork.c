#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

static void* threadFunc(void*);
pthread_t tid;
static pid_t pid;
void* arg;
void* retval;

int main(int argc, char* argv[]) {
	printf("pid of main=%d\n", (int)getpid());
	printf("tid of main=%ld\n", (long)pthread_self());
	int signal;
	signal=pthread_create(&tid, NULL, threadFunc, &arg);
	if(signal!=0) {
		printf("There was an error creating the thread\n");
		return 0;
	}
	signal=pthread_join(tid, &retval);
	if(signal!=0) {
		printf("Thread could not be joined\n");
		return 0;
	}
	return 0;
}
static void* threadFunc(void* arg) {
	printf("pid inside threadFunc=%d\n", (int)getpid());
	printf("tid inside threadFunc=%ld\n", (long)pthread_self());
	pid=fork();
	int status;
	if(pid==-1)
		printf("Fork not possible\n");
	else if(pid==0) {
		printf("pid inside child=%d\n", (int)getpid());
		printf("tid inside child=%ld\n", (long)pthread_self());
		execlp("/home/zedskywalker/myDir/os/thread/pid", "pid", NULL);
	} else {
		wait(&status);
		printf("pid inside parent=%d\n", (int)getpid());
		printf("tid inside parent=%ld\n", (long)pthread_self());
	}
	return NULL;
}

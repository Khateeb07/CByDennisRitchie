#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

static void* threadfn(void*);

int main(int argc,char* arvg){
	pthread_t thr;
	int s;
	void* res;
	s=pthread_create(&thr,NULL,threadfn,NULL);
	if(s!=0){
		printf("Could not create thread\n");
		return 0;
	}
	//sleep(3);
	s=pthread_cancel(thr);
	if(s!=0){
		printf("Could not cancel thread\n");
		return 0;
	}
	s=pthread_join(thr,&res);
	if(s!=0){
		printf("Could not join thread\n");
		return 0;
	}
	if(res==PTHREAD_CANCELED){
		printf("thread was cancelled\n");;
	}else{
		printf("Thread was not cancelled\n");
	}
	return 0;
}

static void* threadfn(void* arg){
	int j;
	printf("New Thread Started\n");
	for(j=1; ;j++){
		printf("Loop %d\n",j);
		//sleep(1);
	}
	return NULL;
}

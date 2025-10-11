#include <stdio.h>
#include <pthread.h>
void* task1(void);
void* task2(void);
int main(int argc, char* argv[]) {
	printf("Main thread started\n");
	pthread_t tid, tid2;
	int arg, arg2;
	if(pthread_create(&tid, NULL, task1(), &arg))
		printf("Thread could not be created\n");
	else
//		pthread_join(tid, NULL);
	if(pthread_create(&tid2, NULL, task2(), &arg2))
		printf("Thread 2 could not be created\n");
	else
//		pthread_join(tid2, NULL);
	printf("Main thread ends\n");
//	printf("arg=%d\targ2=%d\n", arg, arg2);
	return 0;
}
void* task1(void) {
	for(int i=0; i<100; i++) {
		printf("%d\t", i);
	}
	printf("\n");
//	pthread_exit(NULL);
}
void* task2(void) {
	int sum=0;
	for(int i=0; i<100; i++)
		sum+=i;
	printf("Sum=%d\n", sum);
//	pthread_exit(NULL);
}

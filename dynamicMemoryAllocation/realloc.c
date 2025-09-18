#include <stdio.h>
#include <stdlib.h>
int main(){
	int* p=(int*)malloc(sizeof(int));
	*p=10;
	printf("%d\n",*p);
	int* q=(int*)realloc(p,sizeof(int)*2);
	printf("q=%d\tsizeof q=%ld\n",*q, sizeof(q));
	printf("%d\n",*p);
	return 0;
}

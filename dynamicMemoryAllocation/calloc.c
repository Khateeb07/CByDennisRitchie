#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	int* p=(int*) calloc(10, sizeof(int));
	for(int i=0; i<10; i++) {
		printf("%d\n", *(p+i));
	}
	return 0;
}

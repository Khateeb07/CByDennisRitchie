#include <stdio.h>
int main(int argc, char* argv[]) {
	int x=10;
	int* p;
	p=&x;
	printf("x=%d\n",x);
	*p=20;
	printf("x=%d\n",x);
	int k;
	k=*p;
	printf("k=%d\n",k);
	return 0;
}

#include <stdio.h>
int main(){
	int x=10;
	int *p=&x;
	int **q=&p;
	int ***s=&q;
	int k=**q;
	printf("k=%d\n", k);
	**q=20;
	printf("x=%d\n", x);
	return 0;
}

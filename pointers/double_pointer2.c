#include <stdio.h>
int main(){
	int x=10;
	int *p=&x;
	int **q=&p;
	int ***s=&q;
	int ****r=&s;
	printf("%p\n", &x);
	printf("%p\n", p);
	printf("%p\n", *q);
	printf("%p\n", &p);
	printf("%p\n", q);
	printf("%d\n", x);
	printf("%d\n", *p);
	printf("%d\n", **q);
	printf("%d\n", ***s);
	***s=20;
	printf("%d\n", x);
	printf("%d\n", ****r);
	****r=30;
	printf("%d\n", x);
	return 0;
}

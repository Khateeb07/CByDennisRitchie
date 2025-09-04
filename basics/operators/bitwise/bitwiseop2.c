#include <stdio.h>
int main(){
	unsigned int x=10;
	int a=x>>1;
	int b=x>>2;
	int c=x>>3;
	int d=x>>4;
	printf("a=%d\tb=%d\tc=%d\td=%d\n",a,b,c,d);
	printf("x=%d\n",x);
	return 0;
}

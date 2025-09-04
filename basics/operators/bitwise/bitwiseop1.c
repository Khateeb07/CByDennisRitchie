#include <stdio.h>
int main(){
	unsigned x=10;
	int a=x<<1;
	int b=x<<2;
	int c=x<<3;
	printf("a=%d\tb=%d\tc=%d\n",a,b,c);
	printf("x=%d\n",x);
	return 0;
}

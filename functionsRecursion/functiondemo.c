#include <stdio.h>
int add(int, int);
int main(){
	int a=10, b=20,c;
	c=add(a,b);
	printf("%d\n",c);
	return 0;
}
int add(int x, int y){
	int c=x+y;
	return c;
}

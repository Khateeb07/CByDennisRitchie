#include <stdio.h>
int main(){
	char x=10;
	char y=-10;
	char a=(char)(~x);
	char b=(char)(~y);
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	return 0;
}

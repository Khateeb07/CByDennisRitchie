#include <stdio.h>
int main(){
	unsigned int a=99;
	if((a&1)==0)
		printf("a is even\n");
	else
		printf("a is odd\n");
	return 0;
}

#include <stdio.h>
int main(){
	unsigned int x;
	printf("Enter a number:\n");
	scanf("%u",&x);
	if((x&(x-1))==0)
		printf("The number is in power of 2\n");
	else
		printf("The number is not in power of 2\n");
	return 0;
}

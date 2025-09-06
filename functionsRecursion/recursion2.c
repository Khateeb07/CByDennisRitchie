#include <stdio.h>
long factorial(unsigned int n){
	if(n==0 || n==1)
		return 1;
	return n*factorial(n-1);
}
int main(){
	unsigned int num;
	printf("Entered a positive number:\n");
	scanf("%u", &num);
	long result = factorial(num);
	printf("%ld\n", result);
	return 0;
}

#include <stdio.h>
long function(int x, unsigned int n){
	if(n==0)
		return 1;
	return x*function(x, n-1);
}
int main(){
	int x;
	unsigned int n;
	printf("Enter number and its power:\n");
	scanf("%d%u",&x,&n);
	long result=function(x,n);
	printf("%ld\n",result);
	return 0;
}


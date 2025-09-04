#include <stdio.h>
int main(){
	unsigned int a=99;
	int count=0;
	while(a!=0){
		count++;
		a=a&(a-1);
	}
	printf("Number of 1's=%d\n",count);
	return 0;
}

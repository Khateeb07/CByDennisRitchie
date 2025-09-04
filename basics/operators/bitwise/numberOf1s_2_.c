#include <stdio.h>
int main(){
	unsigned int x=10;
	int counter=0;
	while(x!=0){
		if(x&1==1)
			counter++;
		x=x>>1;
	}
	printf("Number of 1's = %d\n", counter);
	return 0;
}

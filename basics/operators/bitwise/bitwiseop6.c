#include <stdio.h>
int main(){
	int a=10;
	int b=20;
	int k=(a<=b)?a:b;
	printf("k=%d\n",k);
	int max(int x,int y){
		return (x>=y)?x:y;
	}
	int m=max(5,7);
	printf("m=%d\n",m);
	return 0;
}

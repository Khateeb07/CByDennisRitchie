#include <stdio.h>
void swap(int*, int*);
int main(){
	int x=10;
	int y=20;
	printf("x=%d\ty=%d\n",x,y);
	swap(&x,&y);
	printf("x=%d\ty=%d\n",x,y);
	return 0;
}
void swap(int* a, int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

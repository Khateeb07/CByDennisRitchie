#include <stdio.h>
void printArray(int *, int);
int a[5];
int f[8];
int main(){
	int b[5];
	int g[7];
	int c[5]={2,4,6,8,10};
	int d[10]={5,10,15};
	int e[5]={5};
	printArray(a,5);
	printArray(b,5);
	printArray(c,5);
	printArray(d,10);
	printArray(e,5);
	printArray(f,8);
	printArray(g,7);
	return 0;
}
void printArray(int arr[], int len){
	for(int i=0; i<len; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

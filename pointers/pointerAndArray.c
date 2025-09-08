#include <stdio.h>
void printArray(int*, int);
int main(){
	int arr[]={5,7,9,8,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	printArray(arr, len);
	return 0;
}
void printArray(int* a, int len){
	for(int i=0; i<len; i++){
//		printf("%d\t", a[i]);
		printf("%d\t", *(a+i));	//	*(a+i) used to access elements
//		printf("%d\t", i[a]);		i[a] used to access elements.
	}
	printf("\n");
}

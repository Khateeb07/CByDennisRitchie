#include <stdio.h>
void printArray(int *, int);
void swap(int*, int*);
void selectionSort(int*, int);
int main(){
	int arr[]={7, 3, 2, 8, 5, 4};
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("Array: \n");
	printArray(arr, len);
	printf("Sorted Array: \n");
	selectionSort(arr, len);
	printArray(arr, len);
	return 0;
}
void printArray(int *a, int len){
	for(int i=0; i<len; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
void swap(int* a, int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selectionSort(int* a, int len){
	int min;
	for(int i=1; i<len; i++){
		min=i-1;
		for(int j=i; j<len; j++){
			if(a[j]<a[min])
				min=j;
		}
		swap(&a[i-1], &a[min]);
	}
}

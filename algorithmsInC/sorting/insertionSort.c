#include <stdio.h>
void printArray(int *, int);
void swap(int*, int*);
void insertionSort(int*, int);
int main(){
	int arr[]={7, 3, 2, 8, 5, 4};
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("Array: \n");
	printArray(arr, len);
	printf("Sorted Array: \n");
	insertionSort(arr, len);
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
/*void insertionSort(int* a, int len){
	for(int i=0; i<len-1; i++){
		int j, k=a[i+1];
		for(j=i; j>=0; j--){
			if(a[j]>k)
				a[j+1]=a[j];
			else if(a[j]<k)
				break;
		}
		a[j+1]=k;
	}
}*/
void insertionSort(int* a, int len){
	int temp, j;
	for(int i=1; i<len; i++){
		temp=a[i];
		for(j=i-1; j>=0 && a[j]>temp; j--){
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

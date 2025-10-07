#include <stdio.h>
void printArray(int *, int);
void swap(int*, int*);
void bubbleSort(int*, int);
int main(int argc, char* argv[]){
	int arr[]={7, 3, 2, 8, 5, 4};
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("Array: \n");
	printArray(arr, len);
	printf("Sorted Array: \n");
	bubbleSort(arr, len);
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
/*void bubbleSort(int* a, int l){
	for(int i=0; i<l; i++){
		for(int j=0; j<l-i; j++){
			if(a[j]>a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
}*/
void bubbleSort(int* a, int len) {
	int flag=0;
	for(int i=1; i<len; i++) {
		flag=0;
		for(int j=1; j<len+1-i; j++) {
			if(a[j]<a[j-1]) {
				flag=1;
				swap(&a[j], &a[j-1]);
			}
		}
		if(flag==0)
			break;
	}
}

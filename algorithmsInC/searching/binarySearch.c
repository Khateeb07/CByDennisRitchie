#include <stdio.h>
void printArray(int *, int);
int binarySearch(int*, int, int, int);
int main(int argc, char* argv[]){
	int data, result, arr[]={2, 3, 4, 5, 7, 8};
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("Array: \n");
	printArray(arr, len);
	printf("Enter data to be searched: ");
	scanf("%d", &data);
	result=binarySearch(arr, 0, len, data);
	if(result!=-1)
		printf("Element found at index: %d\n", result);
	else
		printf("Element not found\n");
	return 0;
}
void printArray(int *a, int len){
	for(int i=0; i<len; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int binarySearch(int* arr, int si, int li, int data) {
	if(si<=li) {
		int mid=(si+li)/2;
		if(arr[mid]==data)
			return mid;
		else if(arr[mid]<data)
			return binarySearch(arr, mid+1, li, data);
		else
			return binarySearch(arr, si, mid-1, data);
	}
	return -1;
}

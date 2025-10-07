#include <stdio.h>
void printArray(int *, int);
int linearSearch(int*, int, int);
int main(int argc, char* argv[]){
	int data, result, arr[]={7, 3, 2, 8, 5, 4};
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("Array: \n");
	printArray(arr, len);
	printf("Enter data to be searched: ");
	scanf("%d", &data);
	result=linearSearch(arr, len, data);
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
int linearSearch(int* arr, int length, int data) {
	for(int i=0; i<length; i++)
		if(arr[i]==data)
			return i;
	return -1;

}

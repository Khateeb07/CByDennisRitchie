#include <stdio.h>
void printArray(int [][5], int, int);
int main(int argc, char* argv[]) {
	int arr[4][5]={{1, 2, 3, 4, 5}, {0, 2, 4, 6, 8}, {1, 3, 5, 7, 9}, {10, 20, 30, 40, 50}};
	printArray(arr, 4, 5);
	arr[2][2]=11;
	printArray(arr, 4, 5);
//	int arr[][5]		Supported by C, row length is optional
//	int arr[4][]		Supported by Java, column length is optional
	*(*(arr+1)+3)=7;
	printArray(arr, 4, 5);
	return 0;
}
void printArray(int a[][5], int r, int c) {
	printf("Array: \n");
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			printf("%d\t", *(*(a+i)+j));
		}
		printf("\n");
	}
}

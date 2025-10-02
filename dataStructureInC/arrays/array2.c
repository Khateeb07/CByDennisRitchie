#include <stdio.h>
void printArray(int *, int);
int main(){
	int arr[]={2,5,7,9,15};
	int len=sizeof(arr)/sizeof(arr[0]);
//	int sum=0;
	for(int i=1; i<len; i++){
//		sum+=arr[i];
		arr[i]=arr[i-1]+arr[i];
	}
/*	printf("%d\n",sum);
	printf("sum = ");
	for(int i=0; i<len; i++){
		if(i==len-1)
			printf("%d ",arr[i]);
		else
			printf("%d + ",arr[i]);
	}
	printf("\n");
*/	printArray(arr, len);
	return 0;
}

void printArray(int arr[], int len){
	for(int i=0; i<len; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

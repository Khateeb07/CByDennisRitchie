#include <stdio.h>
int max(int *, int);
int smax(int *, int);
void reverse(int *, int);
void printArray(int *, int);
int main(){
	int arr[]={5,2,8,9,15,3,17,4};
	int len=sizeof(arr)/sizeof(arr[0]);
/*	int maxNum=max(arr, len);
	printf("%d\n",maxNum);
	int smaxNum=smax(arr, len);
	printf("%d\n", smaxNum);*/
	reverse(arr, len);
	printArray(arr, len);
	return 0;
}
/*int max(int arr[], int len){
	int max=arr[0];
	int temp;
	for(int i=1; i<len; i++){
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
int smax(int arr[], int len){
	int smax=-1, max=-1;
	for(int i=0; i<len; i++){
		if(arr[i]>=max){
			smax=max;
			max=arr[i];
		}else if(arr[i]>smax)
			smax=arr[i];
	}
	return smax;
}*/
void reverse(int arr[], int len){
	int j=len-1, temp=0;
	for(int i=0; i<j; i++){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		j--;
	}
}
void printArray(int arr[], int len){
	for(int i=0; i<len; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

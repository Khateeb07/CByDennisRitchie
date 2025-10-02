#include <stdio.h>
int main(){
	int arr[]={2,5,6,3,19};
	int len=sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<len; i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	return 0;
}

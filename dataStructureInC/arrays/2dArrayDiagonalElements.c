#include <stdio.h>
int main(){
	int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int sum=0;
	int rows=sizeof(arr)/sizeof(arr[0]);
	int cols=sizeof(arr[0])/sizeof(arr[0][0]);
/*	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(i==j)
				sum+=arr[i][j];
		}
	}*/
	for(int i=0; i<rows; i++){
		sum+=arr[i][rows-1-i];
		printf("%d\t",arr[i][rows-1-i]);
	}
	printf("Sum=%d\n",sum);
	return 0;
}

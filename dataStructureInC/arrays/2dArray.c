#include <stdio.h>
int main(){
/*	int td[][5]={{1,2,3,4,5},{2,4,6,8,10},{1,3,5,7,9},{10,20,30,40,50}};
	td[2][2]=11;
	for(int i=0; i<4; i++){
		for(int j=0; j<5; j++){
			printf("%d\t",*(*(td+i)+j));
		}
		printf("\n");
	}
	printf("\n%d\n",*td[0]);
	printf("%d\n",*(*td));
	printf("%d\n",*(*(td+1)+3));
	printf("%d\n",*(*(td+2)+3));
	printf("%d\n",*(*(td+5)+0));*/
//	int arr[2][3]={{2,3,5},{4,8,15}};
	int arr[][4]={{2,3,5},{4,8},{10,20,30,40}};
	printf("%d\n",sizeof(arr));
	printf("%d\n",sizeof(arr[0]));
	printf("%d\n",sizeof(arr[0][0]));
	int rows=sizeof(arr)/sizeof(arr[0]);
//	int cols=sizeof(arr[0])/sizeof(arr[0][0]);
	for(int i=0; i<rows; i++){
		int cols=sizeof(arr[0])/sizeof(arr[0][0]);
		for(int j=0; j<cols; j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

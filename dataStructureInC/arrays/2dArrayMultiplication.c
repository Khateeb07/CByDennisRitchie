#include <stdio.h>
int main(){
/*	int a[][2]={{2,4},{7,5},{1,3}};
	int b[][3]={{5,4,1},{3,9,10}};
	int c[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			c[i][j]=0;
			for(int k=0; k<2; k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("Multiplication of 2d Matrix---->\n\n");*/
	int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Transpose of Matrix\n");
	for(int i=0; i<4; i++){
		for(int j=i; j<4; j++){
			int temp=a[j][i];
			a[j][i]=a[i][j];
			a[i][j]=temp;
		}
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

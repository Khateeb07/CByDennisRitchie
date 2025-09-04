#include <stdio.h>
int main(){
	int x=10,y=20;
	if(x<y){
		printf("Inside if\n");
		printf("x<y\n");
	}
	else{
		printf("Inside else\n");
		printf("x>=y\n");
	}
	printf("Outside of if-else\n");
	return 0;
}

#include <stdio.h>
#define PI 3.14
#define ADD(X,Y) X+Y
int main(){
	int x = ADD(2,3);
	float y = ADD(3.2,5.5);
	printf("x = %d\n",x);
	printf("y = %f\n",y);
	return 0;
}

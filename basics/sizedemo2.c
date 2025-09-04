#include <stdio.h>
#include <stdlib.h>
int x=10;
int a=50;
int main(int argc, char* argv[]){
	static int y=20;
	int b=12, c=15;
	printf("x=%d\n", x);
	printf("y=%d\n", y);
	return 0;
}


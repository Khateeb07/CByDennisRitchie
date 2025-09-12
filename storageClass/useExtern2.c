#include <stdio.h>
void printer();
//extern int x;
int main(){
	extern int x;
//	x=20;
	printer();
	x=20;
	printf("x in main=%d\n",x);
	printer();
	return 0;
}
void printer(){
	extern int x;
	x++;
	printf("x in printer=%d\n",x);
}

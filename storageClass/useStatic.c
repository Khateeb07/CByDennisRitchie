#include <stdio.h>
void printer();
//static int x=20;
int main(){
	printer();
	printer();
	printer();
	static int x=23;
	printf("x in main=%d\tAddress of main x:%p\n",x, &x);
	return 0;
}
void printer(){
	static int x;
	printf("x=%d\tAddress of printer x:%p\n",x, &x);
	x++;
}

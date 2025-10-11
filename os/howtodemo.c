#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int add(int, int);
void myfunction(){
	printf("myfunction\n");
	_exit(0);
}
void yourfunction(){
	printf("yourfunction\n");
}
int main(int argc, char* argv[]){
	atexit(myfunction);
	atexit(myfunction);
	atexit(yourfunction);
	int a=10, b=5, c;
	c=add(a,b);
	printf("Result=%d\n", c);
	exit(0);
}
int add(int x, int y){
	int z=x+y;
	return z;
}

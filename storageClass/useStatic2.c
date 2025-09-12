#include <stdio.h>
void printer();
int main(int argc, char* argv[]) {
	int a=20;
	static int b=a;
	printer();
	return 0;
}
void printer() {
//	int x=10;
	static int y=10;
	printf("y=%d\n", y);
}

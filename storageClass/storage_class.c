#include <stdio.h>
void printer();
extern int x;
int main(int argc, char* argv[]) {
	auto int x=20;
	printer();
	printf("x of main()=%d\n", x);
	if(1) {
		auto int x=30;
		printf("x of if-block=%d\n", x);
	}
	return 0;
}
void printer() {
	x++;
	printf("x of printer()=%d\n", x);
}

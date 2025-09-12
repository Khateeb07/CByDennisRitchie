#include <stdio.h>
void printer();
void show();
int main(int argc, char* argv[]) {
	auto int a=50;
	printf("a=%d\n", a);
	printer();
	show();
	return 0;
}
void printer() {
	int x=10;
	int y=20;
	printf("x=%d\ty=%d\n", x, y);
}
void show() {
	int k;
	printf("k=%d\n", k);
}

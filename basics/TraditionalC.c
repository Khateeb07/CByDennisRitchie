#include <stdio.h>
int
add(x, y)
	int x;
	int y;
{
	return x+y;
}
int main(int argc, char* argv[]) {
	int sum=add(10, 3);
	printf("%d\n", sum);
	printf("%d\n", __STDC__);
	return 0;
}

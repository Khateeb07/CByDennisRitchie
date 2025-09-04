#include <stdio.h>
#define NUM 30
int main(int argc, char* argv[]) {
	printf("%d\n", NUM);
/*	#define NUM 40
	printf("%d\n", NUM);
*/	int x;
	for(x=0; x<10; x+=2) {
		printf("Not ISO Standard\n");
	}
	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("%d\n", __STDC__);
	return 0;
}

#include <stdio.h>
//#define AGE 20
int main() {
	#ifndef AGE
		#define AGE 30;
	#endif
	int x = AGE;
	printf("x = %d \n", x);
	return 0;
}

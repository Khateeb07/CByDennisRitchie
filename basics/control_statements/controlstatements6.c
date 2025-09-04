#include <stdio.h>
int main(){
	int i=1;
	printf("Inside main\n");
	ab:
	printf("Inside label\n");
	i++;
	if(i<5)
		goto ab;
	printf("End of main\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(){
        int* p=(int*)malloc(sizeof(int));
	*p=20;
	printf("%d\n",*p);
	free(p);
	p=NULL;		// After freeing up a pointer it acts as a dangling pointer so NULL is stored in it.
//	printf("%d\n",*p);
        return 0;
}


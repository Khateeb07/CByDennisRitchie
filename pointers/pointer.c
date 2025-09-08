#include <stdio.h>
int main(){
	int x=10;
	int addr=&x;
	int* p=&x;
	printf("%x\n",addr);
	printf("%p\n",p);
	x++;
	p++;
	printf("%x\n",addr);
	printf("%p\n",p);
	printf("%d\n",(int)sizeof(p));
	return 0;
}


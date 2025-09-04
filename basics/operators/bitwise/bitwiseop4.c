#include <stdio.h>
int main(){
	char x=-10;
	char y=(char)(x>>1);
	char a=(char)(x>>2);
	char b=(char)(x>>3);
	char c=(char)(x>>4);
	char d=(char)(x<<1);
	char e=(char)(x<<2);
	char f=(char)(x<<3);
	char g=(char)(x<<4);
	printf("%d\n",y);
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
	printf("%d\n",e);
	printf("%d\n",f);
	printf("%d\n",g);
	return 0;
}


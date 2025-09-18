#include <stdio.h>
#include <stdlib.h>
int main(){
	int chs=sizeof(char);
	printf("Char size=%d\n", chs);
//	char* cp = (char*)malloc(chs*4);
	char* cp = (char*)malloc(sizeof(char)*4);	// Ideal way of using malloc
	*cp='A';
	*(cp+1)='B';
	*(cp+2)='C';
	*(cp+3)='D';
	for(int i=0; i<4; i++){
		printf("%c\n",*(cp+i));
	}
	return 0;
}

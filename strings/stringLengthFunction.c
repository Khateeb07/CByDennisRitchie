#include <stdio.h>
int getLength(char*);
int main(){
	char name[]="Khateeb";
	int len=getLength(name);
	printf("Length=%d\n",len);
	return 0;
}
int getLength(char* s){
	int length=0;
	while(s[length]!='\0')
		length++;
	return length;
}

#include <stdio.h>
#include <string.h>
int main(){
	char name[]="Khateeb";
	int len=strlen(name);
	printf("%s\nLength=%d\n", name, len);
	char name2[]="Khat\0eeb";
	int len2=strlen(name2);
	printf("%s\nLength=%d\n", name2, len2);
	return 0;
}

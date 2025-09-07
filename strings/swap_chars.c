#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	char name[7]="Khateeb";
	int i=0, j=strlen(name)-1;
	while(i<j) {
		char* ptr=&name[i];
		char* ptr2=&name[j];
		char temp=*ptr;
		*ptr=*ptr2;
		*ptr2=temp;
		i++;
		j--;
	}
	printf("%s\n", name);
	return 0;
}

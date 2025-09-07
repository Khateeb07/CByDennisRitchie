#include <stdio.h>
#include <string.h>
void reverse(char name[]){
	int j=strlen(name)-1;
	for(int i=0; i<j; i++, j--){
		char temp=name[i];
		name[i]=name[j];
		name[j]=temp;
	}
}

int main(){
	char name[]="Lucknow";
	printf("%s\n", name);
	reverse(name);
	printf("%s\n", name);
	return 0;
}

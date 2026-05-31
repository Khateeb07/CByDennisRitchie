#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	char* str="Khateeb is a coder";
	for(int i=0; i<strlen(str); i++) {
		int c=0;
		if(str[i]==' ') continue;
		for(int j=0; j<strlen(str); j++) {
			if(j>=i && str[j]==str[i])
				c++;
			else if(j<i && str[i]==str[j])
				break;
		}
		if(c>0)
			printf("%c\t%d\n", str[i], c);
	}
	return 0;
}

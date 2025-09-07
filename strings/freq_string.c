#include <stdio.h>
#include <string.h>
/*void getFrequency(char* str){
	int l=strlen(str);
	for(int i=0; i<l; i++){
		int f=0;
		char ch=str[i];
		for(int j=0; j<l; j++){
			if(ch==str[j] && j>=i)
				f++;
		}
		if(f!=0)
			printf("%c\t%d\n",ch,f);
	}
}*/
void getFrequency(char* str){
	int count=0;
	for(int i=0; i<strlen(str);i++){
		count=0;
		if(str[i]==' ')
			continue;
		for(int j=0; j<strlen(str); j++){
			if(str[i]==str[j] && j>=i)
				count++;
			else if(j<i && str[i]==str[j])
				break;
		}
		if(count>0)
			printf("%c\t%d\n",str[i],count);
	}
}
int main(){
	char city[]="Lucknow Junction";
	getFrequency(city);
	return 0;
}

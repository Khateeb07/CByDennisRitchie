#include <stdio.h>
#include <string.h>
int main(){
	/*char* str1="Lucknow";
	char* str2="Lucklater";
	printf("%d\n",strncmp(str1,str2,0));
	char* str="Lucknow Junction";
	char ch='n';
	char* p1=strchr(str,ch);
	char* p2=strrchr(str,ch);
	printf("%s\n",p1);
	printf("%s\n",p2);
	char* p3=strchr(str,'a');
	if(p3==NULL)
		printf("p3 is NULL\n");*/
	/*char* str="Lucknow Junction";
	char* str2="now";
	char* p=strstr(str,str2);
	printf("%s\n",p);
	char* str3="nowJ";
	char* p2=strstr(str,str3);
	if(p2==NULL)
		printf("p2 is NULL\n");*/
	char str[20]="Lucknow";
	char* st=" Junction";
	char* p=strcpy(str,st);
	printf("%s\n",p);
	char* p2=strncpy(str,"EAST",2);
	printf("%s\n",p2);
	return 0;
}

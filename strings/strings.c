#include <stdio.h>
int main(){
	char name[]={'L','u','c','k','n','o','w'};	// Terminate it with '\0' null character
	char city[]="Lucknow";
	char* location="Lucknow";
	printf("%s\n",city);
	printf("%s\n",location);
	printf("%s\n",name);
	city[0]='T';
	printf("%s\n",city);
//	location[0]='T';	// Runtime Error bcoz location is pointer to char and immutable unlike city which is an array and mutable;
	location="kanpur";	// Here, a new string "kanpur" is created and now the pointer points to that location
	printf("%s\n",location);
	return 0;
}

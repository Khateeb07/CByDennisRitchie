#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	if(argc<3){
		printf("Incorrect usage\n");
		return 0;
	}else{
		int sum=0;
		for(int i=1; i<argc; i++){
			sum=sum+atoi(argv[i]);
		}
		printf("Sum=%d\n", sum);
	}
	return 0;
}

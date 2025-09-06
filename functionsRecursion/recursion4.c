#include <stdio.h>
/*long sum(unsigned int n){
	if(n==1)
		return 1;
	return n+sum(n-1);
}*/
long fact(unsigned int n){
	long result=1;
	for(int i=n; i>0; i--){
		result*=i;
	}
	return result;
}
int main(){
	int n=5;
//	long result = sum(5);
	long result = fact(5);
	printf("%d\n", result);
	return 0;
}

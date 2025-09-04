#include <stdio.h>
#if !__STDC__
	#include <conio.h>
#endif
int main(){
	printf("Hello\n");
	if(!__STDC__){
		getch();
	}
	return 0;
}

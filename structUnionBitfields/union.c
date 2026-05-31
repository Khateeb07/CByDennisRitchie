#include <stdio.h>

union Value {
    int i;
    float f;
    char ch;
};

int main() {
    union Value v;
    v.i = 10;
    printf("%d\n", v.i);

    v.f = 3.14;
    printf("%f\n", v.f);

	v.i=10;
	printf("%d\n", v.i);
    return 0;
}

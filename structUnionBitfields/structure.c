#include <stdio.h>
struct student {
	char* name;
	int age;
	struct college {
		char* name;
		char* location;
	} col;
};
struct student stu={"Khateeb", 22, {"Integral University", "Kursi Road"}};
int main(int argc, char* argv[]) {
	printf("%s\t%d\n%s\t%s\n", stu.name, stu.age, stu.col.name, stu.col.location);
	printf("%ld\n", sizeof(stu));
}

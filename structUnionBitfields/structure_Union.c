#include <stdio.h>
/*struct citizen{
	char* name;
	int age;
	char* location;
};*/
/*struct user{
	int age;
	char* name;
	int salary;
}fbuser;*/
struct user{
	char* name;
	int age;
	int salary;
};
int main(){
	/*struct citizen Tony={"Tony Stark", 40, "California,US"};
	printf("%s\n",Tony.name);
	Tony.location="New York";
	printf("%s\n",Tony.location);*/
	//printf("%ld\n",sizeof(fbuser));
	//printf("%ld\n",sizeof(struct user));
	struct user fbuser;
	struct user *sp;
	sp=&fbuser;
	sp->name="Mukesh Kumar";
	sp->age=34;
	sp->salary=23000;
	printf("%s\n",fbuser.name);
	printf("%s\n",sp->name);
	return 0;
}

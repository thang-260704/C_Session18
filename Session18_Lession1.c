#include<stdio.h>
#include<string.h>
int main(){
	struct student{
		char name[100];
		int age;
		char phoneNumber[100];
	};
	struct student s1={
		"Nguyen Quyet Thang",
		21,
		"0784154417",
	};
	printf("Name : %s\n", s1.name);
	printf("Age : %d\n", s1.age);
	printf("Phonenumber : %s\n", s1.phoneNumber);
	return 0;
}

#include<stdio.h>
#include<string.h>
int main(){
	struct student{
		char name[100];
		int age;
		char phoneNumber[100];
	};
	struct student s[5];
	for(int i=1;i<=5;i++){
	    printf("Moi ban nhap ten sv%d : ",i);
    	fgets(s[i].name,100,stdin);
    	printf("Moi ban nhap tuoi sv%d : ",i);
    	scanf("%d", &s[i].age);
    	getchar();
    	printf("Moi ban nhap so dien thoai sv%d : ",i);
    	fgets(s[i].phoneNumber,100,stdin);
    	printf("\n \n");
    	printf("Name sv%d : %s",i, s[i].name);
    	printf("Age sv%d : %d\n",i, s[i].age);
    	printf("Phonenumber sv%d : %s\n",i, s[i].phoneNumber);
    	printf("\n \n");
    }
	return 0;
}

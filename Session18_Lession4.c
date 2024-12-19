#include<stdio.h>
#include<string.h>
int main(){
	struct student{
		int id;
		char names[100];
		int ages;
		char phoneNumbers[100];
	};
	struct student s[5];
	for(int i=1;i<=5;i++){
	    printf("Moi ban nhap ten id %d : ",i);
    	fgets(s[i].names,100,stdin);
    	printf("Moi ban nhap tuoi id %d : ",i);
    	scanf("%d", &s[i].ages);
    	getchar();
    	printf("Moi ban nhap so dien thoai id %d : ",i);
    	fgets(s[i].phoneNumbers,100,stdin);
    	printf("\n \n");
    	printf("Id : %d\n",i);
    	printf("Names id %d : %s",i, s[i].names);
    	printf("Ages id %d : %d\n",i, s[i].ages);
    	printf("Phonenumbers id %d : %s\n",i, s[i].phoneNumbers);
    	printf("\n \n");
    }
	return 0;
}

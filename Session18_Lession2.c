#include<stdio.h>
#include<string.h>
int main(){
	struct sinhvien{
		char Ten[100];
		int Tuoi;
		char SoDienThoai[100];
	};
	struct sinhvien s[5];
	for(int i=1;i<=5;i++){
	    printf("Moi ban nhap ten sv%d : ",i);
    	fgets(s[i].Ten,100,stdin);
    	printf("Moi ban nhap tuoi sv%d : ",i);
    	scanf("%d", &s[i].Tuoi);
    	getchar();
    	printf("Moi ban nhap so dien thoai sv%d : ",i);
    	fgets(s[i].SoDienThoai,100,stdin);
    	printf("\n \n");
    	printf("Ten sv%d : %s",i, s[i].Ten);
    	printf("Tuoi sv%d : %d\n",i, s[i].Tuoi);
    	printf("SoDienThoai sv%d : %s\n",i, s[i].SoDienThoai);
    	printf("\n \n");
    }
	return 0;
}


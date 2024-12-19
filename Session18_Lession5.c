#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int id;
struct students{
    int id;
    char names[30];
    int ages;
    char phones[15];
};
typedef struct students students;
void insertSV(students *a, int id, int size) {
    int tg=0;
    for(int i=0;i<size;i++) {
        if(a[i].id==id){
            tg=1;
            printf("Cap nhat thong tin:\n");
            printf("Ho va ten: ");
            getchar();
            fgets(a[i].names,25,stdin);
            printf("Tuoi: ");
            scanf("%d",&a[i].ages);
            getchar();
            printf("So dien thoai: ");
            fgets(a[i].phones,15,stdin);
            a[i].phones[strcspn(a[i].phones,"\n")]='\0';
            printf("Da cap nhat thong tin!\n");
            break;
        }
    }
    if (!tg){
      printf("Khong tim thay sinh vien co id %d!\n",id);
    }
}
int main(){
    students a[5]={
        {422,"Nguyen Quyet Thang",21,"0782154417"},
        {123,"Nguyen Sy Trung",18,"0123456789"},
        {66,"Nguyen Manh Hung",18,"0123456789"},
        {312,"Nguyen Tuan Dung",18,"0123456789"},
        {111,"Nguyen Anh Dung",18,"0123456789"}
    };
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d",&id);
    insertSV(&a,id,5);
    printf("ID            Ho va ten      Tuoi So dien thoai\n");
    for(int i=0;i<5;i++){
      printf("%3d%25s%3d%15s\n",a[i].id,a[i].names,a[i].ages,a[i].phones);
    }
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int id;
struct students{
    int id;
    char names[20];
    int ages;
    char phones[13];
};
typedef struct students students;
void editSV(students *a, int id, int *size) {
    int tg=0;
    for(int i=0;i<*size;i++)if(id==a[i].id){
        tg=1;
        printf("ID sinh vien da ton tai!");
        break;
    }
    if(!tg){
        (*size)++;
        a[*size-1].id=id;
        printf("Cap nhat thong tin sinh vien ID %d\nHo va ten: ",id);
        getchar();
        fgets(a[*size-1].names,20,stdin);
        a[*size-1].names[strcspn(a[*size-1].names,"\n")]='\0';
        printf("Tuoi: ");
        scanf("%d",&a[*size-1].ages);
        getchar();
        printf("So dien thoai: ");
        fgets(a[*size-1].phones,13,stdin);
        a[*size-1].phones[strcspn(a[*size-1].phones,"\n")]='\0';
        printf("Da cap nhat thong tin!\n");
    }
}
int main(){
    int n=5;
    students a[10]={
        {422,"Nguyen Quyet Thang",21,"0782154417"},
        {123,"Nguyen Sy Trung",18,"0123456789"},
        {66,"Nguyen Manh Hung",18,"0123456789"},
        {312,"Nguyen Tuan Dung",18,"0123456789"},
        {111,"Nguyen Anh Dung",18,"0123456789"}
    };
    printf("Nhap ID sinh vien can them: ");
    scanf("%d",&id);
    editSV(&a,id,&n);
    printf("ID            Ho va ten     Tuoi   So dien thoai\n");
    for(int i=0;i<n;i++)printf("%3d%25s %3d%15s\n",a[i].id,a[i].names,a[i].ages,a[i].phones);
}

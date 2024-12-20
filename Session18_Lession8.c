#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

Student students[MAX_STUDENTS] = {
    {1, "Nguyen Quyet Thang", 20, "0123456789"},
    {2, "Nguyen Sy Trung", 18, "0987654321"},
    {3, "Nguyen Manh Hung", 18, "0345678901"},
    {4, "Tran Anh Dung", 18, "0567890123"},
    {5, "Nguyen Tuan Dung", 18, "0789012345"}
};

int studentCount = 5;

void displayStudents() {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. ID: %d, Name: %s, Age: %d, Phone: %s\n", i + 1, students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void insertStudent(int position, Student newStudent) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Khong the them sinh vien, mang da day.\n");
        return;
    }
    if (position < 0 || position > studentCount) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = studentCount; i > position; i--) {
        students[i] = students[i - 1];
    }

    students[position] = newStudent;
    studentCount++;
    printf("Sinh vien da duoc them thanh cong.\n");
}

int main() {
    Student newStudent;
    int position;

    displayStudents();

    printf("\nNhap vi tri muon chen sinh vien (0 - %d): ", studentCount);
    scanf("%d", &position);

    printf("Nhap ID: ");
    scanf("%d", &newStudent.id);
    printf("Nhap ten: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]", newStudent.phoneNumber);

    insertStudent(position, newStudent);

    displayStudents();

    return 0;
}

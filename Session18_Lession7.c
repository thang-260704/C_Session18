#include <stdio.h>
#include <string.h>

#define FULL_STUDENTS 50

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

Student students[FULL_STUDENTS] = {
    {1, "Nguyen Quyet Thang", 20, "0782154417"},
    {2, "Nguyen Manh Hung", 18, "0987654321"},
    {3, "Nguyen Sy Trung", 18, "0345678901"},
    {4, "Nguyen Tuan Dung", 18, "0567890123"},
    {5, "Tran Anh Dung", 18, "0789012345"}
};

int studentCount = 5;

void displayStudents() {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d. ID: %d, Name: %s, Age: %d, Phone: %s\n", i + 1, students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int findStudentByName(char *name) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i; 
        }
    }
    return -1; 
}

void deleteStudent(int position) {
    if (position < 0 || position >= studentCount) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = position; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;
    printf("Sinh vien da duoc xoa thanh cong.\n");
}

int main() {
    char nameToDelete[50];
    int position;

    displayStudents();

    printf("\nNhap ten sinh vien can xoa: ");
    scanf(" %[^\n]", nameToDelete);

    position = findStudentByName(nameToDelete);

    if (position == -1) {
        printf("Sinh vien co ten '%s' khong ton tai trong danh sach.\n", nameToDelete);
    } else {
        deleteStudent(position);
        displayStudents();
    }

    return 0;
}

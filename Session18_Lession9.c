#include <stdio.h>
#include <string.h>

#define MAX_MENU_SIZES 100

typedef struct {
    int id;
    char names[50];
    float price;
} Dish;

Dish menu[MAX_MENU_SIZES] = {
    {1, "BanhMi", 150.0},
    {2, "Pho", 50.0},
    {3, "MienGa", 100.0},
    {4, "RauXao", 80.0},
    {5, "ComRang", 200.0}
};

int menuSize = 5;

void printMenu() {
    for (int i = 0; i < menuSize; i++) {
        printf("%d. ID: %d, Names: %s, Price: %.2f\n", i + 1, menu[i].id, menu[i].names, menu[i].price);
    }
}

void addDish(int position, Dish newDish) {
    if (menuSize >= MAX_MENU_SIZES || position < 0 || position > menuSize) {
        printf("Khong the them mon an vao vi tri nay.\n");
        return;
    }
    for (int i = menuSize; i > position; i--) {
        menu[i] = menu[i - 1];
    }
    menu[position] = newDish;
    menuSize++;
    printf("Mon an da duoc them thanh cong.\n");
}

void updateDish(int position, Dish updatedDish) {
    if (position < 0 || position >= menuSize) {
        printf("Khong the sua mon an o vi tri nay.\n");
        return;
    }
    menu[position] = updatedDish;
    printf("Mon an da duoc cap nhat thanh cong.\n");
}

void deleteDish(int position) {
    if (position < 0 || position >= menuSize) {
        printf("Khong the xoa mon an o vi tri nay.\n");
        return;
    }
    for (int i = position; i < menuSize - 1; i++) {
        menu[i] = menu[i + 1];
    }
    menuSize--;
    printf("Mon an da duoc xoa thanh cong.\n");
}

void sortMenu(int order) {
    for (int i = 0; i < menuSize - 1; i++) {
        for (int j = i + 1; j < menuSize; j++) {
            if ((order == 1 && menu[i].price < menu[j].price) ||
                (order == 2 && menu[i].price > menu[j].price)) {
                Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
    if (order == 1) {
        printf("Menu da duoc sap xep giam dan theo gia.\n");
    } else {
        printf("Menu da duoc sap xep tang dan theo gia.\n");
    }
}

void linearSearch(char *names) {
    int found = 0;
    for (int i = 0; i < menuSize; i++) {
        if (strcmp(menu[i].names, names) == 0) {
            printf("Tim thay: ID: %d, Names: %s, Price: %.2f\n", menu[i].id, menu[i].names, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an co ten: %s\n", names);
    }
}

void binarySearch(char *names) {
    int left = 0, right = menuSize - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(menu[mid].names, names);
        if (cmp == 0) {
            printf("Tim thay: ID: %d, Names: %s, Price: %.2f\n", menu[mid].id, menu[mid].names, menu[mid].price);
            found = 1;
            break;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an co ten: %s\n", names);
    }
}

int main() {
    int choice, subChoice, position;
    Dish newDish;
    char searchName[50];

    do {
        printf("\nMENU\n");
        printf("1. In ra gia tri cac phan tu co trong menu\n");
        printf("2. Them mot phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo ten\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMenu();
                break;
            case 2:
                printf("Nhap vi tri muon them (0 - %d): ", menuSize);
                scanf("%d", &position);
                printf("Nhap ID: ");
                scanf("%d", &newDish.id);
                printf("Nhap ten: ");
                scanf(" %[^\n]", newDish.names);
                printf("Nhap gia: ");
                scanf("%f", &newDish.price);
                addDish(position, newDish);
                break;
            case 3:
                printf("Nhap vi tri muon sua (0 - %d): ", menuSize - 1);
                scanf("%d", &position);
                printf("Nhap ID: ");
                scanf("%d", &newDish.id);
                printf("Nhap ten: ");
                scanf(" %[^\n]", newDish.names);
                printf("Nhap gia: ");
                scanf("%f", &newDish.price);
                updateDish(position, newDish);
                break;
            case 4:
                printf("Nhap vi tri muon xoa (0 - %d): ", menuSize - 1);
                scanf("%d", &position);
                deleteDish(position);
                break;
            case 5:
                printf("5a. Giam dan theo price\n");
                printf("5b. Tang dan theo price\n");
                printf("Lua chon cua ban (1: Giam dan, 2: Tang dan): ");
                scanf("%d", &subChoice);
                sortMenu(subChoice);
                break;
            case 6:
                printf("6a. Tim kiem tuyen tinh\n");
                printf("6b. Tim kiem nhi phan\n");
                printf("Lua chon cua ban (1: Tuyen tinh, 2: Nhi phan): ");
                scanf("%d", &subChoice);
                printf("Nhap ten mon an can tim: ");
                scanf(" %[^\n]", searchName);
                if (subChoice == 1) {
                    linearSearch(searchName);
                } else if (subChoice == 2) {
                    binarySearch(searchName);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void print_menu1() {
    system("cls");
    printf("Viberite punkt\n");
    printf("1. Sothdat massiv\n");
    printf("2. Vvesti niviy element\n");
    printf("3. Udalenie elementa\n");
    printf("4. Etog funkcie\n");
    printf("5. Exit\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s);
    }

    return variant;
}

void add_arr(int *size, int *capacity) {
    int a , b ;
    printf("Vedite chislo ctrok:");
    scanf("%d",&(*size));
    printf("Vedite chislo stolbcov:");
    scanf("%d",&(*capacity));
}

void print_num(int size, int capacity) {
    printf("%d %d", size,capacity );
}
void print_arr(int size){
    printf("in progress");
}

int main() {
    int variant;
    int size = 0;
    int capacity = 1;


    do {
        print_menu1();

        variant = get_variant(5);

        switch (variant) {
            case 1:
                add_arr(&size, &capacity);
                break;

            case 2:
                print_num(size, capacity);
                break;

            case 3:
                print_arr(size);
                break;

            case 4:
                print_arr(size);
                break:
        }

        if (variant != 5)
            system("pause");
             } while (variant != 5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void print_menu1() {
    system("cls");
    printf("Menu\n");
    printf("1. Make massive\n");
    printf("2. Replace element in massive\n");
    printf("3. Delet element\n");
    printf("4. Result\n");
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

void add_arr(int *capacity, int *arr) {
    printf("Enter element number:");
    scanf("%d",&(*capacity));
    printf("Capa %d",*capacity);;
    *arr =  arr[*capacity];

    if (*arr == NULL) {
        printf("Allocation error.");
    }

    for (int j = 0; j < *capacity; j++){ //проход столбец
            printf("[%d]:",j);
            scanf("%d", arr[j]);
            }
}

void del_num(int size, int capacity) {
    printf("%d %d", size,capacity );
}
void print_arr(int capacity,int *arr){
    printf("in progress\n");
    for (int j = 0; j < capacity; j++){ //проход столбов
            printf("%d ", arr[j]);
            }
}

int main() {
    int variant;
    int capacity = 1;
    int *arr;


    do {
        print_menu1();

        variant = get_variant(5);
        switch (variant) {
            case 1:
                add_arr(&capacity, arr);
                break;

            /*case 2:
                add_num(size, capacity);
                break;
*/
            case 3:
                del_arr(capacity, arr);
                break;

            case 4:
                print_arr(capacity, arr);
                break;
        }

        if (variant != 5)
            system("pause");
             } while (variant != 5);
    return 0;
}

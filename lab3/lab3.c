#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void print_menu1() {
    setlocale(LC_ALL, "Rus");
    system("cls");  // очищаем экран
    printf("Действия\n");
    printf("1.Ввести данные массива\n");
    printf("2.Вывести исходный массив\n");
    printf("3.Вывести итоговый массив\n");
    printf("4. Выход\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }

    return variant;
}

void add_arr(int *size, int *capacity) {
    int a , b ; //кол-во строк и столбцов
    printf("Vedite chislo ctrok:");
    scanf("%d",&(*size));
    printf("Vedite chislo stolbcov:");
    scanf("%d",&(*capacity));
}

void print_num(int size, int capacity) {
    // реализация процедуры
    printf("%d %d", size,capacity );
}
void print_arr(int size){
    printf("in progress");
}

int main() {
    int variant; // выбранный пункт меню
    int size = 0; // строки
    int capacity = 1; // столбци


    do {
        print_menu1(); // выводим меню на экран

        variant = get_variant(4); // получаем номер выбранного пункта меню

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
        }

        if (variant != 4)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_menu() {
    setlocale(LC_ALL, "Rus");
    system("cls");  // очищаем экран
    printf("Выберите тип ввода\n");
    printf("1.Одномерный массив \n");
    printf("2.Многомерны мвссив\n");
    printf("2.1 Сначало вводим серность массива\n");
    printf("0. Ввод чисел начнется после ыбора пункта меню\n");
    printf("5. Выйти\n");
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


void add_num() {
    // реализация процедуры
}

void print_num() {
    // реализация процедуры
}

switch (variant) {
    case 1:
        printf(vebor1);
        break;

    case 2:
        printf(vebor2);
        break;
}

int main() {
    int variant; // выбранный пункт меню
    int size = 0; // количество элементов массива товаров
    int capacity = 1; // ёмкость массива товаров

    good *goods = (good *)malloc(capacity * sizeof(good)); // выделяем память под массив товаров

    do {
        print_menu(); // выводим меню на экран

        variant = get_variant(5); // получаем номер выбранного пункта меню

        switch (variant) {
            case 1:
                add_good(&goods, &size, &capacity);
                break;

            case 2:
                print_goods(goods, size);
                break;

            case 3:
                print_highest(goods, size);
                break;

            case 4:
                print_lowest(goods, size);
                break;
        }

        if (variant != 5)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_menu() {
    setlocale(LC_ALL, "Rus");
    system("cls");  // ������� �����
    printf("�������� ��� �����\n");
    printf("1.���������� ������ \n");
    printf("2.���������� ������\n");
    printf("2.1 ������� ������ �������� �������\n");
    printf("0. ���� ����� �������� ����� ����� ������ ����\n");
    printf("5. �����\n");
    printf(">");
}

int get_variant(int count) {
    int variant;
    char s[100]; // ������ ��� ���������� �������� ������
    scanf("%s", s); // ��������� ������

    // ���� ���� �����������, �������� �� ���� � ������ ��������� ���
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: "); // ������� ��������� �� ������
        scanf("%s", s); // ��������� ������ ��������
    }

    return variant;
}


void add_num() {
    // ���������� ���������
}

void print_num() {
    // ���������� ���������
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
    int variant; // ��������� ����� ����
    int size = 0; // ���������� ��������� ������� �������
    int capacity = 1; // ������� ������� �������

    good *goods = (good *)malloc(capacity * sizeof(good)); // �������� ������ ��� ������ �������

    do {
        print_menu(); // ������� ���� �� �����

        variant = get_variant(5); // �������� ����� ���������� ������ ����

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
            system("pause"); // ����������� ����������, ����� ������������ ��� ������� ��������� ���������� ���������� ������
    } while (variant != 5);

    return 0;
}

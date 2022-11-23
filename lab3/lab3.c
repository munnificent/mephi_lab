#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

static int value = 1;

int print_menu(int index) {
    if (index > 4 || index < 0) return 0;
    (index == 1) ? printf("First            @\n") : printf("First           \n");
    (index == 2) ? printf("Second           @\n") : printf("Second          \n");
    (index == 3) ? printf("Third            @\n") : printf("Third           \n");
    (index == 4) ? printf("Forth            @\n") : printf("Forth           \n");
}

void selected(int button) {
    system("cls");
    printf("##################\n");
    printf("# %d was selected #\n", button);
    printf("##################\n");
    getch();
}

int button_process() {

    char ch = '0';
    while (!kbhit());
    ch = getch();
    switch (ch) {
        case '1':
            value = ch - 0x30;
            selected(value);
            break;
        case '2':
            value = ch - 0x30;
            selected(value);
            break;
        case '3':
            value = ch - 0x30;
            selected(value);
            break;
        case '4':
            value = ch - 0x30;
            selected(value);
            break;
    }
    if (ch == 72) {
        //Arrow up
        value -= 1;
        if (value == 0) value = 4;
    }
    else if (ch == 80) {
        //Arrow down
        value += 1;
        if (value == 5) value = 1;
    }
    else if (ch == 13) {
        // Enter button
        selected(value);
    }
    return value;
}

int main()
{
    int button = 1;
    while (1) {
        print_menu(button);
        button = button_process();
        system("cls");
    }
    system("PAUSE");
}

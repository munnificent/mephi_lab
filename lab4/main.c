#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#define DELIM " \t"
#define PROMPT "> "

int main() {
    char *input = readline(PROMPT);
    int s_len = strlen(input);
    printf("%d\n", s_len);
    while (s_len != 0) {
        printf("\"%s\"\n", input);
        s_len--;
    }
    return 0;
}

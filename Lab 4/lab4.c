#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t"
#define PROMPT ">_"

int main(){
    int d_len=0, w_len=0, s_len=0, m_len=0;
    char mass[] = "This is a test string";
    m_len = strlen(mass);
    char *trash = calloc(m_len, sizeof(char));
    memcpy(trash, mass, m_len * sizeof(char));
    char *word;
    char *curr;

    word = strtok(mass, DELIM);
    while(word != NULL) {
    curr = strdup(word);
     word = strtok(NULL, DELIM);
    }
    free(word);
    w_len = strlen(curr);
    printf("Word %d: \"%s\"\n",w_len, curr);

    word = strtok(trash, DELIM);
    while(word != NULL) {
    s_len = strlen(word);
    printf("Word1: \"%s\"\n",word);
     word = strtok(NULL, DELIM);
    }

    printf("%d \t %s",m_len,trash);
    return 0 ;
}

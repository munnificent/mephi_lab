#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#define DELIM " \t"
#define PROMPT ">_"

int main(){
    int now=0,prob1=0,prob2=0,i=0, posit=0, N=3,d_len=0, w_len=0, s_len=0, m_len=0;
    char *mass = readline(PROMPT);
    m_len = strlen(mass);
    char *trash = calloc(m_len, sizeof(char));
    memcpy(trash, mass, m_len * sizeof(char));

    char *curr;
    char *word = strtok(trash, DELIM);
    while(word != NULL) {
    curr = strdup(word);
     word = strtok(NULL, DELIM);
    }
	free(trash);
    trash = calloc(m_len, sizeof(char));
    w_len = strlen(curr);
    free(curr);
    word = strtok(mass, DELIM);
    while(word != NULL) {
        if(strlen(word)<= w_len){
            strcat(trash, word);
            now = strlen(trash);
            printf("now%d\n",now);
            trash[now]=' ' ;
        }
     word = strtok(NULL, DELIM);
    }
    now= strlen(trash);
    trash= realloc(trash,now*sizeof(char));
    printf("Result %d:%s",now,trash);
	free(trash);
	free(mass);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t"
#define PROMPT ">_"

int main(){
    int prob1,prob2,i=0, posit=0, N=3,d_len=0, w_len=0, s_len=0, m_len=0;
    char mass[] = "This is a test peedor string";
    m_len = strlen(mass);
    char *trash = calloc(m_len, sizeof(char));
    memcpy(trash, mass, m_len * sizeof(char));

    char *curr;
    char *word = strtok(mass, DELIM);
    while(word != NULL) {
    curr = strdup(word);
     word = strtok(NULL, DELIM);
    }
    free(word);
    w_len = strlen(curr);
    printf("Word %d: \"%s\"\n",w_len, curr);

    while(i != m_len){
            if(trash[i] == ' '){
                prob2= prob1;
                prob1 = i+1;
                N = prob1-prob2 ;
                if(N < w_len){
                         while(N !=0){
                        for(int j =prob2; j != m_len; j++){
                        trash[j]=trash[j+1];
                            }
                            m_len-1;
                            N--;
                         }
                        i=0;
                        prob1=0;
                    }
                }
            i++;
        }
printf("Result:%s",trash);
       free(trash);
        free(curr);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

#define DELIM " \t"
#define PROMPT ">_"

int main(){
    int new=0,prob1=0,prob2=0,i=0, posit=0, N=3,d_len=0, w_len=0, s_len=0, m_len=0;
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

    trash = calloc(m_len, sizeof(char));
    w_len = strlen(curr);
    printf("Word %d: \"%s\"\n",w_len, curr);
    free(trash);
    free(curr);

    while(i != m_len){
            if(mass[i] == ' '||i+1 == m_len){
                prob2 = prob1;
                prob1 = i;
                if(i+1<m_len)
                    N = prob1-prob2 ;
                else{
                    prob1=m_len;
                    N=w_len;
                }
                if(N <= w_len){
                        	for(int j =prob2; j < prob1; j++){
                        		trash[new]=mass[j];
                        		new++;
                            }
                    }
                }
            i++;
        }
    trash= realloc(trash,new*sizeof(char));
printf("Result %d:%s",new,trash);
	free(trash);
	free(mass);
        return 0;
}

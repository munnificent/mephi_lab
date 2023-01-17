#include <stdio.h>
#include <stdlib.h>
int main() {
    char *str = NULL, c;
    int prob1=0,prob2=0,N,now=0,j=0,w_len=0,len = 1;
    str = (char*) malloc(sizeof(char));
    printf("input string: ");
    while((c = getchar()) != '\n') {
        str[len - 1] = c;
        len++;
        str = (char*) realloc(str, len);
    }
    str[len - 1] = '\0';
    printf("%s (%d symbols)\n", str, len - 1);
    char *trash = calloc(len, sizeof(char));

    for(int i = len-2;str[i]!=' ';i--){
        w_len++;
    }

    printf("fin=%d\n",w_len);//fgcfg fcgt gfc ftf  fcgt gfcxg gfctrfch gfc

        while(j != len){
            //printf("j1=%d,%d,%d\n",j,prob2,prob1);
            if(str[j] == ' ' || j+1 == len){
                prob2 = prob1;
                prob1 = j;
                //printf("j2=%d,%d,%d\n",j,prob2,prob1);
                if(j+1<len){
                    if (prob2 != 0)
                        N = (prob1-prob2)-1 ;
                    else
                        N = (prob1-prob2) ;
                } else{
                    prob1=len;
                    N=w_len;
                }
                if(N <= w_len){
                        	for(int f =prob2; f < prob1; f++){
                        		trash[now]=str[f];
                        		now++;
                            }
                    }
                }
            j++;
        }
    trash= realloc(trash,now*sizeof(char));
    printf("Result :%s",trash);
    free(trash);
    free(str);
    return 0;
}

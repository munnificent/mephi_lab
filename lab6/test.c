#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
        char word;
        struct Node *next;
    };
struct Node *head = NULL;
struct Node *current = NULL;

void addNode(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newNode->word = c;
    newNode->next = NULL;
    if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
}

int main() {
    char *suffix = NULL,c1;
    int end =0,flag,word_start=0,len =1;
    suffix = (char*) malloc(sizeof(char));
    printf("Enter a suffix: ");
    while((c1 = getchar()) != '\n') {
        suffix[len - 1] = c1;
        len++;
        suffix = (char*) realloc(suffix, len);
    }
    suffix[len - 1] = '\0';

    char *str = NULL,c2;
    int len2 =1;
    str = (char*) malloc(sizeof(char));
    printf("Enter a words: ");
    while(end != 1 && ((c2 = getchar()) != '\n')) {
            if(c2 == '\n'){
                end = 1;
            }
        if (word_start == 0 && (c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u' || c2 == 'A' || c2 == 'E' || c2 == 'I' || c2 == 'O' || c2 == 'U')) {
               flag=1;
            }
        if (c2 == ' ' || c2 == '\t' || c2 == '\n' ) {
            word_start = 0;
            if(flag == 1){
                for (int i = 0; i < strlen(suffix); i++) {
                    addNode(suffix[i]);
                }
            }
            flag=0;
        } else {
            word_start = 1;
        }
        addNode(c2);
    }

    printf("List of words: \n");
        current = head;
        while (current != NULL) {
        printf("%c", current->word);
        current = current->next;
    }

    return 0;
}

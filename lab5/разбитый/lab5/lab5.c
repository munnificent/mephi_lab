#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "road.h"
typedef struct
{
    char mark[16];
    char name[100];
    int kilo;
} car;

void print_menu() {
    printf("What do you want to do?\n");
    printf("1. Add car to list\n");
    printf("2. Print all cars in list\n");
    printf("3.Do my work\n");
}

void print_goods(car *cars, int size) {
    if (size == 0){
        printf("|            No cars was added...          |\n");
    }
    for (int i = 0; i < size; i++){
        printf("| %s | %s | %d |\n", (cars)[i].mark,(cars)[i].name, (cars)[i].kilo);
    }
}

void make_test(car **cars, int size);
int sortq_num(const void *a, const void *b);
void add_good(car **cars, int *size, int *capacity);
int str_cmp(const void* a, const void* b);


int main(){
	int variant;
	int size = 0;
    int capacity = 1;

    car *cars = (car*)malloc(capacity * sizeof(car));
    do {
        print_menu();

        variant = get_variant(4);

        switch (variant) {
            case 1:
                add_good(&cars, &size, &capacity);
                break;

            case 2:
                print_goods(cars, size);
                break;

            case 3:
                make_test(&cars, size);
                break;
        }
    }while(variant !=4);
	return 0;
}

int sortq_num(const void *a, const void *b) {
     return *(int*)a - *(int*)b;
 }

int sortq_str(const void* a, const void* b) {
    return strcmp(((car*)a)->mark, ((car*)b)->mark);
}


 void make_test(car **cars, int size){
  //qsort(&(**cars).mark, size, sizeof(char), sortq_str);
  char *tmp;
  for(int i=0;i < size-1;i++){
    tmp=(*cars)[i].mark;
    //(*cars)[i].mark=(*cars)[i+1].mark;
    //(*cars)[i+1].mark=tmp;
  }
}

void add_good(car **cars, int *size, int *capacity) {
  printf("Enter good description: ");
    scanf("%s", &(*cars)[*size].mark);
    printf("Enter good name: ");
    scanf("%s", &(*cars)[*size].name);
    printf("Enter car distance: ");
    scanf("%d", &(*cars)[*size].kilo);
    (*size)++;
    if (*size >= *capacity) {
        *capacity *= 3;

        *cars = (car *)realloc(*cars, *capacity * sizeof(car));
    }

}

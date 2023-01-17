#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car
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


void add_good(car **cars, int *size, int *capacity) {
  /*printf("Enter good description: ");
    scanf("%s", &(*cars)[*size].mark);
    printf("Enter good name: ");
    scanf("%s", &(*cars)[*size].name);
    printf("Enter good price: ");
    scanf("%d", &(*cars)[*size].kilo);
/*
(*cars)[0].mark ="bmw";
(*cars)[0].name= "fet";
(*cars)[0].kilo= 15263;

    (*size)++;

    if (*size >= *capacity) {
        *capacity *= 3;

        *cars = (car *)realloc(*cars, *capacity * sizeof(car));
    }
    */
    (*cars)[2]={{"bmw","fer",34},{"audi","ger",27}};
    (*size)=2;
}

int get_variant(int count) {
    int variant;
    char s[100];
    scanf("%s", s);
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s);
    }

    return variant;
}

int sortq1(const void* x, const void* y)
{
	return strcmp(*(char**)x, *(char**)y);

}

int sortq(const void *a, const void *b) {
     return *(int*)a - *(int*)b;
 }

void make_test(car **cars, int size){
  qsort(&(**cars).mark, size, sizeof(char), sortq1 );
}


int main(){
	int variant;
	int size = 0;
    int capacity = 1;

    car *cars = (car*)malloc(capacity * sizeof(car));
    if(cars == NULL)
    		printf("ERROR");

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

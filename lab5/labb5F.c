#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BRAND_LENGTH 16

struct Automobile {
    char brand[MAX_BRAND_LENGTH];
    char *owner;
    float mileage;
};

void fillAutomobile(struct Automobile *car);
void printAutomobiles(struct Automobile *cars, int n);
void freeAutomobiles(struct Automobile *cars, int n);

void shakerSortByBrand(struct Automobile *cars, int n);
void shakerSortByOwner(struct Automobile *cars, int n);
void shakerSortByMileage(struct Automobile *cars, int n);

void insertionSortWithBinarySearchByBrand(struct Automobile *cars, int n);
void insertionSortWithBinarySearchByOwner(struct Automobile *cars, int n);
void insertionSortWithBinarySearchByMileage(struct Automobile *cars, int n);

int get_variant(int count){
	int variant;
	char s[100];
	scanf("%s", s);

	while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
	{
		printf("Incorrect input. Try again: ");
		scanf("%s", s);
	}

	return variant;
}

void fillAutomobile(struct Automobile *car) {
    char buffer[100];

    printf("Enter brand:");
    scanf("%s", &car->brand);

    printf("Enter owner: ");
    scanf("%s", &buffer);
    car->owner = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(car->owner, buffer);

    printf("Enter mileage: ");
    scanf("%f", &car->mileage);
}

void printAutomobiles(struct Automobile *cars, int n) {
    for (int i = 0; i < n; i++) {
        printf("Brand: %s, Owner: %s, Mileage: %.2f\n", cars[i].brand, cars[i].owner, cars[i].mileage);
    }
}

void freeAutomobiles(struct Automobile *cars, int n) {
    for (int i = 0; i < n; i++) {
        free(cars[i].owner);
    }
    free(cars);
}

int compare_brand(const void *a, const void *b) {
    struct Automobile *ia = (struct Automobile *)a;
    struct Automobile *ib = (struct Automobile *)b;
    return strcmp(ia->brand, ib->brand);
}

int compare_owner(const void *a, const void *b) {
    struct Automobile *ia = (struct Automobile *)a;
    struct Automobile *ib = (struct Automobile *)b;
    return strcmp(ia->owner, ib->owner);
}

int compare_mileage(const void *a, const void *b) {
    struct Automobile *ia = (struct Automobile *)a;
    struct Automobile *ib = (struct Automobile *)b;
    return (int)(ia->mileage - ib->mileage);
}

void shakerSortByBrand(struct Automobile *cars, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (strcmp(cars[i].brand, cars[i + 1].brand) > 0) {
                struct Automobile temp = cars[i];
                cars[i] = cars[i + 1];
                cars[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (strcmp(cars[i - 1].brand, cars[i].brand) > 0) {
                struct Automobile temp = cars[i];
                cars[i] = cars[i - 1];
                cars[i- 1] = temp;
            }
        }
        left++;
    }
}

void shakerSortByOwner(struct Automobile *cars, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (strcmp(cars[i].owner, cars[i + 1].owner) > 0) {
                struct Automobile temp = cars[i];
                cars[i] = cars[i + 1];
                cars[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (strcmp(cars[i - 1].owner, cars[i].owner) > 0) {
                struct Automobile temp = cars[i];
                cars[i] = cars[i - 1];
                cars[i - 1] = temp;
            }
        }
        left++;
    }
}

void shakerSortByMileage(struct Automobile *cars, int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (cars[i].mileage > cars[i + 1].mileage) {
                struct Automobile temp = cars[i];
                cars[i] = cars[i + 1];
                cars[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (cars[i - 1].mileage > cars[i].mileage) {
                struct Automobile temp = cars[i];
                cars[i] = cars[i - 1];
                cars[i - 1] = temp;
            }
        }
        left++;
    }
}

void insertionSortByBrand(struct Automobile *cars, int n) {
    for (int i = 1; i < n; i++) {
        struct Automobile temp = cars[i];
        int j = i - 1;
        while (j >= 0 && strcmp(temp.brand, cars[j].brand) < 0) {
            cars[j + 1] = cars[j];
            j--;
        }
        cars[j + 1] = temp;
    }
}

void insertionSortByOwner(struct Automobile *cars, int n) {
    for (int i = 1; i < n; i++) {
        struct Automobile temp = cars[i];
        int j = i - 1;
        while (j >= 0 && strcmp(temp.owner, cars[j].owner) < 0) {
            cars[j + 1] = cars[j];
            j--;
        }
        cars[j + 1] = temp;
    }
}

void insertionSortByMileage(struct Automobile *cars, int n) {
    for (int i = 1; i < n; i++) {
        struct Automobile temp = cars[i];
        int j = i - 1;
        while (j >= 0 && temp.mileage < cars[j].mileage) {
            cars[j + 1] = cars[j];
            j--;
        }
        cars[j + 1] = temp;
    }
}

int main(int argc, char *argv[]) {
    int n;
    printf("Enter the number of automobiles: ");
    scanf("%d", &n);

    struct Automobile *cars = (struct Automobile *)malloc(n * sizeof(struct Automobile));

    for (int i = 0; i < n; i++) {
        fillAutomobile(&cars[i]);
    }

    int option=0;
    int sortingOption;
    int sorterui=2;
    do {
        printf("\nMenu:\n");
        printf("1. Print automobiles\n");
        printf("2. Sort automobiles\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        option = get_variant(8);

        switch (option) {
            case 1:
                printAutomobiles(cars, n);
                break;
            case 2:
                printf("\nSorting options:\n");
                printf("1. By brand\n");
                printf("2. By owner\n");
                printf("3. By mileage\n");
                printf("Enter sorting option: ");
                scanf("%d", &sortingOption);

                switch (sortingOption) {
                    case 1:
                        printf("\nSoereter metod:");
                        scanf("%d", &sorterui);
                        switch (sorterui) {
                                case 1:
                                    printf("\nSorting by brand in shaker:\n");
                                    shakerSortByBrand(cars, n);
                                    printAutomobiles(cars, n);
                                    break;
                                case 2:
                                    printf("\nSorting by brand in Bimo:\n");
                                    insertionSortByBrand(cars, n);
                                    printAutomobiles(cars, n);
                                    break;
                                case 3:
                                    printf("\nSorting by brand in flash:\n");
                                    qsort(cars, n, sizeof(struct Automobile), compare_brand);
                                    printAutomobiles(cars, n);
                        }
                    case 2:
                        printf("\nSoereter metod:");
                        scanf("%d", &sorterui);
                        switch (sorterui) {
                                case 1:
                                    printf("\nSorting by owner:\n");
                                    shakerSortByOwner(cars, n);
                                    printAutomobiles(cars, n);
                                    break;
                                case 2:
                                    printf("\nSorting by owner:\n");
                                    insertionSortByOwner(cars, n);
                                    printAutomobiles(cars, n);
                                    break;
                                case 3:
                                    printf("\nSorting by brand in flash:\n");
                                    qsort(cars, n, sizeof(struct Automobile), compare_owner);
                                    printAutomobiles(cars, n);
                        }
                    case 3:
                        printf("\nSoereter metod:");
                        scanf("%d", &sorterui);
                        switch (sorterui) {
                                case 1:
                                    printf("\nSorting by mileage:\n");
                                    shakerSortByMileage(cars, n);
                                    printAutomobiles(cars, n);
                                    break;
                                case 2:
                                    printf("\nSorting by mileage:\n");
                                    insertionSortByMileage(cars, n);
                                    printAutomobiles(cars, n);
                                    break;
                                case 3:
                                    printf("\nSorting by brand in flash:\n");
                                    qsort(cars, n, sizeof(struct Automobile), compare_mileage);
                                    printAutomobiles(cars, n);
                        }
                    default:
                        printf("Invalid sorting option\n");
                        break;
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 3);

    freeAutomobiles(cars, n);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

void print_menu1()
{
	system("cls");
	printf("Menu\n");
	printf("1. Make massive\n");
	printf("2. Replace element in massive\n");
	printf("3. Delet element\n");
	printf("4. Result\n");
	printf("5. Exit\n");
	printf(">");
}

int get_variant(int count)
{
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

void add_arr(int *capacity,int **arr){
	printf("Enter element number:");
	scanf("%d", &(*capacity));
	printf("Capa %d", *capacity);
	*arr = (int*)realloc(*arr, *capacity * sizeof(int));

	if (*arr == NULL)
	{
		printf("Allocation error.");
	}

	for (int j = 0; j < *capacity; j++)
	{ //проход столбец
		printf("[%d]:", j);
		scanf("%d",&(*arr)[j]);
	}

	for (int j = 0; j < *capacity; j++)
	{ //проход столбов
		printf("[%d] ",(*arr)[j]);
	}
}

void del_num(int capacity, int **arr){
    int part1;
    printf("capa %d",capacity);
    printf("Enter element to delet:");
    scanf("%d",&part1);
    for( int j = part1; j < capacity-1; j++ ){
            printf("mass %d",(*arr)[part1]);
            (*arr)[part1] = (*arr)[part1+1];
            part1++;
    }
    capacity-=1;
    *arr = (int*)realloc(*arr,capacity * sizeof(int));
}

void add_num(int capacity, int **arr)
{
	int part1,part2;
    printf("max element positsion %d",capacity);
    printf("Enter position to add:");
    scanf("%d",&part1);
    printf("Enter element to add:");
    scanf("%d",&part2);
    (*arr)[part1]=part2;

}

void print_arr(int capacity, int **arr)
{
	printf("in progress\n");
	for (int j = 0; j < capacity; j++)
	{
		printf("[%d] ",(*arr)[j]);
	}
}

int main()
{
	int variant;
	int capacity = 1;
	int *arr = (int *)malloc(capacity * sizeof(int));

	do
	{
		print_menu1();

		variant = get_variant(5);
		switch (variant)
		{
		case 1:
			add_arr(&capacity,&arr);
			break;

		case 2:
			add_num(capacity, &arr);
			break;

		case 3:
			del_num(capacity, &arr);
			break;

		case 4:
			print_arr(capacity, &arr);
			break;
		}

		if (variant != 5)
			system("pause");
	} while (variant != 5);
	return 0;
}

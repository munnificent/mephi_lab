#include <stdio.h>
#include <stdlib.h>
#include "laber.h"

void restart(int *capacity, int *fin, int **arr, int **arr1){
    *fin=1;
    *capacity=1;
    free(*arr);
    free(*arr1);
    *arr = (int *)malloc(*capacity * sizeof(int));
	*arr1 = (int *)malloc(*fin * sizeof(int));
}

void dup(int ***arr, int **listLength)
{
    int i=0;
	while(i < **listLength-1)
	{
		if ((**arr)[i] == (**arr)[i+1])
		{
			for (int j = i; j < (**listLength - 1); j++)
        {
		(**arr)[j] = (**arr)[j + 1];
        }
			**listLength -= 1;

            **arr = (int *)realloc(**arr, **listLength * sizeof(int));
		} else {
		i++;
		}
	}
}

int len(int a){
    int i;
    for(i = 0; a != 0 ; i++)
        a/=10;
    return i;
}

void print_menu1(){
	system("cls");
	printf("Menu\n");
	printf("1. Make massive\n");
	printf("2. Replace element in massive\n");
	printf("3. Delete element\n");
	printf("4. Result\n");
	printf("5. Personal exercise\n");
	printf("6. Exit\n");
	printf("8. Restart\n");
	printf(">");
}

void print_menu2(){
	system("cls");
	printf("Menu\n");
	printf("1. Origin massive\n");
	printf("2. Steam massive\n");
	printf(">");
}

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

void add_arr(int *capacity,int **arr){
	printf("Enter element number:");
	scanf("%d", &(*capacity));
	printf("Capa %d", *capacity);
	*arr = (int*)realloc(*arr, *capacity * sizeof(int));

	if (*arr == NULL){
		printf("Allocation error.");
	}

	for (int j = 0; j < *capacity; j++){ //проход столбец
		printf("[%d]:", j);
		scanf("%d",&(*arr)[j]);
	}

	for (int j = 0; j < *capacity; j++){ //проход столбов
		printf("[%d] ",(*arr)[j]);
	}
}

void del_num(int *capacity, int **arr){
    int part1;
    printf("capa %d",*capacity);
    printf("Enter element to delete:");
    scanf("%d",&part1);
    for (int j = part1; j < *capacity - 1; j++)
        {
		(*arr)[j] = (*arr)[j + 1];
        }
    *capacity-=1;
    printf(" new capacity: %d",*capacity);
    *arr = (int*)realloc(*arr,*capacity * sizeof(int));
}

void add_num(int capacity, int **arr)
{
	int part1,part2;
    printf("max element position %d",capacity);
    printf("Enter position to replace:");
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

void sorter(int ***list, int **listLength)
{
	int tmp;
	for (int i = 1; i < **listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && (**list)[j] > (**list)[j + 1])
		{
			tmp = (**list)[j];
			(**list)[j] = (**list)[j + 1];
			(**list)[j + 1] = tmp;
			j--;
		}
	}
}
int cmp(const void *b, const void *a) {
     return *(int*)a - *(int*)b;
 }

 void make_test(int capacity, int *fin, int **arr, int **arr1){
    int k=0,curr,next,flag;
    qsort(*arr, capacity, sizeof(int), cmp );
    for(int i = 0; i <=7;i++){
        curr = (*arr)[i];
        for(int j=0;j<=7;j++){
            next=(*arr)[j];
            flag = samles(curr,next);
            if(flag == 1 && i != j){
                *arr1 = (int*)realloc(*arr1,(k+1)* sizeof(int));
                (*arr1)[k]=curr;
                k++;
                *arr1 = (int*)realloc(*arr1,(k+1)* sizeof(int));
                (*arr1)[k]=next;
                k++;
                *fin=k;
            }
            }
        }
        sorter(&arr1, &fin);
        dup(&arr1, &fin);
    }

int samles(int a, int b){
    int clone,flag=1,num1,num2;
  if(len(a)==len(b)){
  while (a!=0){
    if(flag == 1){
    num1=a%10; //123
    clone=b; //2
    while (clone!=0){
      num2=clone%10;
      clone/=10;
      if(num1==num2){
        flag=1;
        break;
      }
      else if(num1!=num2 && clone==0) {
        flag =-1;
        }
    }
    a/=10;
   }
   else {
     break;
   }
   }
   return flag;
} else{
    return 0;
}
}



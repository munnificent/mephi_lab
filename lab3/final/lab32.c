#include <stdio.h>
#include <stdlib.h>

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
    for( int j = part1; j < *capacity-1; j++ ){
            printf("mass %d",(*arr)[part1]);
            (*arr)[part1] = (*arr)[part1+1];
            part1++;
    }
    *capacity-=1;
    printf("capa %d",*capacity);
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

 int cmp(const void *b, const void *a) {
     return *(int*)a - *(int*)b;
 }

void make_test(int capacity, int *fin, int **arr, int **arr1);
int samles(int a, int b);

int main()
{
	int variant,menu;
	int fin = 1,capacity = 1;
	int *arr = (int *)malloc(capacity * sizeof(int));
	int *arr1 = (int *)malloc(capacity * sizeof(int));

	do
	{
		print_menu1();

		variant = get_variant(6);
		switch (variant)
		{
		case 1:
			add_arr(&capacity,&arr);
			break;

		case 2:
			add_num(capacity, &arr);
			break;

		case 3:
			del_num(&capacity, &arr);
			break;

		case 4:
		    print_menu2();
		    menu = get_variant(2);
		    switch(menu){
            case 1:
                print_arr(capacity, &arr);
                break;

            case 2:
                print_arr(fin, &arr1);
                break;
		    }
			break;

        case 5:
			make_test(capacity, &fin, &arr, &arr1);
			break;
		}

		if (variant != 6)
			system("pause");
	} while (variant != 6);
	return 0;
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
                *fin=k;
                k++;
            }
            }
        }
    }

int samles(int a, int b){
    int temp,clone,flag=1,num1,num2;
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

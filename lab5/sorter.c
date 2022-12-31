#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void binsertion_binary(int **cars, int size){
     int i, j, m, left, right, x;
    for (i=1; i < size; i++){
        x=(*cars)[i];
        left=0;
        right=i-1;
        while (left <= right){//пока есть что просматривать{
            m = (left+right)/2;//делим интервал поиска пополам
            if (x <(*cars)[m])//если вставляемое значение больше текущего
                right = m-1;//искать надо в правой части
            else
                left = m+1;//а если нет, то будем искать в левой
    }
            for (j=i-1; j < left; j++)
                       (*cars)[j++]=(*cars)[j];//sdvig
            printf("for%d\n",j);
            (*cars)[left]=x;
}
    }

void sort_bin(int **data, int size){
        int i;
        for (i = 0; i < size; i++) {
                int pos = -1;
                int start = 0;
                int end = i - 1;
                int numToInsert = (*data)[i];
                // Находим место вставки с помощью бинарного поиска
                while (start <= end && !(pos != -1)) {
                        int middle = (start + end) / 2;
                        if (numToInsert > (*data)[middle]) {
                                start = middle + 1;
                        } else if (numToInsert < (*data)[middle]) {
                                end = middle - 1;
                        } else {
                                pos = middle;
                        }
                }
                if(end < 0){
                        // определяем позицию в случае если элемент меньше всех отсортированных
                        pos = 0;
                } else if(start >= i){
                        // определяем позицию в случае если элемент больше всех отсортированных
                        pos = i;
                }
                if (pos < i) {
                        // сдвигаем элементы вправо на одну позицию
                        int j;
                        for (j = i; j > pos; j--) {
                                (*data)[j] = (*data)[j - 1];
                        }
                        (*data)[pos] = numToInsert;
                }
        }
}

void ShakerSort(int **Mas, int N)
{
    int tmp, Start =1, Left, Right, i;
    Left=Start;
    Right=N-1;
    while (Left<=Right){
        for (i=Right; i>=Left; i--){
            if ((*Mas)[i-1]>(*Mas)[i]){
                tmp = (*Mas)[i];
                (*Mas)[i]=(*Mas)[i-1];
                (*Mas)[i-1]=tmp;
            }
        }
                Left++;
        for (i=Left; i<=Right; i++){
            if ((*Mas)[i-1]>(*Mas)[i]){
                tmp = (*Mas)[i];
                (*Mas)[i]=(*Mas)[i-1];
                (*Mas)[i-1]=tmp;
            }
        }
                Right--;
    }
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

int main(){
    int capacity = 1;
    int *arr = (int *)malloc(capacity * sizeof(int));
    switch (1 )
		{
		case 1:
			add_arr(&capacity,&arr);
			break;
		}
    ShakerSort(&arr,capacity);
        printf("\n Final:");
    for (int j = 0; j < capacity; j++)
	{
		printf("[%d] ",(arr)[j]);
	}

}

#include<stdio.h>

int main(){
    int a , b ; //кол-во строк и столбцов
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);
    int arr[a][b];
    for (int i = 0; i < a; i++){ //проход строка
        for (int j = 0; j < b; j++){ //проход столбец
            printf("[%d][%d]:",i,j);
            scanf("%d", &arr[i][j]);
            }
    }
    for (int i = 0; i < a; i++){ //проход строк
        printf("\n");
        for (int j = 0; j < b; j++) //проход столбов
            printf("%d ", arr[i][j]);

    }
}

#include<stdio.h.>
void bit(int arr[], int b){
        //ввод в мссив элементов //проход строка
        int i=1;
        for (int j = 0; j < b; j++){ //проход столбец
            printf("[%d][%d]:",i,j);
             scanf("%d", &arr[j]);
            }
}
int main(){
        int a , b, c, d, flag ; //кол-во строк и столбцов
    printf("Vedite chislo ctrok:");
    scanf("%d",&a);
    printf("Vedite chislo stolbcov:");
    scanf("%d",&b);

    int arr[b];
    bit(arr,b);

        printf("\n ");
        for (int j = 0; j < b; j++){ //проход столбов
            printf("%d ", arr[j]);
            }
    return 0;
}
